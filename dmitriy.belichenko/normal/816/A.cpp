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
    long cur = 0;
    for (long long i = (long long) j; i <= l; ++i)
    {
        cur *= 10;
        cur += k[i] - '0';
    }
    return cur;
}


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

int n;
int a[105][105];
bool used[105];
int ans = 1;
bool t = 1;
int pre = 0;
void dfs(int u)
{
    used[u] = 1;
   
    for(int i = 0; i < n; i++)
        if(a[u][i] && i!= pre)
        {
            pre = u;
            if(!used[i])
            {
             dfs(i);
              ans++;
            }
             else t = 0;
        }
}

int main()
{
    int x, y;
    char c;
    cin >> x >> c >> y;
    int b = x * 60;
    b+= y;
    for (int t = b; t < 24 * 60; t++)
    {
        int m = t % 60;
        int h = t / 60;
        if ( m / 10 == h % 10)
        {
            if(m % 10 == h / 10)
            {
            cout << max(t - b , 0) << "\n";
            return 0;
            break;
            }
        }
    }
    cout << max(24 * 60 - b, 0) << "\n";
    
    return 0;
}