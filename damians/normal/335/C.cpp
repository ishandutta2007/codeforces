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
#define FOREACH(i,t) FORE(i,t)
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
#define LOLDBG
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
#define wez(x) int x; CZ(x);
#define wez2(x,y) int x,y; CZ2(x,y);
#define wez3(x,y,z) int x,y,z; CZ3(x,y,z);
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
inline void pisz (int x) { printf("%d\n", x); }
typedef vector<pii> vp;

vp norm(vp v)
{
    if (v.sz==0) return v;
    int mn=111;
    sort(ALL(v));
    FOR(i,v.sz) REMIN(mn,v[i].fi);
    FOR(i,v.sz) v[i].fi-=mn;
    if (v[0].se)FOR(i,v.sz) v[i].se^=1;
    return v;
}

vector<vp> dziel(vp v)
{
    sort(ALL(v));
    vector<vp> wyn;
    int i=0;
    while(i<v.sz)
    {
        int j=i+1;
        while(j<v.sz && abs(v[j].fi-v[j-1].fi)<=1) j++;
        vp z;
        REP(k,i,j-1)z.pb(v[k]);
        wyn.pb(norm(z));
        i=j;
    }
    return wyn;
}

map<vp,int> nim;

int go(vp v)
{
    //DBG(v);
    if (v.sz==0) return 0;
    if (v.sz==1) return 1;
    if (IN(v,nim)) return nim[v];
    int x=0;
    int moz[222]={0};
    FOR(i,v.sz)
    {
        vp z;
        FOR(j,v.sz)
        {
            if (j==i) continue;
            if (v[j].se!=v[i].se && abs(v[j].fi-v[i].fi)<=1) continue;
            z.pb(v[j]);
        }
        vector<vp> podz=dziel(z);
        int X=0;
        FOR(j,podz.sz) {int wr=go(podz[j]);X^=wr;}
        moz[X]=1;
        
    }
    while(moz[x])x++;
    return nim[v]=x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int r,n;
    cin>>r>>n;
    vp v;
    FOR(i,r){v.pb(mp(i,0));v.pb(mp(i,1));}
    FOR(i,n)
    {
        int a,b;cin>>a>>b;a--;b--;
        vp z;
        FOR(j,v.sz)
        {
            if (v[j]==mp(a,b)) continue;
            if (v[j].se!=b && abs(a-v[j].fi)<=1) continue;
            z.pb(v[j]);
        }
        v=z;
    }
    v=norm(v);
    int g=go(v);
    if (g) puts("WIN");
    else puts("LOSE");

    return 0;
}