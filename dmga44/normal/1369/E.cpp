#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<pii> g[MAXN];
int last[MAXN];
bool mk[MAXN],anal[MAXN];
int w[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> w[i];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        g[x].push_back(pii(y,i));
        g[y].push_back(pii(x,i));
        last[x]++;
        last[y]++;
    }

    vector<int> res;
    queue<int> q;
    for(int i=0;i<n;i++)
        if(w[i]>=last[i])
        {
            q.push(i);
            mk[i]=1;
        }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        anal[u]=1;
        for(auto y : g[u])
        {
            int v=y.first;
            if(!anal[v])
                res.push_back(y.second);
            if(!mk[v])
            {
                last[v]--;
                if(last[v]<=w[v])
                {
                    q.push(v);
                    mk[v]=1;
                }
            }
        }
    }

    if(res.size()==m)
    {
        reverse(all(res));
        db("ALIVE")
        for(int i=0;i<m;i++)
            cout << res[i]+1 << ' ';
        cout << '\n';
    }
    else
        db("DEAD")

    return 0;
}
/**
3 2
1 1 0
1 2
1 3

3 3
1 2 1
1 2
2 3
1 3

4 10
2 4 1 4
3 2
4 2
4 1
3 1
4 1
1 3
3 2
2 1
3 1
2 4
**/