#include<bits/stdc++.h>
#define N 400060
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int op,ans,q,fa[N][19],cnt;
long long p,f[N][19],ma[N][19],x;
int main()
{
	q=read(); ans=0; 
	f[1][0]=0;
	fa[1][0]=0;
	ma[1][0]=0;
	cnt=1;
	while(q--)
	{
		if(!q)
		int hhh=0;
		op=read(); scanf("%I64d%I64d",&p,&x);  //d p
		p^=ans; x^=ans;
		if(op==1)
		{
			++cnt;
			for(int i=18; i>=0; --i)if(ma[p][i]<x&&fa[p][i]!=0)p=fa[p][i];
			if(f[p][0]<x){
				for(int i=0; i<=18; ++i)
				{
				    f[cnt][i]=x;
				    fa[cnt][i]=0;
				    ma[cnt][i]=x;
				}
			} else
			{
				f[cnt][0]=x;
				fa[cnt][0]=p;
				ma[cnt][0]=x;
				for(int i=1; i<=18; ++i)
				{
					f[cnt][i]=f[cnt][i-1]+f[fa[cnt][i-1]][i-1];
					fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
					ma[cnt][i]=max(ma[cnt][i-1],ma[fa[cnt][i-1]][i-1]);
				}
			}
			continue;
		}
		ans=0;
		for(int i=18; i>=0; --i)if(fa[p][i])
		{
			if(f[p][i]<=x){
				ans+=1<<i;
				x-=f[p][i];
				p=fa[p][i];
				
			} 
		}
		if(f[p][0]<=x)++ans;
		printf("%d\n",ans);
	}
}