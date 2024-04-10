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
int to_i(char c)
{
    return c - 'a';
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

//int gr[50][50][N];
int cnt[N] , ls1[N] , ls2[N] , d[N], a[N];
void Lis(int n , int m , bool flag)
{
    d[0] = -INF;
    for (int i = 1; i <= m + 1; i++)
    {
        d[i] = INF;
    }
    if(flag)
    for(int i = 1; i <= m; i++)
    {
        int j = upper_bound(d, d + m + 2, a[i]) - d;
        if (d[j - 1] <= a[i] && a[i] < d[j])
        {
            d[j] = a[i];
        }
        ls1[i] = lower_bound(d, d + m + 2, INF) - d - 1;
    }
    else
    {
        for(int i = m; i > 0; i--)
        {
            int j = upper_bound(d, d + m + 2, a[i]) - d;
            if (d[j - 1] <= a[i] && a[i] < d[j])
            {
                d[j] = a[i];
            }
            ls2[i] = lower_bound(d, d + m + 2, INF) - d - 1;
        }
    }
}

int seg = 0 , ans = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int l , r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    for(int i = 1; i <= m; i++)
    {
        
        seg += cnt[i];
        a[i] = seg;
       // cout << a[i] << " ";
    }
    Lis(n, m, 1);
    Lis(n, m, 0);
    for(int i = 1; i <= m; i++)
    {
        ans = max(ans , ls1[i] + ls2[i]);
    }
    cout << ans - 1<< "\n";
    return 0;
}