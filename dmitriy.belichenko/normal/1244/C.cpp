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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    for(ll i = 0; i < w + 1; i++)
    {
        ll def = p - i * d;
        if(def % w == 0)
        {
            if(def >= 0)
            {
                if(n - i - def / w >= 0)
                {
                    cout << def / w << " " << i << " " << n - i - def / w << "\n";
                    return 0;
                }
            }
        }
    }
    cout << -1 << "\n";
    
   
}