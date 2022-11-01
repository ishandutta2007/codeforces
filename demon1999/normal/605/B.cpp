#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <tuple>

#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
#define x1 x11
#define x2 x22
#define y1 y11
#define y2 y22
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1000000007, ma = 131072 * 2;
int k, p, m = 1, uk, n, pos[100000];
vector<pair<int, pair<int, int> > > a, b;
vector<int> c(100000, 0);
int main(){
    iostream::sync_with_stdio(0);
    //freopen("roofs.in", "r",  stdin);
    //freopen("travel.out", "w", stdout);
    cin >> n >> m;
    a.resize(m);
    forn (i, m) {
        cin >> a[i].fi >> a[i].se.fi;
        a[i].se.fi = 1 - a[i].se.fi;
        a[i].se.se = i;
    }
    sort(a.begin(), a.end());
    k = 0; p = 0;
    ll from = 2, to = 3;
    forn (i, m) {
        if (a[i].se.fi == 1) {
            if (to > k + 1) {
                cout << "-1";
                re 0;
            }
            b.push_back(mp(a[i].se.se, mp(from, to)));
            from++;
            if (from == to) {
                from = 2;
                to++;
            }
        }
        else {
            b.push_back(mp(a[i].se.se, mp(1, k + 2)));
            k++;
        }
    }
    sort(b.begin(), b.end());
    forn (i, m)
        cout << b[i].se.fi << " " << b[i].se.se << endl;
    return 0;
}