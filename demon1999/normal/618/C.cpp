#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define fi first
#define se second
#define l1 l11
#define l2 l22
typedef long long ll;
typedef long double ld;
typedef std::pair<ll, ll> pii;
using namespace std;
const ll mod = 1000000007;
int n;
vector<pair<pii, int> > a;

bool ok(pii a, pii b, pii c) {
    ll A = b.se - a.se, B = a.fi - b.fi, C = - A * a.fi - B * a.se;
    if (A * c.fi + B * c.se + C == 0) re false;
    re true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("point.in", "r", stdin);
    cin >> n;
    a.resize(n);
    forn (i, n) {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i + 1;
    }
    sort(a.begin(), a.end());
    forn (i, n - 2) {
        if (ok(a[i].fi, a[i + 1].fi, a[i + 2].fi)) {
            cout << a[i].se << " " << a[i + 1].se << " " << a[i + 2].se << "\n";
            re 0;
        }
    }
    return 0;
}