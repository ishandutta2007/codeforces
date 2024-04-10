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
string s[111];

ll dp[21][1<<20];

#define NEWT 111
long double npok[NEWT+1][NEWT+1];

int pc(ll x)
{
	int w=0;
	while(x)
	{
		w+=x%2;
		x>>=1;
	}
	return w;
}



long double wyn()
{
	FOR(i,m+1)FOR(j,1<<m)dp[i][j]=0;
	FOR(i,n)FOR(j,i)
    {
    	int g=0;
    	FOR(k,m) if (s[i][k]==s[j][k]) g^=(1<<k);
    	
    	if (g)
    	{
    		dp[0][g]|=(1LL<<i);
    		dp[0][g]|=(1LL<<j);
    	}
    }
    REP(l,1,m)
    {
    	int L=l-1;
    	FOR(i,1<<m)
    	{
    		if (!(i&(1<<L)))
    		{
    			dp[l][i]=dp[l-1][i]|dp[l-1][i^(1<<L)];
    		}
    		else dp[l][i]=dp[l-1][i];
    	}
    }
    dp[m][0]=(1LL<<n)-1;
    long double wyn=0;
    FOR(i,1<<m)
    {

    	if (dp[m][i])
    	{
    		wyn+=pc(dp[m][i])*1.0L/n/npok[m][__builtin_popcount(i)];
    	}
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    FOR(n0,NEWT+1)
	{
        npok[n0][0]=npok[n0][n0]=1;
        REP(k0,1,n0-1) npok[n0][k0]=npok[n0-1][k0-1]+npok[n0-1][k0];
    }
    cin>>n;
    FOR(i,n) cin>>s[i];
    if (n==1) {cout<<0;return 0;}
    m=s[0].sz;
    cout<<setprecision(12)<<fixed<<wyn();


	return 0;
}