//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stack>
#include<bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
vector<int>son[100005];
int n,v[100005],s[100005],fa[100005],heavy[100005],f,t,d[100005],MAX[100005],ans[100005];
void init(int now)
{
	int M=0;
	for(int i=0;i<(int)son[now].size();++i)
	{
		if(fa[now]==son[now][i])
		{
			swap(son[now][i],son[now][son[now].size()-1]);
			--i;
			son[now].pop_back();
			continue;
		}
		fa[son[now][i]]=now;
		init(son[now][i]);
		s[now]+=s[son[now][i]];
		if(s[son[now][i]]>s[M])
		{
			M=son[now][i];
		}
	}
	if(M==0)
	{
		M=now;
	}
	heavy[now]=M;
}
void add(int now,int FA)
{
	for(int i=0;i<(int)son[now].size();++i)
	{
		add(son[now][i],FA);
	}
	++d[v[now]];
	if(d[v[now]]>MAX[FA])
	{
		MAX[FA]=d[v[now]];
		ans[FA]=0;
	}
	if(d[v[now]]==MAX[FA])
	{
		ans[FA]+=v[now];
	}
}
void dfs(int now)
{
	for(int i=0;i<(int)son[now].size();++i)
	{
		if(heavy[now]==son[now][i])
		{
			continue;
		}
		dfs(son[now][i]);
		memset(d,0,sizeof(d));
	}
	if(heavy[now]!=now)
	{
		dfs(heavy[now]);
		MAX[now]=MAX[heavy[now]];
		ans[now]=ans[heavy[now]];
	}
	for(int i=0;i<(int)son[now].size();++i)
	{
		if(son[now][i]==heavy[now])
		{
			continue;
		}
		add(son[now][i],now);
	}
	++d[v[now]];
	if(d[v[now]]>MAX[now])
	{
		MAX[now]=d[v[now]];
		ans[now]=0;
	}
	if(d[v[now]]==MAX[now])
	{
		ans[now]+=v[now];
	}
}
void read(int &now)
{
	now=0;
	char c=getchar();
	while('0'>c||c>'9')
	{
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		now=(now<<3)+(now<<1)+(c^'0');
		c=getchar();
	}
}
void wt(int now)
{
	char tmp[20];
	int cnt=0;
	while(now)
	{
		tmp[++cnt]=(now%10)^'0';
		now/=10;
	}
	while(cnt)
	{
		putchar(tmp[cnt--]);
	}
}
signed main()
{
//	std::ios::sync_with_stdio(false);
//	cin>>n;
	read(n);
	for(int i=1;i<=n;++i)
	{
//		cin>>v[i];
		read(v[i]);
		s[i]=1;
	}
	for(int i=1;i<n;++i)
	{
//		cin>>f>>t;
		read(f);
		read(t);
		son[f].push_back(t);
		son[t].push_back(f);
	}
	init(1);
	dfs(1);
	for(int i=1;i<=n;++i)
	{
//		cout<<ans[i]<<' ';
		wt(ans[i]);
		putchar(' ');
	}
//	cout<<endl;
	return 0;
}