#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 1e6;

int n, k;
vector<int> perm;
vector<int> counts;

bool CanKnap(const vector<pair<int, int>>& knap, const int k) {
    static bitset<MAX_N> buffer;
    buffer[0] = 1;
    for (const auto& p : knap) {
        int pw = p.second;
        while (pw > 1) {
            int d = (pw >> 1);
            pw -= d;
            buffer |= (buffer << (p.first * d));
        }
        buffer |= (buffer << p.first);
    }
    return buffer[k];
}

int GetMinResult() {
    vector<pair<int, int>> knap;
    for (int i = 1; i <= n; ++i) {
        if (counts[i] > 0) {
            knap.push_back(make_pair(i, counts[i]));
        }
    }
    if (CanKnap(knap, k)) {
        return k;
    } else {
        return k + 1;
    }
}

int GetMaxResult() {
    int result = 0;
    int ck = k;
    for (int i = 1; i <= n; ++i) {
        int cc = counts[i];
        while (ck > 0 && cc > 0) {
            int d = min(ck, i >> 1);
            --cc;
            ck -= d;
            result += 2 * d;
        }
    }
    int oddCount = 0;
    for (int i = 1; i <= n; ++i) {
        oddCount += counts[i] * (i & 1);
    }
    {
        int d = min(oddCount, ck);
        result += d;
    }
    return result;
}

void Solve() {
    counts.assign(n + 1, 0);
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            continue;
        }
        int x = i;
        int len = 0;
        while (!used[x]) {
            ++len;
            used[x] = true;
            x = perm[x];
        }
        ++counts[len];
    }
    cout << GetMinResult() << " ";
    cout << GetMaxResult() << endl;
}

bool Read() {
    if (!(cin >> n >> k)) {
        return false;
    }
    perm.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
        --perm[i];
    }
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