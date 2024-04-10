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
typedef pair<ll,ll> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int n,k;
vector<pii> v;

inline bool jest(pii p)
{
    vector<pii>::iterator it=lower_bound(ALL(v),p);
    if (it==v.end() || *it!=p) return 0;
    return 1;
}

bool check(pii s)
{
    int brak=0;
    int z=n-1;
    FOR(i,n)
    {
        pii p=mp(2*s.fi-v[i].fi,2*s.se-v[i].se);
        while(z>=0 && v[z]>p) z--;
        if (z<0 || v[z]!=p) brak++;
        if (brak>k) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    if (k>=n)
    {
        cout<<-1;
        return 0;
    }
    v.resize(n);
    FOR(i,n) {cin>>v[i].fi>>v[i].se;v[i].fi*=2;v[i].se*=2;}
    sort(ALL(v));
    vector<pii> wyn;
    FOR(i,k+1) REPD(j,n-1,n-1-k)
    {
        pii s;
        s.fi=(v[i].fi+v[j].fi)/2;
        s.se=(v[i].se+v[j].se)/2;
        if (check(s)) wyn.pb(s);
    }
    sort(ALL(wyn));
    un(wyn);
    cout<<wyn.sz<<"\n";
    cout<<setprecision(2)<<fixed;
    FOR(i,wyn.sz)
    {
        cout<<wyn[i].fi*0.5<<" "<<wyn[i].se*0.5<<"\n";
    }
    

    return 0;
}