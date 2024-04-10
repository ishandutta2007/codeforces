#include<bits/stdc++.h>
#define N 1005
#define M 10005
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

long long w_,f[N][M];
int wqy,co[N],c[N],g[N][M],n,w,b,x,d[N][M];
int main()
{
	n=read(); w=read(); b=read(); x=read();
	for(int i=1; i<=n; ++i)c[i]=read();
	for(int i=1; i<=n; ++i)co[i]=read();
	f[0][0]=w; g[0][0]=1; d[0][0]=0; 
	for(int i=1; i<=n; ++i) 
	{
		if(!c[i])
		{
			for(int j=0; j<=wqy; ++j){
			    if(!g[i-1][j])break;
				f[i][j]=min(f[i-1][j]+x,(long long)b*j+w);
				d[i][j]=0;
				g[i][j]=1;
			}
			continue;
		}
		f[i][0]=w; wqy+=c[i]; g[i][0]=1; d[i][0]=0;
		for(int j=1; j<=wqy; ++j){
			
			if(i==2 && j==10)
			int cyb=5;
			
			if(!g[i][j-1])break;
			
			if(d[i][j-1]==c[i]){
				if(g[i-1][j-c[i]]){
					w_=f[i-1][j-c[i]]+x;
					w_=min(w_,(long long)b*(j-c[i])+w);
					if(w_>=(long long)co[i]*c[i])
					{
					    f[i][j]=w_-(long long)co[i]*c[i];
					    d[i][j]=c[i];
					    g[i][j]=1;
					}   
				}
			}
			else
			{
				if(f[i][j-1]>=co[i]){
					f[i][j]=f[i][j-1]-co[i];
					d[i][j]=d[i][j-1]+1;
					g[i][j]=1;
				}
			}
			
			if(!g[i-1][j-1])continue;
			w_=f[i-1][j-1]+x;
			w_=min(w_,(long long)b*(j-1)+w);
			if(w_>=co[i])
			{
				if(!g[i][j])
				{
				    f[i][j]=w_-co[i];
				    d[i][j]=1;
				    g[i][j]=1;
				}
				else if(w_-co[i]>=f[i][j])
				{
					f[i][j]=w_-co[i];
				    d[i][j]=1;
				    g[i][j]=1;
				}
			} 
			
			if(!g[i-1][j])continue;
			w_=f[i-1][j]+x;
			w_=min(w_,(long long)b*j+w);
			if(!g[i][j])
			{
				f[i][j]=w_;
				d[i][j]=0;
				g[i][j]=1;
			}
			else if(w_>=f[i][j])
			{
				f[i][j]=w_;
				d[i][j]=0;
				g[i][j]=1;
			}
		}
	}
	for(int i=wqy; i>=0; --i)if(g[n][i]){
		printf("%d\n",i);
		exit(0);
	}
}