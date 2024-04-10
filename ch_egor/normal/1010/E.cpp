// WTF just for test

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

using namespace std;

const int MX = 100 * 1000 + 7;

void relax(pair<int, int>& p, int x) {
    p.first = min(p.first, x);
    p.second = max(p.second, x);
}

bool in(const pair<int, int>& p, int x) {
    return x >= p.first && x <= p.second;
}

vector<pair<int, int> > ad[MX];
vector<int> pt[MX];
vector<int> fen[4 * MX];
vector<int> t[4 * MX];

vector<tuple<int, pair<int, int>, pair<int, int> > > ask[MX];

int sm[MX];
int ans[MX];

void add(vector<int>& fen, int pos) {
    for (; pos < fen.size(); pos = (pos | (pos + 1))) {
        fen[pos]++;
    }
}

int sum(const vector<int>& fen, int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += fen[r];
    }
    return res;
}

int sum(const vector<int>& fen, int l, int r) {
    int res = sum(fen, r);
    if (l) {
        res -= sum(fen, l - 1);
    }
    return res;
}

void build(int v, int lx, int rx) {
    if (lx == rx) {
        t[v] = pt[lx];
        sort(t[v].begin(), t[v].end());
    } else {
        int mx = (lx + rx) >> 1;
        build(v + v, lx, mx);
        build(v + v + 1, mx + 1, rx);
        merge(t[v + v].begin(), t[v + v].end(), t[v + v + 1].begin(), t[v + v + 1].end(), back_inserter(t[v]));
    }
    fen[v].resize(t[v].size());
}

void add(int v, int lx, int rx, int x, int y) {
    int pos = lower_bound(t[v].begin(), t[v].end(), y) - t[v].begin();
    add(fen[v], pos);
    if (lx != rx) {
        int mx = (lx + rx) >> 1;
        if (x <= mx) {
            add(v + v, lx, mx, x, y);
        } else {
            add(v + v + 1, mx + 1, rx, x, y);
        }
    }
}

int sum(int v, int lx, int rx, pair<int, int> gx, pair<int, int> gy) {
    if (gx.first > rx || gx.second < lx) {
        return 0;
    } else if (gx.first <= lx && gx.second >= rx) {
        int lp = lower_bound(t[v].begin(), t[v].end(), gy.first) - t[v].begin();
        int rp = upper_bound(t[v].begin(), t[v].end(), gy.second) - t[v].begin() - 1;
        return sum(fen[v], lp, rp);
    } else {
        int mx = (lx + rx) >> 1;
        return sum(v + v, lx, mx, gx, gy) + sum(v + v + 1, mx + 1, rx, gx, gy);
    }
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int n, m, k;
    cin >> n >> m >> k;

    pair<int, int> bx(X, 1), by(Y, 1), bz(Z, 1);
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        relax(bx, x);
        relax(by, y);
        relax(bz, z);
    }
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pt[y].push_back(z);
        ad[x].emplace_back(y, z);
        if (in(bx, x) && in(by, y) && in(bz, z)) {
            cout << "INCORRECT\n";
            return 0;
        }
    }
    cout << "CORRECT\n";
    for (int i = 1; i <= k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (in(bx, x) && in(by, y) && in(bz, z)) {
            ans[i] = 1;
        } else {
            pair<int, int> nx = bx, ny = by, nz = bz;
            relax(nx, x);
            relax(ny, y);
            relax(nz, z);
            ask[nx.first - 1].emplace_back(-i, ny, nz);
            ask[nx.second].emplace_back(i, ny, nz);
        }
    }

    build(1, 1, Y);
    for (int i = 1; i <= X; i++) {
        for (const auto& pt : ad[i]) {
            add(1, 1, Y, pt.first, pt.second);
        }

        for (const auto& q : ask[i]) {
            int id = get<0>(q);
            int val = sum(1, 1, Y, get<1>(q), get<2>(q));
            if (id > 0) {
                sm[id] += val;
            } else {
                sm[-id] -= val;
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        if (ans[i] == 1) {
            cout << "OPEN\n";
        } else if (sm[i] > 0) {
            cout << "CLOSED\n";
        } else {
            cout << "UNKNOWN\n";
        }
    }
}