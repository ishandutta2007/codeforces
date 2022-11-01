#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int n;
set<int> wi[5001];
int p[50005];
int kgora[50004];
vector<int> kr[50006];
vector<int> koszt[50006];
bool odw[50006];
map<int,int> ind;

void dfs(int u, int par,int kosz)
{
    DBG(u);
    p[u]=par;
    kgora[u]=kosz;
    odw[u]=1;
    FOR(i,kr[u].sz)
    {
        if (!odw[kr[u][i]]) dfs(kr[u][i],u,koszt[u][i]);
    }
}

int wyn[50004];
int wyn2[50004];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    vector<pii> kol(n);
    FOR(i,n)
    {
        int a;cin>>a;
        wi[i].insert(a);
        ind[a]=i;        
        kol[i]=mp(a,i);
    }
    FOR(i,n) odw[i]=0;
    FOR(i,n-1)
    {
        int a,b,x;
        cin>>a>>b>>x;
        a--;b--;
        koszt[a].pb(x);
        koszt[b].pb(x);
        kr[a].pb(b);
        kr[b].pb(a);
        
    }
    dfs(0,0,0);
    
    sort(ALL(kol));
    int czas=0;
    int ile=0;
    FOR(i,n) wyn[i]=-1;
    DBG(kol);
    while(ile<n)
    {
        DBG(ile);
        vi miejsce=vi(kgora,kgora+n);
        DBG(miejsce);
        DBG(kol);
        FOR(i,n)
        {
            int u=kol[i].se;
            if (u==0 && wyn[i]==-1)
            {
                ile++;
                wyn[i]=czas;
            }
            else if (u!=0)
            {
                if (miejsce[u])
                {
                    miejsce[u]--;
                    kol[i].se=p[u];
                }
            }
        }
        czas++;
    }
    FOR(i,n) wyn2[ind[kol[i].fi]]=wyn[i];
    FOR(i,n) cout<<wyn2[i]<<" ";
    DBG(vi(wyn,wyn+n));

    return 0;
}