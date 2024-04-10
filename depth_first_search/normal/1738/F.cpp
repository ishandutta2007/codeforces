// LUOGU_RID: 90608904
#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 1000
using namespace std;
int n,d[N+5],id[N+5],f[N+5],g[N+5],vis[N+5];
int fa(int x) {return f[x]?f[x]=fa(f[x]):x;}
int main()
{
	int Tt,i,j,x,k;scanf("%d",&Tt);while(Tt--)
	{
		for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",d+i),id[i]=i,vis[i]=f[i]=0,g[i]=1;
		sort(id+1,id+n+1,[&](int x,int y){return d[x]>d[y];});
		for(i=1;i<=n;++i) for(vis[k=id[i]]=1;!f[k]&&g[k]<d[k];)
		{
			printf("? %d\n",k),fflush(stdout),scanf("%d",&x);
			if(vis[x]) {f[k]=fa(x);break;}vis[x]=1,++g[f[x]=k];
		}
		for(printf("! "),i=1;i<=n;++i) printf("%d%c",fa(i)," \n"[i==n]);fflush(stdout);
	}return 0;
}