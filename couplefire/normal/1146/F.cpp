#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 200200
#define MOD 998244353
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,f[MAX][3];
vector<int> E[MAX];
void dfs(int u)
{
	if(E[u].empty())f[u][2]=1;else f[u][0]=1;
	for(int v:E[u])
	{
		dfs(v);
		f[u][2]=(1ll*f[u][2]*(f[v][0]+f[v][2])+1ll*(f[u][1]+f[u][2])*(f[v][1]+f[v][2]))%MOD;
		f[u][1]=(1ll*f[u][1]*(f[v][0]+f[v][2])+1ll*f[u][0]*(f[v][1]+f[v][2]))%MOD;
		f[u][0]=1ll*f[u][0]*(f[v][0]+f[v][2])%MOD;
	}
}
int main()
{
	n=read();
	for(int i=2;i<=n;++i)E[read()].push_back(i);
	dfs(1);printf("%d\n",(f[1][0]+f[1][2])%MOD);
	return 0;	
}