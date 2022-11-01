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
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define MAXNODE 100001

vi kr[MAXNODE],krt[MAXNODE];
vi kra[MAXNODE];
vector<vi> skl;//wynik
int nrskl[MAXNODE];//wynik
bool odw[MAXNODE];
vi stos;
int akt;

vi krc[MAXNODE];
int N, Nc;

inline void dod_kr(int a,int b)
{
    kr[a].pb(b);
    krt[b].pb(a);
}
void czysc(int N0)
{
    N=N0;
    FOR(i,N) kr[i].clear();
    FOR(i,N) krt[i].clear();
    skl.clear();
}

void dfs(int u)
{
    odw[u]=1;
    FORE(i,kr[u]) if (!odw[*i]) dfs(*i);
    stos.pb(u);
}

void dfst(int u)
{
    odw[u]=1;
    nrskl[u]=akt;
    skl[akt].pb(u);
    FORE(i,krt[u]) if (!odw[*i]) dfst(*i);
}

void lol()
{
    stos.clear();
    akt=0;
    FOR(i,N) odw[i]=0;
    FOR(i,N) if (!odw[i]) dfs(i);
    FOR(i,N) odw[i]=0;
    REPD(i,N-1,0) if (!odw[stos[i]]) 
    {
        skl.pb(vi());
        dfst(stos[i]);
        akt++;
    }
    Nc=skl.sz;
}


set<pii> st;

vector<pii> wyn;

void dfs1(int u)
{
    odw[u]=1;
    FORE(j,kra[u])
    {
        if (!odw[*j])
        {
            st.insert(mp(u,*j));
            st.insert(mp(*j,u));
            wyn.pb(mp(u,*j));
            dod_kr(u,*j);
            dfs1(*j);
        }
        else
        {
            if (!IN(mp(u,*j),st))
            {
                st.insert(mp(u,*j));
                st.insert(mp(*j,u));
                wyn.pb(mp(u,*j));
                dod_kr(u,*j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    czysc(n);
    FOR(i,m)
    {
        int a,b;cin>>a>>b;
        a--;b--;
        kra[a].pb(b);
        kra[b].pb(a);
    }
    dfs1(0);
    FOR(i,n) odw[i]=0;
    lol();
    if (Nc>1)
    {
        cout<<0;
        return 0;
    }
    FOR(i,wyn.sz) cout<<wyn[i].fi+1<<" "<<wyn[i].se+1<<"\n";

    return 0;
}