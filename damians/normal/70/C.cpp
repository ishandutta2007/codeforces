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
#define LOLDBG
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
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int bit[1000008];
int maxval;
// BIT obsluguje przedzial [1..maxval-1]

void czysc(int mxv)
{
    maxval=mxv;
    FOR(i,mxv+1) bit[i]=0;
}

void dodaj(int ind, int war)
{
    while(ind<maxval)
    {
        bit[ind]+=war;
        ind+=(ind & -ind);
    }
}

int suma(int ind)//[1..ind]
{
    int sm=0;
    while(ind>0)
    {
        sm+=bit[ind];
        ind-=(ind & -ind);
    }
    return sm;
}




int rev(int x)
{
    vector<int> v;
    while(x) {v.pb(x%10);x/=10;}
    reverse(ALL(v));
    int w=0;
    int d=1;
    FOR(i,v.sz) {w+=d*v[i];d*=10;}
    return w;
}

pii fr(int x)
{
    pii p=mp(x,rev(x));
    int d=__gcd(x,rev(x));
    p.fi/=d;
    p.se/=d;
    return p;
}

int mx,my,w;



pii sw(pii p)
{
    return mp(p.se,p.fi);
}

map<pii,int> m;
vi tab[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>mx>>my>>w;
    
    czysc(1<<17);
    int nr=0;
    REP(i,1,my) 
    {
        if (!IN(fr(i),m)) {m[fr(i)]=nr;nr++;}
        tab[m[fr(i)]].pb(i);
    }
    ll best=1LL<<50,bx,by;
    int hi=my;
    REP(x,1,mx)
    {
        if (!IN(sw(fr(x)),m)) continue;
        vi &v=tab[m[sw(fr(x))]];
        FOR(i,v.sz) dodaj(v[i],1);
        while(suma(hi-1)>=w)
            hi--;
        if (suma(hi)>=w)
        {
            if (best>(ll)x*hi)
            {
                best=(ll)x*hi;
                bx=x;
                by=hi;
            }
        }
    }
    if (best<(1LL<<50))
    cout<<bx<<" "<<by<<endl;
    else cout<<-1<<endl;
    

    return 0;
}