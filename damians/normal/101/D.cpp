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

struct zwrot
{
    double wyn;
    ll dl;
    ll wie;
    zwrot(){wyn=dl=wie=0;}
};

ostream &operator<<(ostream &s,zwrot z) {return s<<"("<<z.wyn<<","<<z.dl<<","<<z.wie<<")";}

bool operator<(zwrot a,zwrot b)
{
    return a.wie*b.dl>a.dl*b.wie;
}

vector<pii> kr[100000];
int n;

zwrot dfs(int u,int p)
{
    zwrot w;
    w.wie=1;
    vector<zwrot> vc;
    DBG(u);
    FORE(i,kr[u])
    {
        if (i->fi==p) continue;
        zwrot z=dfs(i->fi,u);
        DBG(i->fi);
        DBG(z);
        z.dl+=2*i->se;
        z.wyn+=i->se;
        DBG(z);
        w.dl+=z.dl;
        w.wie+=z.wie;
        vc.pb(z);
    }
    sort(ALL(vc));
    double pref=0.0,sum=.0;
    FOR(i,vc.sz)
    {
        sum+=vc[i].wie*1.0*(vc[i].wyn+pref);
        pref+=vc[i].dl;
    }
    if (w.wie)
        w.wyn=sum/w.wie;
    
    return w;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n-1)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        kr[a].pb(mp(b,c));
        kr[b].pb(mp(a,c));
    }
    printf("%.10lf\n",dfs(0,0).wyn*n/(n-1));

    return 0;
}