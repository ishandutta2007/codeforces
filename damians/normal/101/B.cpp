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

int bit[1000008];
int maxval;

#define MOD 1000000007

void czysc(int mxv)
{
    maxval=mxv;
    FOR(i,mxv+1) bit[i]=0;
}

void dodaj(int ind, int war)
{
    ind++;
    while(ind<maxval)
    {
        bit[ind]+=war;
        bit[ind]%=MOD;
        ind+=(ind & -ind);
    }
}

ll suma(int ind)
{
    ind++;
    ll sm=0;
    while(ind>0)
    {
        sm+=bit[ind];
        ind-=(ind & -ind);
    }
    return sm%MOD;
}

ll suma(int ind1,int ind2)
{
    return (suma(ind2)-suma(ind1-1)+MOD)%MOD;
}

map<int,int> tl;
vi v;
int p[200001],k[200001];
vector<pii> pr;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    FOR(i,m)
    {
        cin>>p[i]>>k[i];
        v.pb(p[i]);
        v.pb(k[i]);
    }
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    FOR(i,v.sz) tl[v[i]]=i;
    if (!IN(n,tl) || !IN(0,tl))
    {
        cout<<0;
        return 0;
    }
    n=tl[n];
    czysc(tl.sz+5);
    //DBG(n);
    FOR(i,m)
    {
        p[i]=tl[p[i]];
        k[i]=tl[k[i]];
        pr.pb(mp(k[i],p[i]));
    }
    sort(ALL(pr));
    dodaj(0,1);
    FORE(j,pr)
    {
        dodaj(j->fi,suma(j->se,j->fi-1));
    }
    cout<<(suma(n,n)%MOD+MOD)%MOD<<endl;
    

    return 0;
}