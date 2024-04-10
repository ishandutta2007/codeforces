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
//long long , 
//ios_base::sync_with_stdio(false);cin
long long read()
{
	long long res=0;
	bool s=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') s=0;
		c=getchar();
	}
	while(isdigit(c))
	{
		res=(res<<1)+(res<<3)+(c^48);
		c=getchar();
	}
	if(s) return res;
	return (~res)+1;
}
int n,m,u,w;
long long v[200005];
long long s;
vector<int> c[200005];
int clr[200005];
long long sum[2];
bool dfs(int i,int cl=1)
{
	if(clr[i])
	{
		if(cl!=clr[i])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	bool res=1;
	clr[i]=cl;
	sum[cl&1]+=v[i];
	rep(j,c[i].size())
	{
		res&=dfs(c[i][j],3^cl);
	}
	return res;
}
void solve()
{
	n=read();m=read();s=0;rep1(i,n) c[i].clear();rep1(i,n) clr[i]=0;sum[0]=sum[1]=0;rep1(i,n) v[i]=read();rep1(i,n) v[i]=read()-v[i];rep1(i,n) s+=v[i];
	rep(i,m)
	{
		c[u=read()].pb(w=read());
		c[w].pb(u);
	}
	if(s&1) printf("NO\n");
	else if(!dfs(1)||sum[0]==sum[1]) printf("YES\n");
	else printf("NO\n");
}
int t;
int main()
{
	t=read();
	while(t--)
	solve();
	return 0;
}