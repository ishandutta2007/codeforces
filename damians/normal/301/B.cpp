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

int x[222],y[222];

ll a[222];
int kol[222];
int n;
ll d;
ll dp[222];
int cel;
ll dist[222][222];



bool go(ll X)
{
	FOR(i,n) dp[i]=-(1LL<<60);
	dp[0]=X;
	bool change=1;
	while(change)
	{
		//DBG(vector<ll>(dp,dp+n));
		change=0;
		FOR(i,n)
		{
			if (dp[i]>=0)
			{
				//FOR(j,n) DBG(d*(abs(x[i]-x[j])+abs(y[i]-y[j])));
				FOR(j,n) if (i!=j && dp[i]>=d*(abs(x[i]-x[j])+abs(y[i]-y[j])) && dp[j]<dp[i]-d*(abs(x[i]-x[j])+abs(y[i]-y[j]))+a[j])
				{
					dp[j]=dp[i]-d*(abs(x[i]-x[j])+abs(y[i]-y[j]))+a[j];
					change=1;
				}
			}
		}
	}
	return dp[n-1]>=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>d;
    REP(i,1,n-2) cin>>a[i];
    //DBG(vector<ll>(a,a+n));
    FOR(i,n) cin>>x[i]>>y[i];
    //REPD(i,n-1,0) {x[i]-=x[0];y[i]-=y[0];}
	//go(1001);
	//return 0;
    ll lo=-1,mid,hi=1LL<<60;
    while(hi-lo>1)
    {
		mid=(hi+lo)/2;
		if (go(mid)) hi=mid;
		else lo=mid;
	}
	cout<<hi;
    
    
    return 0;
}