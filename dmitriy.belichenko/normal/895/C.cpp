
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
using namespace std;
using namespace std;
long long dp[(1<<19) + 1][2];
int divp[73];
int MOD = 1e9 + 7;
int id[73];
int stt[100005];
auto st = stt + 1;
long long sum(long long a , long long b)
{
    a += b;
    if(a >= MOD)
        return a - MOD;
    else return a;
}
long long mult( long long a , long long b)
{
    long long c = 1LL * a * b;
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int primes[] = {2,3,5,7,11,	13,	17,	19,	23,	29,	31,	37, 41,	43,	47,	53,	59,	61,	67};
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        divp[a[i]]++;
    }
    st[-1] = 1;
    st[0] = 1;
    for(int i = 1; i <= n + 1; i++)
    {
        st[i] = sum( st[i - 1] , st[i - 1]) ;
        //cout << st[i] << " ";
    }
    dp[0][0] = 1;
    
    for(int i = 1; i <= 70 ; i++)
    {
        int k = i;
        int mask = 0;
        for(int p = 0; p < 19; p++)
        {
            int cnt = 0;
            while(k % primes[p] == 0)
            {
                k /= primes[p];
                cnt++;
            }
            if(cnt % 2)
            mask += 1 << p;
        }
        id[i] = mask;
    }
    int cur = 1;
    for(int i = 1; i < 71; i++)
    {
        cur = 1 - i % 2;
      //  cout << divp[i] << "\n";
        for(int j = 0; j < (1 << 19); j++)
        {
            dp[j][1 - cur] = 0;
        }
        int to = 1 - cur;
        for(int j = 0; j < (1<<19) ; j++)
        {
            int mask = j ^ id[i];
            if(divp[i] > 0) dp[mask][to] = sum(dp[mask][to],
                               mult (dp[j][cur],
                                st[divp[i] - 1]));
            dp[j][to] = sum(dp[j][to],
                                     mult(dp[j][cur]
                                 ,st[divp[i] - 1]));
    
        }
    }
    
    cout << dp[0][0] - 1;
}