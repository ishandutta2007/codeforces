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

vector<pii> wyn[2000];
vector<pii> stul,pen;


int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;cin>>n>>k;
    FOR(i,n)
    {
        int a,b;cin>>a>>b;
        a*=2;
        if (b==1) stul.pb(mp(a,i+1));
        else pen.pb(mp(a,i+1));
    }
    sort(ALL(pen));
    sort(ALL(stul));
    reverse(ALL(stul));
    DBG(stul);
    int ILE=stul.sz;
    int nr=0;
    REPD(i,min(ILE,k)-1,0) wyn[nr++].pb(stul[i]);

    if (ILE<k)
    {
        //DBG(ILE);
        FOR(j,pen.sz)
        {
            wyn[ILE].pb(pen[j]);
            if (ILE+1<k) ILE++;
        }
    }
    else
    {
        REP(j,k,(int)stul.sz-1) wyn[0].pb(stul[j]);
        FOR(j,pen.sz)
        {
            wyn[0].pb(pen[j]);
        }
    }
    ll w=0;
    FOR(i,k)
    {
        sort(ALL(wyn[i]));
        if (i<stul.sz) w-=wyn[i][0].fi/2;
        FOR(j,wyn[i].sz) w+=wyn[i][j].fi;
    }
    cout<<w/2;
    cout<<".";
    cout<<5*(w%2)<<"\n";
    FOR(i,k)
    {
        cout<<wyn[i].sz<<" ";
        FOR(j,wyn[i].sz) cout<<wyn[i][j].se<<" ";
        cout<<"\n";
    }

    return 0;
}