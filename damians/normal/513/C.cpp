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

int l[66],r[66];
int d[66];

double get(int a,int b,int c,int d)
{
	if (a>b || c>d) return 0;
	a=max(a,c);
	b=min(b,d);
	if (a<=b) return (b-a+1);
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
	int n;cin>>n;
	FOR(i,n)cin>>l[i]>>r[i];
	FOR(i,n)d[i]=r[i]-l[i]+1;
	int mx=10000;
	double res=0;
	FOR(w,n) FOR(s,n)
	{
		if (w==s) continue;
		REP(k,l[s],r[s])
		{
			double pro=1.0/d[s];
			if (w<s) pro*=get(l[w],r[w],k,r[w])/d[w];
			else pro*=get(l[w],r[w],k+1,r[w])/d[w];
			FOR(i,n)
			{
				if (w==i || s==i) continue;
				int mx;
				if (i<s) mx=k-1;
				else mx=k;
				pro*=get(l[i],mx,l[i],r[i])/d[i];
			}
			/*if (pro>0)
			{
				DBG(w);
				DBG(s);
				DBG(k);
				DBG(pro);
			}*/
			res+=pro*k;
		}
	}
	cout<<setprecision(12)<<fixed<<res;
	return 0;
}