#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n,m,u,v;
int clr[200005];
vector<int> c[200005];
vector<int> ans;
int cnt[2];
void dfs(int vt,int cl=0)
{
	if(clr[vt]==-1)
	{
		clr[vt]=cl;
		++cnt[cl];
		rep(i,c[vt].size())
		{
			dfs(c[vt][i],!cl);
		}
	}
}
void solve()
{
	cin>>n>>m;
	cnt[0]=cnt[1]=0;
	ans.clear();
	rep1(i,n)
	{
		c[i].clear();
		clr[i]=-1;
	}
	rep(i,m)
	{
		cin>>u>>v;
		c[u].pb(v);
		c[v].pb(u);
	}
	dfs(1);
	if(cnt[1]>cnt[0])
	{
		rep1(i,n)
		{
			if(clr[i]==0) ans.pb(i);
		}
	}
	else
	{
		rep1(i,n)
		{
			if(clr[i]==1) ans.pb(i);
		}
	}
	cout<<ans.size()<<endl;
	rep(i,ans.size())
	{
		if(i) cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
}
int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	solve();
	return 0;
}