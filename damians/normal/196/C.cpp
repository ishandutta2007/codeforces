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
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

vi kr[1600];
int wiel[1600];
int odp[1600];//nr ver

int dfs(int u,int p)
{
    FOR(i,kr[u].sz)
    {
        if (kr[u][i]==p)
        {
            swap(kr[u][i],kr[u].back());
            kr[u].pop_back();
            break;
        }
    }
    wiel[u]=1;
    FORE(i,kr[u])
    {
        wiel[u]+=dfs(*i,u);
    }
    return wiel[u];
}

pair<pii,int> pkt[1600];
int x,y;

double kat;
int sx,sy;

struct por
{
    bool operator()(pair<pii,int> a,pair<pii,int> b)
    {
        double A=atan2(a.fi.se-sy,a.fi.fi-sx)-kat;
        if (A<0) A+=2*M_PI;if (A>=2*M_PI) A-=2*M_PI;
        double B=atan2(b.fi.se-sy,b.fi.fi-sx)-kat;
        if (B<0) B+=2*M_PI;if (B>=2*M_PI) B-=2*M_PI;
        return A<B;
    }
};


void go(int u,int a,int b,int px,int py)
{
    DBG(u);
    DBG(a);
    DBG(b);
    DBG(px);
    DBG(py);
    DBG((vector<pair<pii,int> >(pkt+a,pkt+(b+1))));
    odp[pkt[a].se]=u;
    if (a==b) return;
    if (kr[u].sz==1)
    {
        go(kr[u][0],a+1,b,pkt[a].fi.fi,pkt[a].fi.se);
        return;
    }
    sx=pkt[a].fi.fi;
    sy=pkt[a].fi.se;
    DBG(mp(py-sy,px-sx));
    kat=atan2(py-sy,px-sx);
    DBG(kat);
    a++;
    sort(pkt+a,pkt+(b+1),por());
    int ax=sx;
    int ay=sy;
    FORE(i,kr[u])
    {
        go(*i,a,a+wiel[*i]-1,ax,ay);
        a=a+wiel[*i];
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    FOR(i,n-1)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        kr[a].pb(b);
        kr[b].pb(a);
    }
    FOR(i,n)
    {
        cin>>pkt[i].fi.fi>>pkt[i].fi.se;
        pkt[i].se=i;
    }
    dfs(0,-1);
    sort(pkt,pkt+n);
    
    go(0,0,n-1,pkt[0].fi.fi-10,pkt[0].fi.se-10);
    FOR(i,n) cout<<odp[i]+1<<" ";

    return 0;
}