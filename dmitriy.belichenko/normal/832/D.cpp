#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
long long inf = 1 << 62;
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
ll MOD =  1000000007;
int n, l;
vector < vector<int> > g;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
int dp[100005];
void dfs (int v, int p  , int dst )
{
    dp[v] = dst;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (to != p)
            dfs (to, v ,dst + 1);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b)
{
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int calcdist (int a, int b)
{
    int x=lca(a, b);
    return dp[a]+dp[b]-2*dp[x]+1;
}

int calcans (int f, int s, int t)
{
    return (calcdist(s, f)+ calcdist(f, t)- calcdist(s, t)+1)/2;
}

int main()
{
    int n , q;
    cin >> n >> q;
    g.resize(n + 1);
  
    for(int i =  1;  i < n; i++)
    {
        int k;
        cin >> k;
        k--;
        g[i].pb(k);
        g[k].pb(i);
    }
    /*for(int i = 0; i < n-1; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    } */
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i=0; i<n; ++i)  up[i].resize (l+1);
    dfs (0 , 0 , 1);
    dp[0] = 1;
    //dfsrev(0);
    for(int i = 0; i < q; i++)
    {
        int a, b , c;
        cin >> a >> b >> c;
        a--; b--;c--;
        int ans = max(ans, calcans(a , b , c));
        ans = max(ans , calcans(b , c , a));
        ans = max(ans , calcans(c , a , b));
        cout << ans << "\n";
    }
}