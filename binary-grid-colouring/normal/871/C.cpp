#include<bits/stdc++.h>
using namespace std;
const int N = 234567;
const int mod = 1e9+7;
int n;
int totx,toty;
map<int,int>X,Y;
int head[N<<1];
int tot;
struct edge
{
	int next,to;
}e[N<<3];
void add(int u,int v)
{
	e[++tot]=(edge){head[u],v};
	head[u]=tot;
	e[++tot]=(edge){head[v],u};
	head[v]=tot;
}
int xx[N],yy[N];
bool vis[N<<1];
int ans=1;
int cnt;
int tmp;
void dfs(int x)
{
	cnt++;
	vis[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		if(!vis[e[i].to])
		{
			dfs(e[i].to);
		}
		tmp++;
	}
}
int pw[N]={1};
int main()
{
	cin >> n;
	for(int i=1;i<=2*n;i++){
		pw[i] = 2*pw[i-1]%mod;
	}
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> y;
		if(!X[x])
		{
			X[x] = (++totx);	
		}
		if(!Y[y])
		{
			Y[y] = (++toty);
		}
		xx[i] = X[x];
		yy[i] = Y[y];
	}
	for(int i=1;i<=n;i++)
	{
		add(xx[i],totx+yy[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt = 0;
			tmp = 0;
			dfs(i);
			bool flag = (tmp<=2*cnt-2);
			ans = 1LL*ans*(pw[cnt]-flag)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}