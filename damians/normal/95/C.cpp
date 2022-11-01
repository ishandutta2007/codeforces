#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
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
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define INF (1LL<<60)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

priority_queue<pair<ll,ll> > Q;
vector<vector<pair<int,ll> > > kr; 
vector<vector<pair<int,ll> > > kr1; 
bool dod[1002];
ll opt[10002];
int n;

ll d[1002][1002];

void dij(int zrodlo)
{
    FOR(i,1002) opt[i]=INF;
    FOR(i,1002) dod[i]=0;
    opt[zrodlo]=0;
    Q.push(mp(0,zrodlo));
    while(!Q.empty())
    {
        ll p=(Q.top()).se;
        if (dod[p]) 
        {
            Q.pop();
            continue;
        }
        opt[p]=-((Q.top()).fi);
        Q.pop();
        
        
        dod[p]=1;
        FOR(i,kr[p].sz)
        {
            if (!dod[kr[p][i].fi] && (opt[kr[p][i].fi]>opt[p]+kr[p][i].se))
            {
                opt[kr[p][i].fi]=opt[p]+kr[p][i].se;
                Q.push(mp(-opt[kr[p][i].fi],kr[p][i].fi));
            }
        }
    }
    FOR(i,n) d[zrodlo][i]=opt[i];
}

int x,y;

void dij2(int zrodlo)
{
    FOR(i,1002) opt[i]=INF;
    FOR(i,1002) dod[i]=0;
    opt[zrodlo]=0;
    Q.push(mp(0,zrodlo));
    while(!Q.empty())
    {
        ll p=(Q.top()).se;
        if (dod[p]) 
        {
            Q.pop();
            continue;
        }
        opt[p]=-((Q.top()).fi);
        Q.pop();
        
        
        dod[p]=1;
        FOR(i,kr1[p].sz)
        {
            if (!dod[kr1[p][i].fi] && (opt[kr1[p][i].fi]>opt[p]+kr1[p][i].se))
            {
                opt[kr1[p][i].fi]=opt[p]+kr1[p][i].se;
                Q.push(mp(-opt[kr1[p][i].fi],kr1[p][i].fi));
            }
        }
    }
    if (opt[y]<INF)
    {
        cout<<opt[y]<<endl;
    }
    else
    cout<<-1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int m;cin>>n>>m;
    kr.resize(n);
    kr1.resize(n);
    FOR(i,1002) FOR(j,1002) d[i][j]=INF;
    cin>>x>>y;x--;y--;
    FOR(i,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        kr[a].pb(mp(b,c));
        kr[b].pb(mp(a,c));
    }
    FOR(i,n) dij(i);
    FOR(i,n)
    {
        ll a,b;
        cin>>a>>b;
        FOR(j,n) if (d[i][j]<=a)
        {
            kr1[i].pb(mp(j,b));
        }
    }
    dij2(x);
    
    
    

    return 0;
}