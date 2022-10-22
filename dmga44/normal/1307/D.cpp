#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int level0[MAXN],leveln[MAXN];
bool mk[MAXN],ks[MAXN];
vector<int> g[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k,a;
    cin >> n >> m >> k;
    for(int i=0;i<k;i++)
    {
        cin >> a;
        a--;
        ks[a]=1;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    mk[0]=1;
    for(q.push(0);!q.empty();q.pop())
    {
        int u=q.front();

        for(auto v : g[u])
            if(!mk[v])
               {
                    mk[v]=1;
                    q.push(v);
                    level0[v]=level0[u]+1;
               }
    }
    for(int i=0;i<n;i++)
        mk[i]=0;

    mk[n-1]=1;
    for(q.push(n-1);!q.empty();q.pop())
    {
        int u=q.front();

        for(auto v : g[u])
            if(!mk[v])
               {
                    mk[v]=1;
                    q.push(v);
                    leveln[v]=leveln[u]+1;
               }
    }
    for(int i=0;i<n;i++)
        mk[i]=0;

    int res=level0[n-1];
    vector<pii> pos;
    for(int i=0;i<n;i++)
        if(ks[i])
            pos.push_back(pii(level0[i]-leveln[i],i));

//    for(int i=0;i<n;i++)
//        cout << level0[i] << ' ' << leveln[i] << '\n';
//    db("")

    sort(pos.begin(),pos.end());

    vector<int> ac(k+1);
    for(int i=k-1;i>=0;i--)
        ac[i]=max(ac[i+1],leveln[pos[i].second]);
    ac[k]=-1e9;

    int r1=0;
    for(int i=0;i<k;i++)
    {
        r1=max(r1,level0[pos[i].second]+1+ac[i+1]);
//        cout << level0[pos[i].second] << ' ' << ac[i+1] << '\n';
    }
    db(min(res,r1))

    return 0;
}