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
long long inf = LONG_LONG_MAX;
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
map<int, vector<int> > p;
map<int, int> m;
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
vector < vector<int> > g;
vector<bool> used;
vector<int> res;
vector<int> last;
vector<int> d;
map<int, int> cnt;
vector<int> ans;
map<int, map<int, int> > pt ;
void dfs(int v)
{
    used[v] = true;
for (auto u : g[v])
    {
if (!used[u])
        {
            last[u] = v;
dfs(u);
        }
    }
    res.push_back(v);
}
int k  , x;
void calcans(int n)
{
for (int i = 0; i < n; i++)
    {
int v = res[i];
if (d[v] != 0 )
        {
int del = 1 - d[last[v]];
            d[last[v]] = del;
            ans.pb(pt[v][last[v]] + 1);
        }
    }
}
int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
int n, m;
    cin >> n >> m;
    d.resize(n);
for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        cnt[d[i]]++;
    }
    g.resize(n);
for (int i = 0; i < m; i++)
    {
int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[v].push_back(u);
        g[u].push_back(v);
        pt[u][v] = i;
        pt[v][u] = pt[u][v];
    }
    k = cnt[-1];
    x = cnt[1] % 2;
if (!k && x)
    {
         cout << -1 << "\n";
return 0;
    }
if (x)
    {
bool flag = 0;
for (int i = 0; i < n; i++)
        {
if (d[i] == -1)
            {
if(!flag)
                {
                    d[i] = max(1 , d[i]);
                    flag = 1;
                }
else d[i] = max(0, d[i]);
            }
        }
    }
else
    {
for (int i = 0; i < n; i++)
if (d[i] == -1) d[i] = max(d[i] , 0);
    }
     used.resize(n , 0);
     last.resize(n);
dfs(0);
calcans(n);
     cout << ans.size() << endl;
for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
     cout << "\n";
return 0;
}