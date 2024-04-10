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


int a[105][105];
bool used[105];
vector <pair <int, int> > v;
int n , k , q;
int ps[200005];
int ans[200005];
bool t = 1;
int pre = 0;
void dfs(int u)
{
    int ans =0;
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

int res(int l  ,int r)
{
    return (ans[r] - ans[l - 1]);
}
void precalc(int k)
{

    for (auto x : v)
    {
        ps[x.first] += x.second;
    }
    for (int i = 1; i < 200005; i++)
    {
        int u = (ps[i] >= k);
        ps[i] += ps[i - 1];
        u = (ps[i] >= k);
        ans[i] = u + ans[i - 1] ;
    }
}
int main()
{
    cin >> n >>  k >> q;
    v.resize(2 * n);
    
    for (int i = 0; i < n; i++)
    {
        int l , r;
        cin >> l >> r;
        v.push_back(make_pair(l, 1));
        v.push_back(make_pair(r+1, -1));
    }
     precalc(k);
    for (int i = 0; i < q; i++)
    {
        int l , r;
        cin >> l >> r;
        cout << res(l , r) << "\n";
    }
    return 0;
}