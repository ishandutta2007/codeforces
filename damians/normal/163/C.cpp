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

vector<ll> a;
double wyn[200000];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    ll l,v1,v2;
    cin>>n>>l>>v1>>v2;
    a.resize(n);
    FOR(i,n)
    {
        cin>>a[i];
        a[i]-=2*l;
        a[i]*=(v1+v2);
    }
    l*=2*(v1+v2);
    FOR(i,n) a.pb(a[i]+l);
    a.pb((1LL<<63)-1);
    int i1=0,i2=0;
    int ile=0;
    ll L=l/(2*(v1+v2))*v2;
    while(a[i2+1]-a[i1]<=L) {i2++;ile++;}
    ll x=a[0];
    DBG(a);
    DBG(l);
    DBG(L);
    while(i1!=n)
    {
        DBG(x);
        DBG(i1);
        DBG(i2);
        DBG(ile);
        ll odl=0;
        if (a[i2+1]-(x+L)<a[i1+1]-x)
        {
            DBG("1");
            odl=a[i2+1]-(x+L);
            DBG(odl);
            x+=odl;
            i2++;
            wyn[ile]+=odl*1.0/l;
            ile++;
        }
        else
        {
            DBG("2");
            odl=a[i1+1]-(x);
            DBG(odl);
            x+=odl;
            i1++;
            wyn[ile]+=odl*1.0/l;
            ile--;
        }
    }
    FOR(i,n+1) cout<<setprecision(12)<<fixed<<wyn[i]<<"\n";
    
    

    return 0;
}