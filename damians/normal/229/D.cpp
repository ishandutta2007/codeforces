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
#define INF 2000000001
int dp[5005][5005];
int h[6000];
int s[6000];

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
	CZ(n);
//	n=5000;
    REP(i,1,n) CZ(h[i+1]);
    //REP(i,1,n) h[i+1]=1;
    n++;
    REP(i,1,n) s[i]=s[i-1]+h[i];
    REP(p,1,n+1)FOR(k,p+1) dp[p][k]=INF;
    dp[1][0]=h[1];
    REP(p,1,n-1)
    {
		//DBG(h[p]);
		//DBG(vi(dp[p],dp[p]+p+2));
		REP(k,0,p) REMIN(dp[p][k+1],dp[p][k]);
		FOR(k,p+1)
		{
			if (dp[p][k]==INF) continue;
			if (s[n]-s[p]>=dp[p][k])
			{
				int lo=p,hi=n,mid;
				int dd=dp[p][k]+s[p];
				while(hi-lo>1)
				{
					mid=(hi+lo)/2;
					if (s[mid]>=dd) hi=mid;
					else lo=mid;
				}
				REMIN(dp[hi][k+hi-p-1],s[hi]-s[p]);
			}
			
			REMIN(dp[p+1][k+1],dp[p][k]+h[p+1]);
			
		}
	}
	FOR(i,n+2)
	{
		if (dp[n][i]<INF)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 1;
    
    return 0;
}