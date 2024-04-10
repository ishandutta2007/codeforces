#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,a[MAXN],b[MAXN],ins[MAXN][2],ton[MAXN],dl[MAXN],h,t,father[MAXN];
ll val[MAXN];
vector<int> mem[MAXN];
int find(int k)
{
	if(father[k]!=k) father[k]=find(father[k]);
	return father[k];
}
void solve(int l,int r)
{
	for(int i=find(l-1);i<=r;i=find(i))
	{
		val[i]=0;
		father[i]=i+1;
		for(int j=0;j<(int)mem[i].size();++j)
		{
			++ton[mem[i][j]];
			if(ton[mem[i][j]]==2) dl[++t]=mem[i][j];
		}
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) b[i]=read();
		for(int i=1;i<=n;++i)
		{
			val[i]=val[i-1]+a[i]-b[i];
			mem[i].clear();
			if(val[i]) father[i]=i;
			else father[i]=i+1;
		}
		father[n+1]=n+1;
		father[0]=1;
		for(int i=1;i<=m;++i)
		{
			ins[i][0]=read(),ins[i][1]=read();
			ton[i]=(val[ins[i][0]-1]==0)+(val[ins[i][1]]==0);
			if(ton[i]==2) dl[++t]=i;
			else
			{
				if(val[ins[i][0]-1]) mem[ins[i][0]-1].push_back(i);
				if(val[ins[i][1]]) mem[ins[i][1]].push_back(i);
			}
		}
		while(h!=t)
		{
			int u=dl[++h];
			solve(ins[u][0],ins[u][1]);
		}
		int flag=1;
		for(int i=1;i<=n;++i) if(val[i]) flag=0;
		puts(flag?"YES":"NO");
	}
	return 0;
}
//ore no turn,draw!