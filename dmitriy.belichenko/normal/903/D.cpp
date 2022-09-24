#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long double
const ll MOD = 1e9 + 7;
const ll N = 1e5;
using namespace std;
map <ll, ll> a;
map <ll, ll> sm;
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll res = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x = 0;
        cin >> x;
        ll num = i , o = res;
        for(ll j = x - 1; j <= x + 1; j++)
        {
            num -= a[j];
            res -= sm[j];
        }
        ans -= 1LL * res - num * x;
        res = o + x;
        sm[x] += x;
        a[x]++;
    }
    cout << setprecision(25) << ans << "\n";
    return 0;
}