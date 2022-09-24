
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
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 2e6 + 5;
int MOD = 1e9 + 7;
template<class A, class B>

void sum(A &a , B b)
{
    a += b;
    if(a < 0) a += MOD;
    if(a >= MOD) a -= MOD;
}

ll mult( ll a , ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
bool isprime(int n)
{
    for(int i = 2; i * i <= n; i++ )
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int n , k;
ll ans = 0 , st = 0;
map<int , int> cnt;
int dp[1005];
int popcnt( int k)
{
    int cnt = 0;
    if(k == 1) return 1;
    while(k)
    {
        cnt++;
        k &= k - 1;
    }
    return cnt;
}
void precalc()
{
    for(int i = 1; i <= 1000; i++)
    {
        int j = i;
        int cnt = 0;
        while(j != 1)
        {
            cnt++;
            j = popcnt(j);
        }
        dp[i] = cnt;
    }
}
int c[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s ;
    cin >> s >> k;
    precalc();
    dp[1] = 0;
    int ans = 0;
    n = s.size();
    int cnt2 = 0;
    c[0][0] = 1;
    if(k == 0)
    {
        cout << 1 << "\n";
        return 0;
    }
    if(s == "1")
    {
        cout << (k == 0) << "\n";
        return 0;
    }
    if(k == 1)
    {
        cout << n - 1 << "\n";
        return 0;
    }
    for(int i = 1; i <= 1000; i++)
    {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            sum(c[i][j] , c[i - 1][j]);
            sum(c[i][j] , c[i - 1][j - 1]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0') continue;
        int p = n - i - 1;
        for(int j = max(cnt2 , 1); j <= 1000; j++)
        {
            if(1 + dp[j] == k)
            {
             //   cout << j << "\n";
                sum(ans , c[p][j - cnt2]); // C(p , j - cnt2);
            }
        }
        cnt2++;
    }
    if(1 + dp[cnt2] == k)
    {
        sum(ans , 1);
    }
    cout << ans << "\n";
}