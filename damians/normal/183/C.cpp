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
#define INF 10000000

vi kr[100001];
vector<pii> kr2[100001];


bool odw[100001];
int kol[100001];
vi L;



void rub(int u,int c)
{
    if (odw[u])
    {
        L.pb(abs(kol[u]-c));
        return;
    }
    odw[u]=1;
    kol[u]=c;
    pii p;
    FOR(i,kr2[u].sz)
    {
        p=kr2[u][i];
        if (p.se==1) rub(p.fi,c+1);
        else rub(p.fi,c-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    FOR(i,m)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        kr[a].pb(b);
        kr2[a].pb(mp(b,1));
        kr2[b].pb(mp(a,-1));
    }

    FOR(i,n) odw[i]=0;
    FOR(i,n) kol[i]=0;
    FOR(i,n) if (!odw[i]) rub(i,0);
    int d=0;
    FOR(i,L.sz)
    {
        if (L[i]) d=__gcd(d,L[i]);
    }
    int best=1;
    REP(i,1,n)
    {
        if (d%i==0)best=i;
        
    }
    cout<<best;

    return 0;
}