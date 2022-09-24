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
const int N = 1e6 + 7;
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
int pr[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> n;
    k = n;
    int mx = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            mx = max(i , mx);
            while(n % i == 0) n/= i;
        }
    }
    mx = max(mx , n);
  //  cout << mx << "\n";
    for(int i = k - mx + 1; i <= k ; i++ )
    {
        pr[i] = find_mx(i);
      //  cout << pr[i] << " ";
    }
    int x = 1e9;
    for(int i = k - mx + 1; i <= k; i++ )
    {
        if(pr[i] != i)
        x = min(x , i - pr[i] + 1);
    }
    cout << x << "\n";
    return 0;
}