#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bitset>
//#include "grader.h"
#define forn(i,n) for(int i=0;i<n;i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ---
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef long long ll;

typedef long double ld;
const ll ma = 131072;
ll n, k, a, ans, tree[2 * ma];
vector<pair<int, int> > w, x, y;

bool cmp(pair<int, int> x, pair<int, int> y) {
    re x.se - x.fi < y.se - y.fi || (x.se - x.fi == y.se - y.fi && x.se < y.se);
}

ll maxl(int l, int r) {
    if (l > r) re -1;
    if (l % 2 == 1)
        re max(tree[l], maxl(l + 1, r));
    if (r % 2 == 0)
        re max(tree[r], maxl(l, r - 1));
    re maxl(l / 2, r / 2);
}
int main() {
    iostream::sync_with_stdio(0);
    //ifstream cin("input.txt");
    cin >> n;
    x.resize(n); w.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].fi >> x[i].se;
    }
    for (int i = 0; i < 2 * ma; i++)
        tree[i] = -1;
    for (int i = 0; i < n; i++) {
        cin >> w[i].fi;
        w[i].se = i;
    }
    sort(w.begin(), w.end());
    sort(x.begin(), x.end(), cmp);
    y.resize(n);
    for (int i = 0; i < n; i++)
        if (x[i].se - x[i].fi != w[i].fi) {
            cout << "NO";
            re 0;
        }
        else {
            y[w[i].se] = x[i];
        }
    for (int i = 0; i < n; i++) {
        if (maxl(y[i].fi + ma,  2 * ma - 1) >= y[i].se) {
            cout << "NO";
            re 0;
        }
        tree[y[i].fi + ma] = max(tree[y[i].fi + ma], ll(y[i].se));
        ll k = y[i].fi + ma;
        while (k / 2) {
            k /= 2;
            tree[k] = max(tree[2 * k], tree[2 * k + 1]);
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << y[i].fi << " " << y[i].se << "\n";
    re 0;
}