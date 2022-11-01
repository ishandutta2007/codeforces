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

char s[101][20002];

int x[101][10002];

int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;CZ2(n,m);
    FOR(i,n) scanf("%s",s[i]);
    FOR(i,n)
    {
		bool ok=0;
		FOR(j,m) if (s[i][j]=='1') ok=1;
		FOR(j,m) s[i][j+m]=s[i][j];
		if (!ok)
		{
			puts("-1");
			return 0;
		}
	}
	FOR(i,n)
	{
		FOR(j,m) x[i][j]=m+2;
		int last=-1;
		FOR(j,2*m)
		{
			if (s[i][j]=='1') last=j;
			if (last!=-1) REMIN(x[i][j%m],abs(last-j));
			
		}
		last=-1;
		REPD(j,2*m-1,0)
		{
			if (s[i][j]=='1') last=j;
			if (last!=-1) REMIN(x[i][j%m],abs(last-j));
			
		}
	}
	int best=1<<30;
	FOR(j,m)
	{
		int su=0;
		FOR(i,n) su+=x[i][j];
		REMIN(best,su);
	}
	cout<<best;
	
	
    
    return 0;
}