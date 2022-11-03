#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

int Ceil(int n, int d) {
    return n / d + (n % d != 0);
}

struct TServer {
    int Index;
    int Capacity;

    int Get(int need) const {
        return Ceil(need, Capacity);
    }
};

int n, x1, x2;
vector<TServer> a;

struct TResult {
    std::pair<int, int> First;
    std::pair<int, int> Second;
};

bool Solve(TResult& result, int x1, int x2) {
    vector<std::pair<int, int>> can(n);
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            can[i].first = -1;
        } else {
            can[i] = can[i + 1];
        }
        int k = a[i].Get(x2);
        if (i + k <= n) {
            can[i] = {i, i + k};
        }
    }
    for (int i = 0; i < n; ++i) {
        int k = a[i].Get(x1);
        if (i + k < n && can[i + k].first != -1) {
            result.First = {i, i + k};
            result.Second = can[i + k];
            return true;
        }
    }
    return false;
}

void Solve() {
    sort(a.begin(), a.end(), [] (const TServer& lhs, const TServer& rhs) {
        return lhs.Capacity < rhs.Capacity;
    });

    bool ok = false;

    TResult result;
    if (!Solve(result, x1, x2)) {
        if (Solve(result, x2, x1)) {
            swap(result.First, result.Second);
            ok = true;
        }
    } else {
        ok = true;
    }

    if (!ok) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << result.First.second - result.First.first
            << " " << result.Second.second - result.Second.first << endl;
        for (int i = result.First.first; i < result.First.second; ++i) {
            cout << a[i].Index + 1 << " ";
        }
        cout << endl;
        for (int i = result.Second.first; i < result.Second.second; ++i) {
            cout << a[i].Index + 1 << " ";
        }
        cout << endl;
    }
}

bool Read() {
    if (!(cin >> n >> x1 >> x2)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        a[i].Index = i;
        cin >> a[i].Capacity;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}