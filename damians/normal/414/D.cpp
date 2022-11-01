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
#define LOLDBG1
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

vi kr[111111];
int l[111111];
ll ss[111111];
ll sss[111111];

void dfs(int u,int p,int h)
{
	l[h]++;
	FORE(it,kr[u])
	{
		if (*it!=p) dfs(*it,u,h+1);
	}
}

int n,k,p;

bool dasie(int f)
{
	int h0=0,h1=0,ile=1;
	
	while(1)
	{
		ile-=l[h0];
		h0++;
		//DBG(h0);
		//DBG(ile);
		while(h1<h0 || ile<f)
		{
			h1++;
			ile+=l[h1];
			if (h1>n+2) return 0;
		}
		//DBG(ile);
		//DBG(h1);
		int mam=0;
		ll sum=0;
		ll sum1=sss[h1]-sss[h0]-ss[h0-1]*(h1-h0);
		sum=sum1;
		int zle=min(l[h0],ile-f);
		sum-=(h1-h0)*1LL*zle;
		if (sum<=p) return 1;
	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    CZ3(n,k,p);
    FOR(i,n-1)
    {
		int a,b;
		CZ2(a,b);a--;b--;
		kr[a].pb(b);
		kr[b].pb(a);
	}
	dfs(0,0,0);
	ss[0]=0;
	sss[0]=0;
	DBG(vi(l,l+n));
	REP(i,1,n)
	{
		ss[i]=ss[i-1]+l[i];
		sss[i]=sss[i-1]+ss[i-1];
	}
	int lo=0,hi=min(k,n-1)+1,mid;
	//DBG(dasie(5));
	//return 0;
	while(hi-lo>1)
	{
		mid=(hi+lo)/2;
		if (dasie(mid)) lo=mid;
		else hi=mid;
	}
	cout<<lo;
    
    return 0;
}