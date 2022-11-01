#include <string>
#include <vector>
#include <algorithm>
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

ll t[1000000];
int n,s;
vector<int> kr[1000000];
bool odw[1000000];

ll dfs(int u)
{
    if (u!=s)
    {
        t[u]--;
    }
    ll wyn=(u!=s);
    vector<pair<ll,int> > v;
    odw[u]=1;
    ll ile=0;
    
    FOR(i,kr[u].sz)
    {
        if (odw[kr[u][i]]) continue;
        pair<ll,int> p=mp(dfs(kr[u][i]),i);
        ile+=t[kr[u][i]];
        v.pb(p);
    }
    sort(ALL(v));
    reverse(ALL(v));
    FOR(i,v.sz)
    {
        pair<ll,int> p=v[i];
        if (t[u]>0)
        {
            wyn+=p.fi+1;
            t[u]--;
        }
        DBG(wyn);
    }
    wyn+=2*min(ile,t[u]);
    t[u]-=min(ile,t[u]);
    DBG2(u+1,wyn);
    DBG(ile);
    DBG(t[u]);
    return wyn;
    
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n) cin>>t[i];
    FOR(i,n) kr[i].clear();
    FOR(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        kr[a].pb(b);
        kr[b].pb(a);
    }
    FOR(i,n) odw[i]=0;
    cin>>s;s--;
    cout<<dfs(s);
    

    return 0;
}