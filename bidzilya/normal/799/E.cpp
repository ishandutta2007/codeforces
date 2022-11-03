#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void ClearPopBased(T& t) {
    while (!t.empty()) {
        t.pop();
    }
}

const long long INF = 1e18;

class TCont {
public:
    void Add(int value) {
        AddImpl(value);
        Adjust();
    }

    void SetLimit(int limit) {
        Limit = limit;
        Adjust();
    }

    int GetSize() {
        return Result.size();
    }

    long long GetSum() {
        return Sum;
    }

    void Clear() {
        ClearPopBased(Result);
        ClearPopBased(Postponed);
        Limit = 0;
        Sum = 0;
    }

private:
    priority_queue<int> Result;
    priority_queue<int, vector<int>, greater<int>> Postponed;
    int Limit;
    long long Sum;

    void AddImpl(int value) {
        Result.push(value);
        Sum += value;
    }

    void RemoveImpl() {
        int value = Result.top();
        Result.pop();
        Sum -= value;
        Postponed.push(value);
    }

    void Adjust() {
        while (Limit > (int) Result.size() && !Postponed.empty()) {
            AddImpl(Postponed.top());
            Postponed.pop();
        }
        while (Limit < (int) Result.size()) {
            RemoveImpl();
        }
    }
};

int n, m, k;
vector<int> c;

vector<int> x, y;

vector<int> ct[4];
vector<long long> sct[4];
vector<int> tp;

TCont cont;

void BuildSum(const vector<int>& a, vector<long long>& s) {
    s.resize(a.size() + 1);
    s[0] = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        s[i + 1] = s[i] + a[i];
    }
}

void Solve() {
    if (k > m) {
        cout << -1 << endl;
        return;
    }
    tp.assign(n, 0);
    for (int xx : x) {
        tp[xx] |= (1 << 0);
    }
    for (int yy : y) {
        tp[yy] |= (1 << 1);
    }
    for (int i = 0; i < (1 << 2); ++i) {
        ct[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        ct[tp[i]].push_back(c[i]);
    }
    for (int i = 0; i < (1 << 2); ++i) {
        sort(ct[i].begin(), ct[i].end());
        BuildSum(ct[i], sct[i]);
    }
    cont.Clear();
    for (int x : ct[0]) {
        cont.Add(x);
    }
    array<int, 4> ptrs;
    ptrs[1] = ct[1].size();
    ptrs[2] = ct[2].size();
    long long result = INF;
    for (int t = 0; t <= min(m, (int) ct[3].size()); ++t) {
        if (k - t > (int) min(ct[1].size(), ct[2].size())) {
            continue;
        }
        for (int i = 1; i <= 2; ++i) {
            while (ptrs[i] > 0 && ptrs[i] > k - t) {
                --ptrs[i];
                cont.Add(ct[i][ptrs[i]]);
            }
        }
        int fc = t + 2 * max(0, k - t);
        long long fs = sct[3][t] + (k - t >= 0 ? sct[1][k - t] + sct[2][k - t] : 0);
        const int need = m - fc;
        if (need < 0) {
            continue;
        }
        cont.SetLimit(need);
        if (cont.GetSize() == need) {
            result = min(result, fs + cont.GetSum());
        }
    }
    if (result == INF) {
        result = -1;
    }
    cout << result << endl;
}

void ReadArray(vector<int>& a) {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
}

bool Read() {
    if (!(cin >> n >> m >> k)) {
        return false;
    }
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    ReadArray(x);
    ReadArray(y);
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}