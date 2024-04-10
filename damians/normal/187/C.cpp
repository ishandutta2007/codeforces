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

vi kr[400000];
int s,t;
int n,m,k;
vi vol;
int p[400000];
int szuk(int x){if (x==p[x]) return x;return p[x]=szuk(p[x]);}
void unia(int x,int y){p[szuk(x)]=szuk(y);}

int check()
{
    FOR(i,350000) p[i]=i;
    vi nowe;
    vi tp;
    nowe=vol;
    REP(q,1,n+2)
    {
        tp=nowe;
        nowe.clear();
        FOR(i,tp.sz)
        {
            int u=tp[i];
            FOR(j,kr[u].sz)
            {
                if (szuk(u)!=szuk(kr[u][j]))
                {
                    unia(u,kr[u][j]);
                    nowe.pb(kr[u][j]);
                }
            }
        }
        if (szuk(s)==szuk(t)) return q;
    }
    return n+4;
}


int main()
{
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m>>k;
    vol.resize(k);
    FOR(i,k) cin>>vol[i];
    FOR(i,k) vol[i]--;
    
    int f=n;
    FOR(i,m)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        kr[a].pb(f);
        kr[f].pb(a);
        kr[f].pb(b);
        kr[b].pb(f);
        f++;
    }
    cin>>s>>t;
    t--;s--;
    vol.pb(t);
    int q=check();
    if (q<n+1) cout<<q;
    else cout<<-1;

    return 0;
}