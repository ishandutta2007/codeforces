#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 26;
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
ll mult(ll a, ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
int find_mx(int n)
{
    int mx = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            mx = max(i , mx);
            while(n % i == 0) n/= i;
        }
    }
    if(n > 1) mx = max(mx , n);
    return mx;
}
vector<int> dv;
ll v[N] , t[N] , rv[N];
ll pref[N];
ll ans[N];
ll cnt[N];
ll a[N];
ll seg = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    pref[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + t[i - 1];
    }
    for(int i = 0; i < n; i++)
    {
        int l = -1 , r = n , mid;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if(pref[mid  + 1] - pref[i] < v[i])
            {
                l = mid;
            }
            else r = mid;
        }
        
        rv[i] = pref[r] - pref[i];
  //      cout << v[i] << " " << rv[i] << "\n";
        ans[r] += v[i] - rv[i];
        cnt[i]++;
        cnt[r]--;
       // cout << i << " " << r << "\n";
    }
    for(int i = 0; i < n; i++)
    {
        seg += cnt[i];
        a[i] = seg;
    }
  //  cout << "\n";
    for(int i = 0; i < n; i++)
    {
        ans[i] += a[i] * t[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}