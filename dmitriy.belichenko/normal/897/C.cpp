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
unsigned long long dp[205];
string pref = "What are you doing while sending \"";
string mid = "\"? Are you busy? Will you send \"";
string suff = "\"?";
unsigned long long len(int x )
{
    if(x > 200) return (1LL << 60);
    if(dp[x] ) return dp[x];
    
    if(x == 0)
    {
        string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
        return s.size();
    }
    return dp[x] = pref.length() + mid.length() + suff.length() + 2 * len(x - 1);
}
char ind(int n , long long k)
{
    if(n == 0)
    {
        string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
        return s[k - 1];
    }
    if(k <= pref.size())
    {
       return pref[k - 1];
    }
    k -= pref.size();
    if(k <= len(n - 1))
    {
        return ind(n - 1 , k);
    }
    k -= len(n - 1);
    if(k <= mid.size())
    {
        return mid[k -1];
    }
    k -= mid.size();
    if(k <= len(n - 1))
    {
        return ind(n - 1 , k);
    }
    k -= len(n - 1);
    return suff[k - 1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
   // q = 500;
  //  string t = "What are you doing while sending \"What are you doing at the end of the world? Are you busy? Will you save us?\"? Are you busy? Will you send \"What are you doing at the end of the world? Are you busy? Will you save us?\"?";
  //  cout << t.size() << " ";
   
    while(q--)
    {
        long long n , k;
        cin >> n >> k;
        if(len(n) < k)
        {
            cout << '.';
        }
        else
        {
            cout <<  ind(n , k);
        }
    }
}