#pragma GCC optimize("Ofast", "no-stack-protector")
#pragma GCC target("sse4", "avx" , "popcnt" , "lzcnt" , "sse3" , "sse4.1"  , "sse4.2" , "sse2" , "tune=native")
#pragma "fastmath"
#pragma "unroll loops"
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <valarray>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int N = 1e5 + 5;
const int maxlog = 18;
ld eps = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
ll x[N] , y[N];

ll triangle_area_2 (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) 
{
    return (ll)((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}

ll dist[3000][3000];
int main()
{
    srand(239);
    int n ;
    ll s;
    cin >> n >> s;
    s *= 2;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for(int i = 0; i < n; i++)
        for(int j = 0 ; j < n; j++)
            dist[i][j] = x[i] * y[j] - x[j] * y[i];

    for(int u = 0; u < n; ++u)
    {
        for(int v = u + 1; v < n; ++v)
        {
            ll xp = dist[v][u];
            for(int k = v + 1; k < n; ++k)
            {
                ll pr = xp + dist[u][k] - dist[v][k];
                if(pr == s || -s == pr)
                {
                    cout << "Yes\n" <<  x[u] << " " << y[u] << "\n" <<  x[v] << " " << y[v] << "\n" <<  x[k] << " " << y[k] << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}