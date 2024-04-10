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
ll n, q, l, r, sum;
vector<ll> a, b, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("point.in", "r", stdin);
    cin >> n >> q;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
    }
    b.resize(n - 1);
    forn (i, n - 1) {
        b[i] = abs(a[i] - a[i + 1]);
    }
    forn (i, q) {
        a.resize(0);
        p.resize(0);
        sum = 0;
        cin >> l >> r;
        l--;
        r--;
        a.push_back(1000000000);
        p.push_back(l - 1);
        ll ans = 0;
        for (int i = l; i < r; i++) {
            while (a[sz(a) - 1] < b[i]) {
                sum -= a[sz(a) - 1] * (p[sz(a) - 1] - p[sz(a) - 2]);
                a.pop_back();
                p.pop_back();
            }
            a.push_back(b[i]);
            p.push_back(i);
            sum += a[sz(a) - 1] * (p[sz(a) - 1] - p[sz(a) - 2]);
            ans += sum;
        }
        cout << ans << "\n";
    }
    return 0;
}