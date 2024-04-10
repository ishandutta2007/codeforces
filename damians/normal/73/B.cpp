#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
#define ML 1000000LL
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

map<string,int> mapa;
ll a[200000],b[200000];
vector<ll> v;
ll n,m;
multiset<ll> B;
string imie;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)
    {
        string s;ll x;
        cin>>s>>x;
        mapa[s]=i;
        a[i]=x*ML;
    }
    int nr=1;
    FOREACH(it,mapa)
    {
        nr++;
        DBG(it->fi);
        a[(it->se)]+=ML-nr;
    }
    cin>>m;
    FOR(i,m) cin>>b[i];
    REP(i,m,n-1) b[i]=0;
    cin>>imie;
    ll A=a[mapa[imie]];
    FOR(i,n) b[i]*=ML;
    sort(b,b+n);
    
    FOR(i,n-1) B.insert(b[n-1]-b[i]);
    DBG(B.sz);
    FOR(i,n) if (a[i]>A) v.pb(a[i]-A);
    sort(ALL(v));
    multiset<ll>::iterator it;
    int high=0,low=0;
    DBG(v);
    FOR(i,v.sz)
    {
        DBG(v[i]);
        DBG(B.sz);
        if (B.empty()) break;
        it=B.lower_bound(v[i]);
        if (it==B.end()) break;
        else
        {
            DBG(*it);
            B.erase(it);
            high++;
        }
    }
    cout<<v.sz-high+1<<" ";
    B.clear();
    v.clear();
    REP(i,1,n-1) {B.insert(b[i]-b[0]);}
    FOR(i,n) if (a[i]<A) v.pb(-a[i]+A);
    sort(ALL(v));
    DBG(v);
    FOR(i,v.sz)
    {
        DBG(v[i]);
        if (B.empty()) break;
        it=B.lower_bound(v[i]);
        //DBG(*it);
        if (it==B.end()) break;
        else
        {
            DBG(*it);
            B.erase(it);
            low++;
        }
    }
    DBG(low);
    cout<<n-(v.sz-low)<<" ";

    return 0;
}