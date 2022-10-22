#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(2e18)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll t[MAXN];
ll h[MAXN];
ll ts[MAXN][2];
ll dp[MAXN][3];
bool mk[MAXN];
vector<int> g[MAXN];

void dfs(int u)
{
    mk[u]=1;
    vector<ll> sons;
    ll sum=0;
    for(auto v : g[u])
    {
        if(mk[v])
            continue;
        dfs(v);
        sons.push_back(dp[v][0]-dp[v][1]);
        sum+=dp[v][0];
    }

    sort(all(sons));

    for(int i=0;i<3;i++)
    {
        if(i<2)
            ts[u][i]++;
        ll act=sum;
        ts[u][1]+=sons.size();
        dp[u][i]=act+(min(ts[u][0],ts[u][1])*t[u]);
        for(auto y : sons)
        {
            act-=y;
            ts[u][1]--;
            ts[u][0]++;
            dp[u][i]=max(act+(min(ts[u][0],ts[u][1])*t[u]),dp[u][i]);
        }

        ts[u][0]-=sons.size();
        if(i<2)
            ts[u][i]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> t[i];
    for(int i=0;i<n;i++)
        cin >> h[i];
    ll sum=0;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        sum+=t[u]+t[v];
        if(h[u]!=h[v])
        {
            if(h[u]>h[v])
            {
                ts[u][0]++;
                ts[v][1]++;
            }
            else
            {
                ts[u][1]++;
                ts[v][0]++;
            }
        }
        else
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    for(int i=0;i<n;i++)
    {
        if(mk[i])
            continue;
        dfs(i);
//        cout << i << ' ' << dp[i][2] << '\n';
        sum-=dp[i][2];
    }
//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<3;j++)
//            cout << dp[i][j] << ' ';
    db(sum)

    return 0;
}
/**
5
40 10 30 50 20
2 3 2 3 1
1 2
1 3
2 4
2 5

5
1000000 1 1 1 1
1000000 1 1 1 1
1 2
1 3
1 4
1 5

10
510916 760492 684704 32545 484888 933975 116895 77095 127679 989957
402815 705067 705067 705067 623759 103335 749243 138306 138306 844737
1 2
3 2
4 3
1 5
6 4
6 7
8 7
8 9
9 10

**/