#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

vector<int> g[MAXN];
int level[MAXN][3];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,a,b,c,u,v;
        cin >> n >> m >> a >> b >> c;
        for(int i=0;i<n;i++)
        {
            level[i][0]=0;
            level[i][1]=0;
            level[i][2]=0;
            g[i].clear();
        }
        a--,b--,c--;
        vector<ll> p(m),ac(m+1),ini;
        for(int i=0;i<m;i++)
            cin >> p[i];
        sort(all(p));
        for(int i=0;i<m;i++)
            ac[i+1]=ac[i]+p[i];

        for(int i=0;i<m;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ini.push_back(a);
        ini.push_back(b);
        ini.push_back(c);
        for(int k=0;k<3;k++)
        {
            int tt=ini[k];
            queue<int> q;
            q.push(tt);
            mk[tt]=1;

            while(!q.empty())
            {
                int u=q.front();
                q.pop();

                for(auto v : g[u])
                    if(!mk[v])
                    {
                        mk[v]=1;
                        q.push(v);
                        level[v][k]=level[u][k]+1;
                    }
            }

            for(int i=0;i<n;i++)
                mk[i]=0;
        }

        ll res=1e18;
        for(int i=0;i<n;i++)
        {
            int l1=level[i][1];
            int l2=level[i][0]+level[i][2];
            if(l1+l2<=m)
                res=min(res,ac[l1]+ac[l1+l2]);
        }
        db(res)
    }

    return 0;
}
/**
1
4 3 2 3 4
1 2 3
1 2
1 3
1 4

**/