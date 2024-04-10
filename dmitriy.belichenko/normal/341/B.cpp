#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
long long inf = 1LL << 62;
static long parseans(long j, long l)
{
    string k = "";
    long ps = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        ps *= 10;
        ps += k[i] - '0';
    }
    return ps;
}

int cur = 1;
int cnt = 0;
static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    } else
    {
        return gcd(b, a % b);
    }
}

static bool pri(long long k)
{
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
int n , k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int a[1000005];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n);
    dp[0] = -1000005;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1000005;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = int (upper_bound (dp.begin(), dp.end(), a[i]) - dp.begin());
        if (dp[j-1] < a[i] && a[i] < dp[j])
        {
            dp[j] = a[i];
            // ans++;
        }
    }
    for(int i = 0; i <= n; i++)
    {
        if( abs(dp[i]) != 1000005) ans++;
    }
    
    cout << ans << "\n";
}