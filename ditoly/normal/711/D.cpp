#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do c=getchar();while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#include<vector>
using namespace std;
#define MAXN 200000
#define MOD 1000000007
vector<int> v[MAXN+5];
int f[MAXN+5],fn,u[MAXN+5],ans=1,k;
void dfs(int x,int fa)
{
	f[x]=++fn;u[x]=1;
	int i,j,y,o=1,p;
	for(i=0;i<v[x].size();i++)
	{
		y=v[x][i];
		if(y==fa&&o){o=0;continue;}
		if(u[y])
		{
			for(p=0,j=0;j<f[x]-f[y];j++)p=(p*2+2)%MOD;
			ans=(long long)ans*p%MOD;k+=f[x]-f[y]+1;
		}
		else if(!f[y])dfs(y,x);
	}
	fn--;u[x]=0;
}
int main()
{
	int n,i,x;
	read(n);
	for(i=1;i<=n;i++)
	{
		read(x);
		v[i].push_back(x);
		v[x].push_back(i);
	}
	for(i=1;i<=n;i++)if(!f[i])dfs(i,fn=0);
	for(;k<n;k++){ans<<=1;ans%=MOD;}
	printf("%d",ans);
}