/**********
*         *
*  HELLO  *
*         *
**********/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stdio.h>
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

const ll mx = 500000;
const ll e9 = 1000000000;
ll n, a[mx];
vector<ll> g[mx];

bool check(ll x) {
    ll k0 = 0, k1 = 0;
    for (ll i = 0; i < n; ++i) {
        if (a[i] == x)
            k0++;
        if (a[i] == (x-1))
            k1++;
        if (a[i] > x)
            return 0;
    }
    if (k0 > 0) {
        if (k0 > 1)
            return 0;
        ll v = -1;
        for (ll i = 0; i < n; ++i) {
            if (a[i] == x) {
                v = i;
                break;
            }
        }
        ll num = 0;
        for (auto j: g[v]) {
            if (a[j] == (x-1))
                num++;
        }
        if (num >= k1)
            return 1;
        else
            return 0;
    }
    for (ll i = 0; i < n; ++i) {
        ll num = 0;
        for (auto j: g[i]) {
            if (a[j] == (x-1))
                num++;
        }
        if (a[i] == (x-1))
            num++;
        if (num >= k1)
            return 1;
    }
    return 0;
}

ll binsearch(ll l, ll r) {
    if (l == r) return l;
    if ((r-l) == 1) {
        if (check(l))
            return l;
        else
            return r;
    }
    ll m = (l+r)/2;
    if (check(m))
        return binsearch(l, m);
    else
        return binsearch(m+1, r);
}

int main()
{
    ll u, v;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < (n-1); ++i) {
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }
    cout << binsearch(-2*e9-1, 2*e9+2);
    return 0;
}