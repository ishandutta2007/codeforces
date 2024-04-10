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

set<int> all;
set<int> s1[100005],s2[100005];
vector<pair<int,pii> > but;
vi kr[100005];
vi lewo[100005];
int kasa[100002];
bool ob[100002];

int getuj(int roz)
{
    return lower_bound(ALL(but),mp(roz,mp(0,0)))-but.begin();
}

void wywal(int nr,int skad)
{
    REP(j,skad,skad+1)
    {
        s1[j].erase(nr);
        s2[j].erase(nr);
    }
}

set<int> Q;
ll suma=0;
vector<pii> wyn;

void paruj(int a,int b)
{
    ob[a]=0;
    all.erase(but[b].fi);
    FOR(j,kr[b].sz) Q.insert(kr[b][j]);
    suma+=but[b].se.se;
    wyn.pb(mp(a,but[b].se.fi));
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    FOR(i,n)
    {
        int c;
        int r;
        cin>>c>>r;
        but.pb(mp(r,mp(i,c)));
        all.insert(r);
    }
    sort(ALL(but));
    int m;cin>>m;
    
    FOR(i,m)
    {
        int kas,roz;
        cin>>kas>>roz;
        kasa[i]=kas;
        vi d;
        REP(r,roz,roz+1)
        {
            if (!IN(r,all)) continue;
            int nr=getuj(r);
            if (but[nr].se.se<=kas)
            {
                d.pb(nr);
                kr[nr].pb(i);
            }
        }
        DBG(d);
        lewo[i]=d;
        if (d.sz<2) Q.insert(i);
        ob[i]=1;
    }
    while(Q.sz)
    {
        int nr=*(Q.begin());
        Q.erase(Q.begin());
        if (!ob[nr]) continue;
        FOR(j,lewo[nr].sz)
        {
            int B=lewo[nr][j];
            if (!IN(but[B].fi,all)) continue;
            paruj(nr,B);
        }
        ob[nr]=0;
    }
    FOR(i,m)
    {
        if (ob[i])
        {
            if (lewo[i].sz!=2) {DBG("AFDGSDGSDGSG ZLO");return 0;}
            s1[lewo[i][0]].insert(i);
            s2[lewo[i][1]].insert(i);
        }
    }
    int i=0;
    while(i<but.sz)
    {
        DBG(but[i]);
        DBG(s1[i].sz);
        DBG(s2[i].sz);
        if (s1[i].sz==0) {i++;continue;}
        int j=i;
        int h=0;
        while(s1[j].sz) {h+=s1[j].sz;j++;}
        if (h>j-i)
        {
            REP(r,i,j)
            {
                if (s2[r].sz)
                {
                    int nr=*(s2[r].begin());
                    suma+=but[r].se.se;
                    wyn.pb(mp(nr,but[r].se.fi));
                    wywal(nr,r);
                }
                else
                {
                    if (s1[r].sz==0) {DBG("AFDGSDGSDGSG ZLO22222");return 1;}
                    int nr=*(s1[r].begin());
                    suma+=but[r].se.se;
                    wyn.pb(mp(nr,but[r].se.fi));
                    wywal(nr,r);
                }
            }
        }
        else
        {
            int slaby=i;
            REP(r,i,j)
            {
                if (but[r].se.se<but[slaby].se.se) slaby=r;
            }
            REP(r,i,j)
            {
                if (r==slaby) continue;
                if (s2[r].sz)
                {
                    int nr=*(s2[r].begin());
                    suma+=but[r].se.se;
                    wyn.pb(mp(nr,but[r].se.fi));
                    wywal(nr,r);
                }
                else
                {
                    if (s1[r].sz==0) {DBG("AFDGSDGSDGSG ZLO22222");return 1;}
                    int nr=*(s1[r].begin());
                    suma+=but[r].se.se;
                    wyn.pb(mp(nr,but[r].se.fi));
                    wywal(nr,r);
                }
            }
        }
        i=j+1;
    }
    cout<<suma<<"\n";
    cout<<wyn.sz<<"\n";
    FOR(i,wyn.sz) cout<<wyn[i].fi+1<<" "<<wyn[i].se+1<<"\n";

    return 0;
}