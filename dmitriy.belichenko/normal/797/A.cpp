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
    }
    else
    {
        return gcd(b, a % b);
    }
}
map<int, int> m;
map<int, set<int> > m1;
vector<int>fact;
static bool pri(long long k)
{
    if (k == 1LL) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(20);
    int n , k;
    cin >> n >> k;
    int ans = n;
    if(k == 1)
    {
        cout << n ;
        return 0;
    }
    for(int i = 2; i * i <= n ; i++)
    {
        while(n % i == 0)
        {
            if(pri(i))
            fact.push_back(i);
            if((pri(n/i)) && n/i != i) fact.push_back(n/i);
            n/= i;
        }
    }
   // for(int i = 0; i < fact.size(); i++) cout << fact[i] << " ";
    cout << "\n";
    if(fact.size() < k){ cout << -1; return 0;}
    for(int i = 0; i < k - 1; i++){ cout << fact[i] << " " , ans /= fact[i]; };
    cout << ans;
   return 0;
    
}