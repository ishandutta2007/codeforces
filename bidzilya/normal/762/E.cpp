#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TFenwickTree {
public:
    void Build(int n) {
        N = n;
        Values.assign(N, 0);
    }

    void Add(int pos, int value) {
        for (; pos < N; pos |= (pos + 1)) {
            Values[pos] += value;
        }
    }

    void Add(int l, int r, int value) {
        Add(l, value);
        if (r != N - 1) {
            Add(r + 1, -value);
        }
    }

    int Get(int pos) const {
        int result = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            result += Values[pos];
        }
        return result;
    }

private:
    int N;
    vector<int> Values;
};

int n, k;

struct TEvent {
    int Pos;
    int Radius;
    int Freq;

    int Left;
    int Right;
    int Index;

    void Read(int idx) {
        cin >> Pos >> Radius >> Freq;
        --Freq;
        Index = idx;
    }
};

vector<TEvent> a;

const int MAX_FREQ = 1e4;

vector<TEvent> b[MAX_FREQ];

int BuildLeftRights() {
    vector<int> points;
    points.reserve(3 * n);
    for (int i = 0; i < n; ++i) {
        points.push_back(a[i].Pos);
        points.push_back(a[i].Pos - a[i].Radius);
        points.push_back(a[i].Pos + a[i].Radius);
    }

    sort(points.begin(), points.end());
    points.resize(unique(points.begin(), points.end()) - points.begin());

    unordered_map<int, int> mp;
    for (int i = 0; i < (int) points.size(); ++i) {
        mp[points[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        a[i].Left = mp[a[i].Pos - a[i].Radius];
        a[i].Right = mp[a[i].Pos + a[i].Radius];
        a[i].Pos = mp[a[i].Pos];
    }

    return points.size();
}

void Solve() {
    int count = BuildLeftRights();

    TFenwickTree tree;
    tree.Build(count);

    for (int i = 0; i < MAX_FREQ; ++i) {
        b[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        b[a[i].Freq].push_back(a[i]);
    }

    long long result = 0;
    vector<TEvent> points;
    for (int i = 0; i < MAX_FREQ; ++i) {
        if (b[i].empty()) {
            continue;
        }

        points.clear();
        for (int j = max(0, i - k); j <= min(i + k, MAX_FREQ - 1); ++j) {
            for (const TEvent& e : b[j]) {
                points.push_back(e);
            }
        }

        sort(points.begin(), points.end(), [] (const TEvent& lhs, const TEvent& rhs) {
            return lhs.Radius < rhs.Radius || (lhs.Radius == rhs.Radius && lhs.Index < rhs.Index);
        });

        for (const TEvent& e : points) {
            if (e.Freq == i) {
                result += tree.Get(e.Pos);
            }

            tree.Add(e.Left, e.Right, 1);
        }

        for (const TEvent& e : points) {
            tree.Add(e.Left, e.Right, -1);
        }
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n >> k)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].Read(i);
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