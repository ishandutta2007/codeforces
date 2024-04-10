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

#define NEWT 203
#define MOD 1000000007
ll npok[NEWT+1][NEWT+1];
int a[10];
ll dp[102][11];

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(n0,NEWT+1)
	{
        npok[n0][0]=npok[n0][n0]=1;
        REP(k0,1,n0-1) npok[n0][k0]=npok[n0-1][k0-1]+npok[n0-1][k0];
        REP(k0,1,n0-1) if (npok[n0][k0]>=MOD) npok[n0][k0]-=MOD;
    }
    int n;cin>>n;
    FOR(i,10)
    {
		cin>>a[9-i];
	}
	dp[0][0]=1;
	REP(i,1,10) REP(j,0,100)
	{
		REP(w,a[i-1],100)
		{
			if (w>j) continue;
			if (i<10) dp[j][i]=(dp[j][i]+dp[j-w][i-1]*npok[j][w])%MOD;
			else if (j-w) dp[j][i]=(dp[j][i]+dp[j-w][i-1]*npok[j-1][w])%MOD;
		}
	}
	ll wyn=0;
	REP(j,1,n) wyn+=dp[j][10];

	cout<<wyn%MOD;

    return 0;
}