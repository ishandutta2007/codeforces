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

vi v;
int dp[5005][5005];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;cin>>n;
    int m;cin>>m;
    double syf;
    FOR(i,n)
    {
		int x;cin>>x>>syf;
		v.pb(x);
	}
	FOR(i,n+3)FOR(j,n+3) dp[i][j]=1<<30;
	FOR(i,n+1) dp[m+1][i]=0;
	REPD(s,m,1)
	{
		dp[s][n]=0;
		int ile=0;
		REPD(i,n-1,0)
		{
			if (v[i]<s) dp[s][i]=dp[s][i+1];
			else
			{
				if (v[i]==s) {dp[s][i]=dp[s][i+1];ile++;}
				else
				{
					dp[s][i]=dp[s][i+1]+1;
					REMIN(dp[s][i],dp[s+1][i]+ile);
				}
			}
		}
	}
	cout<<dp[1][0];
    
    return 0;
}