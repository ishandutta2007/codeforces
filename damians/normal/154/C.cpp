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
#include <ctime>
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
#define ull unsigned long long
#define MAXN 1000003
unsigned X;
ull pX[MAXN];
vector<pair<int,ull> > v;
vi kr[1000000+2];

ull lol(const vi& g)
{
    ull wyn=0;
    FOR(i,g.sz) wyn+=pX[i]*g[i];
    return wyn;
}

int main()
{
    srand(time(0));
    while(1)
    {
        X=rand();
        if (X%2 && X>20000) break;
    }
    X*=X;
    pX[0]=1;REP(i,1,MAXN-1) pX[i]=X*pX[i-1];
    int n,m;
    CZ2(n,m);
    FOR(i,m)
    {
        int a,b;CZ2(a,b);
        a--;b--;
        kr[a].pb(b);
        kr[b].pb(a);
    }
    FOR(i,n)
    {
        sort(ALL(kr[i]));
        v.pb(mp(kr[i].sz,lol(kr[i])));
        kr[i].pb(i);
        sort(ALL(kr[i]));
        v.pb(mp(kr[i].sz,lol(kr[i])));
    }
    sort(ALL(v));
    int i=0;
    ll w=0;
    //DBG(v);
    while(i<v.sz)
    {
        int j=1;
        while(j<v.sz && v[i+j-1]==v[i+j]) j++;
        w+=j*1LL*(j-1)/2;
        i+=j;
    }
    cout<<w;

    return 0;
}