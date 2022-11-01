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

int p[222222];
int rp[222222];
int n;
ll odp[222222];

struct ev
{
	int typ;//0 pkt
	int x,y;
	int nr;
	bool operator<(ev e) const
	{
		if (x==e.x) return typ<e.typ;
		return x>e.x;
	}
};

int main()
{
    ios_base::sync_with_stdio(0);
    int q;
    cin>>n>>q;
    REP(i,1,n) cin>>p[i];
    REP(i,1,n) rp[p[i]]=i;
    vector<ev> v;
    ev tp;
    REP(i,1,n)
    {
		for(int j=i;j<=n;j+=i) 
		{
			tp.typ=0;
			tp.x=rp[i];
			tp.y=rp[j];
			if (tp.x>tp.y) swap(tp.x,tp.y);
			v.pb(tp);
		}
	}
	FOR(i,q)
	{
		int a,b;cin>>a>>b;
		tp.typ=1;
		tp.x=a;
		tp.y=b;
		tp.nr=i;
		v.pb(tp);
	}
	sort(ALL(v));
	czysc(n+4);
	FOR(i,v.sz)
	{
		if (v[i].typ==0)
		{
			dodaj(v[i].y,1);
		}
		else
		{
			odp[v[i].nr]=suma(v[i].y);
		}
	}
	FOR(i,q) cout<<odp[i]<<"\n";
    
    
    
    return 0;
}