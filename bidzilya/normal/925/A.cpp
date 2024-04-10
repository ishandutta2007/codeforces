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

const int INF = 1e9;

int n, m, cl, ce, v;
vector<int> ls;
vector<int> es;

int q;
vector<int> sx;
vector<int> sy;
vector<int> ex;
vector<int> ey;

int Ceil(int n, int d) {
    return n / d + (n % d != 0);
}

int UseLadder(int sx, int sy, int ex, int ey, int pos) {
    int result = abs(pos - sy);
    result += abs(sx - ex);
    result += abs(pos - ey);
    return result;
}

int UseElevator(int sx, int sy, int ex, int ey, int pos) {
    int result = abs(pos - sy);
    result += Ceil(abs(sx - ex), v);
    result += abs(pos - ey);
    return result;
}

int GetDistance(int sx, int sy, int ex, int ey) {
    int result = INF;
    if (sx == ex) {
        result = min(result, abs(sy - ey));
    }
    {
        auto litr = lower_bound(ls.begin(), ls.end(), sy);
        if (litr != ls.end()) {
            result = min(result, UseLadder(sx, sy, ex, ey, *litr));
        }
        if (litr != ls.begin()) {
            --litr;
            result = min(result, UseLadder(sx, sy, ex, ey, *litr));
        }
    }
    {
        auto eitr = lower_bound(es.begin(), es.end(), sy);
        if (eitr != es.end()) {
            result = min(result, UseElevator(sx, sy, ex, ey, *eitr));
        }
        if (eitr != es.begin()) {
            --eitr;
            result = min(result, UseElevator(sx, sy, ex, ey, *eitr));
        }
    }
    return result;
}

void Solve() {
    for (int i = 0; i < q; ++i) {
        cout << GetDistance(sx[i], sy[i], ex[i], ey[i]) << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> n >> m >> cl >> ce >> v)) {
        return false;
    }
    ls.resize(cl);
    es.resize(ce);
    for (int i = 0; i < cl; ++i) {
        cin >> ls[i];
        --ls[i];
    }
    for (int i = 0; i < ce; ++i) {
        cin >> es[i];
        --es[i];
    }
    cin >> q;
    sx.resize(q);
    sy.resize(q);
    ex.resize(q);
    ey.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
        --sx[i];
        --sy[i];
        --ex[i];
        --ey[i];
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