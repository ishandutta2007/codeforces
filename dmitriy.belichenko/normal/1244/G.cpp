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
const int N = 5e6 + 1488;
ll a[N];
ll ans = 0;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n , k;
    cin >> n >> k;
    ll sm = n * (n + 1) / 2;
    if(k < sm) return cout << -1 << "\n", 0;
    iota(a + 1, a + n + 1, 1);
    int l = 0, r = n;
    while(r - l > 0)
    {
        l++;
        // cout << l << "\n";
        while(r > l && sm - l + r > k) l++;
        if(r <= l) break;
        sm += r - l;
        swap(a[l], a[r--]);
    }
    cout << sm << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << i + 1 << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << a[i + 1] << " ";
    }
    return 0;
}