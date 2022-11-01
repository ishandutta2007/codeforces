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
#define INF 200000000

int a[303][303];
int b[606][303];
int dp[303][303];
int tp[303][303];
int len[606];

int main()
{
    int n;CZ(n);
    FOR(i,n) len[i]=i+1;
    FOR(i,n-1) len[n+i]=n;
    FOR(i,n) FOR(j,n) CZ(a[i][j]);
    FOR(i,n) FOR(j,len[i])
    {
		b[i][j]=a[i-j][j];
	}
	FOR(i,n-1)FOR(j,len[n+i])
	{
		if (n+i-j<n)
		b[n+i][j]=a[n+i-j][j];
		else b[n+i][j]=-1000000;
	}

	dp[0][0]=b[0][0];
	FOR(i,2*n-2)
	{
		FOR(j,len[i+1]) FOR(k,len[i+1]) tp[j][k]=-INF;
		FOR(j,len[i]) FOR(k,len[i])
		{
			REP(j1,j,j+1)REP(k1,k,k+1)
			{
				if (j1<len[i+1] && k1<len[i+1])
				REMAX(tp[j1][k1],dp[j][k]+b[i+1][j1]+(j1!=k1?b[i+1][k1]:0));
			}
		}
		FOR(j,len[i+1]) FOR(k,len[i+1]) 
		{

			dp[j][k]=tp[j][k];
		}
	}
	cout<<dp[n-1][n-1];
    
    return 0;
}