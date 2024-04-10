#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
//ios_base::sync_with_stdio(false);cin
int t,n,U,V,X,Y;
ll tot;
bool np[200005];
int p[20005],cnt;
vector<pair<int,int> > fac[200005];
int c[20005];
int mn[20005];
ll val[200005];
bool vis[200005];
ll qkpw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod1;
		a=a*a%mod1;
		b>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return qkpw(x,mod1-2);
}
vector<pair<int,pair<int,int> > >to[200005];
void sieve()
{
    for(int i=2;i<=200000;++i)
    {
    	if(!np[i])
    	{
    		p[cnt]=i;fac[i].pb(mp(cnt++,1));
		}
		for(int j=0;j<cnt;++j)
		{
			int res=i*p[j];
			if(res>200000) break;
			if(i%p[j])
			{
				fac[res]=fac[i];
				fac[res].pb(mp(j,1));
				np[res]=1;
			}
			else
			{
				fac[res]=fac[i];
				++fac[res].back().se;
				np[res]=1;
				break;
			}
		}
	}
}
void dfs(int x,ll v)
{
	if(!vis[x])
	{
	//	cout<<x<<":1";
	//	rep(i,10)
	//	{
	//		if(c[i]>0)
	//		{
	//			cout<<"*"<<p[i]<<"^"<<c[i];
	//		}
	//		if(c[i]<0)
	//		{
	//			cout<<"/"<<p[i]<<"^"<<-c[i];
	//		}
	//	}
	//	cout<<endl;
		vis[x]=1;
		val[x]=v;
		rep(i,to[x].size())
		{
			int u=to[x][i].fi;
			rep(j,fac[to[x][i].se.se].size())
			c[fac[to[x][i].se.se][j].fi]+=fac[to[x][i].se.se][j].se;
			rep(j,fac[to[x][i].se.fi].size())
			{
				c[fac[to[x][i].se.fi][j].fi]-=fac[to[x][i].se.fi][j].se;
				mn[fac[to[x][i].se.fi][j].fi]=min(c[fac[to[x][i].se.fi][j].fi],mn[fac[to[x][i].se.fi][j].fi]);
			}
			dfs(u,v*to[x][i].se.se%mod1*inv(to[x][i].se.fi)%mod1);
			rep(j,fac[to[x][i].se.se].size())
			c[fac[to[x][i].se.se][j].fi]-=fac[to[x][i].se.se][j].se;
			rep(j,fac[to[x][i].se.fi].size())
			c[fac[to[x][i].se.fi][j].fi]+=fac[to[x][i].se.fi][j].se;
		}
	}
}
/*
int c[20005];
int mn[20005];
*/
void Q()
{
	cin>>n;
	rep1(i,n) to[i].clear();
	rep(i,n-1)
	{
		cin>>U>>V>>X>>Y;
		to[U].pb(mp(V,mp(X,Y)));
		to[V].pb(mp(U,mp(Y,X)));
	}
	rep(i,min(n,cnt))
	{
		c[i]=mn[i]=0;
	}
	rep1(i,n) vis[i]=0;
	val[1]=1;
	dfs(1,1);
	tot=0;
	rep1(i,n)
	{
		tot+=val[i];
		if(tot>=mod1) tot-=mod1;
	}
	//cout<<tot<<endl;
	rep(i,cnt)
	{
		if(p[i]<=n)
		{
			tot=(tot*(qkpw(p[i],-mn[i])))%mod1;
		}
		else break;
	}
	cout<<tot<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	sieve();
	while(t--)
	Q();
	return 0; 
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/