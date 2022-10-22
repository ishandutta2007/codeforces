#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
const int MAXN=3e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,pre[MAXN],ptim,suf[MAXN],stim,tag[MAXN],deep[MAXN],ANS[MAXN];
long long ans;
vector<int> node[MAXN];
bool cmp(int x,int y){return tag[x]<tag[y];}
void format(int u,int fa)
{
	deep[u]=deep[fa]+1;
	sort(node[u].begin(),node[u].end(),cmp);
	pre[++ptim]=u;
	for(int i=0;i<node[u].size();++i)
	{
		int v=node[u][i];
		if(v==fa) continue;
		format(v,u);
	}
	suf[++stim]=u;
}
int tmp[MAXN],tim,F;
void fun(int u,int fa,int lim)
{
	++tim;
	if(tmp[u]!=lim+tim) F=1;
	for(int i=0;i<node[u].size();++i)
	{
		int v=node[u][i];
		if(v==fa || tmp[v]<=lim) continue;
		fun(v,u,lim);
	}
}
int check(int phase)
{
	for(int i=1;i<=n;++i) tmp[i]=tag[i];
	int u;
	for(int i=1;i<=n;++i) if(tag[i]==phase) u=i;
	while(1)
	{
		int flag=0;
		for(int i=0;i<node[u].size();++i)
		{
			int v=node[u][i];
			if(deep[v]>deep[u] && tmp[u]<tmp[v]) {swap(tmp[u],tmp[v]),u=v,flag=1;break;}
		}
		if(!flag) break;
	}
	for(int i=1;i<=phase;++i) if(tmp[suf[i]]!=i) return 0;
	fun(1,0,phase);
	if(F) return 0;
	return 1;
}
void print(int u,int fa)
{
	++tim;
	ANS[u]=tim;
	for(int i=0;i<node[u].size();++i)
	{
		int v=node[u][i];
		if(v==fa) continue;
		print(v,u);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) tag[i]=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		node[u].push_back(v);
		node[v].push_back(u);
	}
	format(1,0);
	int cur=tag[1]-1;
	if(!check(cur)) {puts("NO");return 0;}
	puts("YES");
	for(int i=1;i<=n;++i) if(tag[i]<=cur) ans+=deep[i]-1;
	printf("%lld\n",ans);
	tim=0;
	print(1,0);
	for(int i=1;i<=n;++i) printf("%d ",ANS[i]);
	putchar('\n');
	return 0;
}