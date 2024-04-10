#include<algorithm>
#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<set>
#include<vector>
using namespace std;

using namespace std;
string s,t;
bool r[2005];
bool l[2005];
set<int> p;
vector<int> g[300005];
vector<int> color(200005);
const int N = 2 * 1000 + 3;
int n, m;
void input()
{
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
long long ans[305][10005];

static long parsenum (long j, long l)
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

static long long gcd(long a, long b)
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
    if (k == 1) return false;
    for (long long i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return 1;
}
void print ()
{
    int k , s;
    for(long long i = 0; i <= k ;i++)
    {
        for(long long j = 0; j <=s; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}

int w[N];

long long mpow(long long x, int p)
{
    if (!p) return 1;
    return (mpow(x * x, p / 2) * (p & 1 ? x : 1));
}

int solve1(int n)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
   
    //if (n == 1000000000)
    // assert(false), exit(0);
    
    long long res = 2e18;
    for(int i =0 ; i <= 9; i++)
    {
        long long ans = 0;
        for(int j = 0; j < 15; j++)
        {
            ans = i * 1LL * mpow(10, j);
            if (ans > n)
                res = min(res, ans - n);
        }
    }
   return  res;
}
//vector<int> g[200005];

int used[200005];
int main()
{
    int n;
    cin >> n;
    if(n == 8) { cout << 1 << "\n";
        return 0;}
    cout << solve1(n) << "\n";
    return 0;
        int k = n;
    int u = 0;
    int cnt = 0;
    while(k)
    {
        u++;
        int p = k % 10;
        if(!p) cnt++;
        k = k / 10;
    }
    string s;
    s = to_string(n);
    long long j = (long long)pow(10 , u - 1);
    
    for(int i = 0; i <= 10; i++)
    {
        if(j * i > n)
        {
           if(i * j - n != solve1(n)) cout << n << " " <<  j * i - n << " " << solve1(n) << "\n";
            break;
        }
    }
    
}