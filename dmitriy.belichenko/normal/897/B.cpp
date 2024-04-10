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
int MOD = 1e9 + 7;
using namespace std;
map<int, double > bi;
long long sum(long long a, long long b)
{
    a += b;
    return a % MOD;
    if (a >= MOD)
        return a - MOD;
    else return a ;
}
long long mult(long long a, long long b)
{
    long long c = 1LL * a * b;
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
long long tolong(const string &s)
{
    long long res = 0;
    for(int i  = 0; i < s.size(); i++)
    {
        res += (s[i] - '0') * pow(10 , s.size() - i - 1);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , k;
    cin >> k >> n;
    int cnt = 1;
    int len = 0;
    vector<string> s;
    while(cnt <= k)
    {
        long long x = pow(10 , len);
        string v = to_string(x);
        string u = v;
        reverse(v.begin(), v.end());
        //cout << len << "\n";
        s.push_back((u + v));
        for(int i = 0; x < pow(10 , len+1) - 1 && cnt <= k; i++)
        {
            x+= 1;
            string y = to_string(x);
            string yy = y;
            reverse(y.begin(), y.end());
            s.push_back((yy + y));
            cnt++;
        }
        len++;
    }
    long long ans = 0;
    MOD = n;
    for(int i = 0; i < k; i++)
    {
      //   cout << s[i] << "\n";
        ans = sum(ans , tolong(s[i]));
    }
    cout << ans << "\n";
}