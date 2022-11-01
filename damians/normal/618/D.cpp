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
#include <ctime>
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
ll x,y;
int n;
vi kr[1<<20];
int d[1<<20];

int dp1[1<<20];
int dp2[1<<20];

void go(int u,int p)
{
	FOR(i,kr[u].sz)
	{
		if (kr[u][i]==p)
		{
			swap(kr[u][i],kr[u].back());
			kr[u].pop_back();
			break;
		}
	}
	FOR(i,kr[u].sz) go(kr[u][i],u);
	if (kr[u].sz==0) {dp1[u]=dp2[u]=0;return;}
	if (kr[u].sz==1)
	{
		dp1[u]=1+dp1[kr[u][0]];
		dp2[u]=dp1[u];
		return;
	}
	int ile=0;
	int dzieci=kr[u].sz;
	int sum=0;
	FOR(i,kr[u].sz)
	{
		sum+=dp1[kr[u][i]];
		if (dp2[kr[u][i]]>dp1[kr[u][i]]) ile++;
	}
	{
		dp1[u]=1+sum+min(dzieci-1,ile);
	}
	{
		dp2[u]=2+sum+min(dzieci-2,ile);
	}
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>x>>y;
    FOR(i,n-1)
    {
    	int a,b;cin>>a>>b;
    	a--;b--;
    	kr[a].pb(b);
    	kr[b].pb(a);
    	d[a]+=1;
    	d[b]+=1;
    }
    if (x<=y)
    {
    	go(0,-1);
    	cout<<dp2[0]*x+(n-1-dp2[0])*y;
    }
    else
    {
    	int mxdeg=0;
    	FOR(i,n) REMAX(mxdeg,d[i]);
    	if (mxdeg==n-1)
    	{
    		cout<<x+(n-2)*y;
    	}
    	else cout<<(n-1)*y;
    }

	return 0;
}