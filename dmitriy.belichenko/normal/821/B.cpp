#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

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

long long m  , b;
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
long long calc(long long x ,long long y)
{
    long long res = 0;
    for(long long i = 0; i < y + 1; i++)
    {
        res = res + i * (x + 1);
        res+= (x * x + x)/2;
    }
    return res;
}
static bool pri(long long k)
{
    if (k == 1) return false;
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
    //cin >> n;
    string cmd;
  /*
    vector<int> v;
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> cmd;
        if(cmd[0] == 'a')
        {
            cin >> k;
            v.push_back(k);
        }
        else
        {
            int p = v.size();
            if(cur != v[p - 1])
            {
                sort(v.rbegin(), v.rend());
                cnt++;
            }
            cur++;
            v.pop_back();
            
        }
    }
    cout << cnt << "\n";
    return 0; */
    cin >> m >> b;
    long  long ans = 0;
    for(long long i = 0; i < b + 1; i++)
    {
        long long x = m * 1LL * abs(i - b);
        ans = max(ans, calc(x , i));
    }
    cout << ans << "\n";
}