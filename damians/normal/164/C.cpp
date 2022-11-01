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
#include <climits>
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

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }


namespace MCF {
    #define MAXN 100010
    #define MAXM 100010
    #define wint int
    #define cint int
    const wint wEPS = 0;
    const wint wINF = 1001001001;
    const cint cEPS = 0;
    const cint cINF = 1001001001;
    int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
    wint capa[MAXM], tof;
    cint cost[MAXM], toc, d[MAXN], pot[MAXN];
    int vis[MAXN], pree[MAXN];
    void init(int _n) {
        n = _n; m = 0; memset(ptr, ~0, n << 2);
    }
    void ae(int u, int v, wint w, cint c) {
        next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
        next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
    }
    bool spRep(int src, int ink, wint flo = wINF) {
        wint f;
        cint c, cc;
        int i, u, v;
        memset(pot, 0, n * sizeof(cint));
    //*
        for (bool cont = 1; cont; ) {
            cont = 0;
            for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
                if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
                    pot[zu[i]] = pot[u] + cost[i]; cont = 1;
                }
            }
        }
    //*/
        for (toc = 0, tof = 0; tof + wEPS < flo; ) {
            typedef pair<cint,int> node;
            priority_queue< node,vector<node>,greater<node> > q;
            for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
            for (q.push(mp(d[src] = 0, src)); !q.empty(); ) {
                c = q.top().first; u = q.top().second; q.pop();
                if (vis[u]++) continue;
                for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
                    cc = c + cost[i] + pot[u] - pot[v = zu[i]];
                    if (d[v] > cc) { q.push(mp(d[v] = cc, v)); pree[v] = i; }
                }
            }
            if (!vis[ink]) return 0;
            f = flo - tof;
            for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; chmin(f, capa[i]); }
            for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
            tof += f;
            toc += f * (d[ink] - pot[src] + pot[ink]);
            for (u = 0; u < n; ++u) pot[u] += d[u];
        }
        return 1;
    }
}


int s[2000],t[2000];
int c[2000];
int nrkr[2000];
vi czas;

int getuj(int x)
{
    return lower_bound(ALL(czas),x)-czas.begin();
}

    

int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;cin>>n>>k;
    FOR(i,n)
    {
        cin>>s[i]>>t[i]>>c[i];
        czas.pb(s[i]);
        czas.pb(s[i]+t[i]);
    }
    sort(ALL(czas));
    un(czas);
    int C=czas.sz;
    MCF::init(C+3);
    int zr=0;
    int zr2=1;
    int cel=C+2;
    MCF::ae(zr,zr2,k,0);
    FOR(i,C-1) MCF::ae(i+2,i+2+1,1000,0);
    FOR(i,C) MCF::ae(zr2,i+2,1000,0);
    FOR(i,n) {nrkr[i]=MCF::m;MCF::ae(2+getuj(s[i]),2+getuj(s[i]+t[i]),1,-c[i]);}
    FOR(i,C) MCF::ae(i+2,cel,1000,0);

    int wyn=MCF::spRep(0,C+2);
    //int f=mcmf4( 2*n+6, zr, cel, wyn );
    //DBG(wyn);
    //cout<<-wyn;
    FOR(i,n) cout<<1-MCF::capa[nrkr[i]]<<" ";
    
    
    

    return 0;
}