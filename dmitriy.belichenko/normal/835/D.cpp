#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
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

static long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    else
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


double binpow (double a, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return binpow (a, n-1) * a;
    else {
        int b = binpow (a, n/2);
        return b * b;
    }
}
vector<int> calcz (string s)
{
    int n = s.length();
    vector<int> z (n);
    int l = 0, r = 0;
    for (int i = 1 ; i<n; i++)
    {
        if (i <= r)
        {
            z[i] = min (r - i+ 1, z[i - l]);
        }
        while (i + z[i] < n && s[ z[i] ] == s[i + z[i] ]) z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
/*bool check(string s)
 {
 
 }*/
vector<int> calcpref(string s)
{
    vector<int> p(s.size() + 1);
    int n = s.length();
    p[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[p[i]] !=s[i-1]) p[i] = p[p[i]];
        if (s[p[i]] == s[i-1]) p[i]++;
    }
    return p;
}
int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie();
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int dp[5005][5000 + 1];
    vector<int> ans(5005);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <  n - i + 1; j++)
        {
            //cout << "daf";
            int r = i + j;
            if(i == 1)
            {
                dp[j][r] = 1;
                // cout << "daf";
                continue;
            }
            else
            if(i == 2)
            {
                if(s[r - 1] == s[j])
                    dp[j][r] = 2;
                else dp[j][r] = 0;
                continue;
            }
            if((s[j] != s[r - 1] ||  !dp[j + 1][ r - 1]))
            {
                continue;
            }
            dp[j][r] = 1;
            int mid = ( j + r) / 2;
            if(i & 1)
            {
                if(dp[j][mid] && dp[mid + 1][r])
                {
                    dp[j][r] = dp[j][mid] + 1;
                    
                }
            }
            else
                if(dp[j][mid] && dp[mid][r])
                {
                    dp[j][r] = dp[j][mid] + 1;
                }
            
            
        }
    }
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 0; j < n - i + 1 ; j++)
        {
            ans[dp[j][j + i]]++;
            
        }
        // cout << "\n";
    }
    
    
    for(int i = n - 1; i>= 1; i--)
    {
        ans[i] += ans[i+1];
    }
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout <<"\n";
    return 0;
}