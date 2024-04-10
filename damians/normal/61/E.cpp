#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
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
#define CZ(x) scanf("%d",&(x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;

template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int bit[1100001];
int maxval;//do ustawienia
// BIT obsluguje przedzial [1..maxval]

void czysc(int mxv)
{
    maxval=mxv;
    FOR(i,mxv+1) bit[i]=0;
}

void dodaj(int ind, int war)
{
    while(ind<=maxval)
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

int t[1000004];
pair<int,int> p[1000004];

int main()
{
    int n;CZ(n);
    FOR(i,n) CZ(t[i]);
    FOR(i,n) p[i]=mp(t[i],i);
    sort(p,p+n);
    FOR(i,n) t[p[i].se]=i+1;
    czysc(n);
    ll wyn=0,w1,w2;
    int x;
    FOR(i,n)
    {
        x=t[i];
        w1=suma(n)-suma(x-1);
        w2=x-1-suma(x-1);
        wyn+=w1*w2;
        dodaj(x,1);
    }
    cout<<wyn<<endl;

    

    return 0;
}