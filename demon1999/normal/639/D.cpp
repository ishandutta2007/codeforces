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
using namespace std;
const ll mod = 1000000007;
ll n, k, b, c, ans = -1, sum, pay, fc;
vector<ll> a, bb;
multiset<ll> pp;

ll cc(ll a, ll i) {
    ll k = i - a % 5;
    if (k < 0) k += 5;
    re k * c;
}

ll f(ll a, ll i) {
    ll b = a - a % 5 + i;
    if (b < a) b += 5;
    re b;
}

int main(){
    iostream::sync_with_stdio(0), cin.tie(0);
    //assert(freopen("point.in", "r", stdin));
    //freopen("point.out", "w", stdout);
    cin >> n >> k >> b >> c;
    a.resize(n);
    b = min(b, 5 * c);
    forn (i, n) {
        cin >> a[i];
        a[i] += (1000LL * 1000LL * 1000LL);
    }
    sort(a.begin(), a.end());
    bb = a;
    forn (i, 5) {
        pp.clear();
        sum = 0;
        forn (j, k) {
            fc = cc(a[j], i);
            a[j] = f(a[j], i);
            //cout << a[j] << " " << fc << endl;
            pp.insert(fc - ((a[j] - a[0]) / 5LL) * b);
            sum += fc - ((a[j] - a[0]) / 5LL) * b;
        }
        pay = (a[k - 1] - a[0]) / 5LL;
        if (ans == -1 || ans > pay * b * k + sum)
            ans = pay * b  * k + sum;
        for (int j = k; j < n; j++) {
            fc = cc(a[j], i);
            a[j] = f(a[j], i);
            //cout << a[j] << " " << fc << endl;
            pp.insert(fc - ((a[j] - a[0]) / 5LL) * b);
            sum += fc - ((a[j] - a[0]) / 5LL) * b;
            sum -= *pp.rbegin();
            pp.erase(pp.find(*pp.rbegin()));
            pay = (a[j] - a[0]) / 5LL;
            if (ans == -1 || ans > ((a[j] - a[0]) / 5LL) * b * k + sum) {
                ans = pay * b  * k + sum;
            }
        }
        //cout << endl;
        a = bb;
    }
    cout << ans;
    re 0;
}