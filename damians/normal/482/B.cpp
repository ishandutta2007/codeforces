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
#include <complex>
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
int n,m;
int l[1<<17],r[1<<17],q[1<<17];
int a[1<<17];
int s[1<<17];

bool check(int b)
{
	FOR(i,n+2)s[i]=0;
	FOR(i,m)
	{
		int x=((1<<b)&q[i]);
		if (x)
		{
			s[l[i]]+=1;
			s[r[i]+1]+=-1;
		}
	}
	REP(i,1,n) s[i]=s[i-1]+s[i];
	REP(i,1,n) s[i]=!!(s[i]);
	REP(i,1,n) s[i]+=s[i-1];
	FOR(i,m)
	{
		int x=((1<<b)&q[i]);
		if (!x)
		{
			int wyn=s[r[i]]-s[l[i]-1];
			if (wyn==r[i]-l[i]+1) return 0;
		}
	}
	REP(i,1,n) a[i]^=(1<<b)*(s[i]-s[i-1]);
	return 1;
}


int main()
{
    CZ2(n,m);
    //cin>>n>>m;
    FOR(i,m)CZ3(l[i],r[i],q[i]);
    FOR(b,30) if (!check(b)) 
    {
    	puts("NO");
    	return 0;
    }
    puts("YES");
    REP(i,1,n) printf("%d ",a[i]);

	return 0;
}