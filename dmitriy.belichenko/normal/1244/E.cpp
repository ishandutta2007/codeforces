// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma GCC optimize("O3")

#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <math.h>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

mt19937 rng(time(NULL));

#define all(x) x.begin(), x.end()
#define sz(a) (int)((a).size())
#define eb emplace_back
#define mp make_pair
#define X first
#define Y second
#define pb push_back

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using ld = long double;
using graph = vector<vi>;
using pii = pair<int, int>;

const int MOD = 998244353;
const int inf = 1e9 + 7;
const int N = 1e5 + 1488;
ll a[N];
ll ans = 0;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a , a + n );
    for(int i = 0;  i < n / 2; i++)
    {
        int rev = n - i - 1;
        ll x = a[i + 1] - a[i];
        x += a[rev] - a[rev - 1];
        x *= (i + 1);
        if(x < k + 1) k -= x;
        else return cout << a[rev] - a[i] - k / (i + 1) << "\n", 0;
    }
    cout << ans << "\n";
    return 0;
}