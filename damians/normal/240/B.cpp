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
#define CZ(x) fscanf(inf,"%d",&(x));
#define CZ2(x,y) fscanf(inf,"%d%d",&(x),&(y));
#define CZ3(x,y,z) fscanf(inf,"%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }
#define MX 40002
#define INF (1<<28)
int dp[2][202][MX+2];
int h[202];

int main()
{
	FILE *inf=fopen("input.txt","r");
	FILE *outf=fopen("output.txt","w");
	int n;CZ(n);
	int a,b;CZ2(a,b);
	FOR(i,n) CZ(h[i+1]);
	int sum=0;
	REP(i,1,n) sum+=h[i];
	FOR(j,MX+1) dp[0][0][j]=dp[1][0][j]=(j!=0)*INF;
	REP(i,1,n)
	{
		REPD(j,MX,0) dp[0][i][j]=dp[1][i][j]=INF;
		int mn=min(h[i],h[i-1]);
		REPD(j,MX,h[i])
		{
			REMIN(dp[0][i][j],dp[0][i-1][j-h[i]]);
			REMIN(dp[0][i][j],dp[1][i-1][j-h[i]]+mn);
		}
		REPD(j,MX,0)
		{
			REMIN(dp[1][i][j],dp[1][i-1][j]);
			REMIN(dp[1][i][j],dp[0][i-1][j]+mn);
		}
		//DBG(vi(dp[0][i],dp[0][i]+10));
		//DBG(vi(dp[1][i],dp[1][i]+10));
	}
	int best=INF;

	REP(i,0,MX)
	{
		if (i<=a && sum-i<=b) REMIN(best,dp[0][n][i]);
		if (i<=a && sum-i<=b) REMIN(best,dp[1][n][i]);
	}
	if (best<INF) fprintf(outf,"%d\n",best);
	else fprintf(outf,"%d\n",-1);

	
	fclose (inf);
	fclose (outf);
    
    return 0;
}