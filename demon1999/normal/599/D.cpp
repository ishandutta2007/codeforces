#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bitset>
//#include "horses.h"
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

typedef long double ld;
const ll ma = 131072 * 4, mod = 1000000007;
const ld eps = 1e-10;
ll n, m, k;
vector<int> q, p, b;
vector<pair<ll, ll> > ans;
int main() {
    iostream::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    /*for (ll j = 1; ;j++)
        if (j * j + j * (j + 1) * (2 * j + 1) / 6 > 1000000000000000000LL) {
            cout << j; break;
        }*/
    for (ll i = 1; i <= 15000000; i++) {
        ll pp = i, kk = 1;
        if (i % 3 == 0) {
            pp /= 3;
            kk = 3;
        }
        ll k = (2 * n / pp + i * kk * (i - 1) - kk * (i - 1) * (2 * i - 1) / 3);
        if (2 * n % pp == 0 && k % (kk * i + kk) == 0 && k / (kk * i + kk) >= i) {
            ans.push_back(mp(i, k / (kk * i + kk)));
        }
        if (k / (i + 1) < i) break;
    }
    int k = 2 * sz(ans);
    if (ans[sz(ans) - 1].fi == ans[sz(ans) - 1].se) k--;
    cout << k << "\n";
    forn (i, sz(ans))
        cout << ans[i].fi << " " << ans[i].se << "\n";
    for (int i = sz(ans) - 1; i >= 0; i--)
        if (ans[i].se != ans[i].fi) cout << ans[i].se << " " << ans[i].fi << "\n";
    re 0;
}