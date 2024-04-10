#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>

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
    if (k == 1) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
int n , k;
priority_queue<int,vector<int>,greater<int>> q;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
      int ans = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        string com ;
        cin >> com ;
        if(com[0] =='a')
        {
            int k;
            cin >> k;
            if(k)
            {
              v.push_back(k);
              q.push(k);
            }
        }
        else
        {
         if(v.size() == 0 || v.back() == q.top())
         {
             if(v.size() != 0) v.pop_back();
         }
            else
         {
             v.clear();
             ans = ans + 1;
         }
            q.pop();
        }
    }
    cout << ans << "\n";
    return 0;
 }