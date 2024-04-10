#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int qn; 
int mm,cnt,oo,q[250009],k,to[100004],o,a[100004],n,l,r,ll,LL,u,v,U,L;
vector<int>d[100004],to1[100004],to2[100004];
int main()
{///
///
//    freopen("1.in","r",stdin);
   // freopen("1.out","w",stdout);
	n=read(); mm=read();
	for(int i=1; i<=n; ++i)
	{
		a[i]=read();
		for(int j=1; j<=a[i]; ++j)
		{
			o=read();
			d[i].push_back(o);
		}
	}
	for(int i=1; i<n; ++i)
	{
		l=a[i];
		r=a[i+1];
		ll=min(l,r);
		for(k=0; k<ll; ++k)if(d[i][k]!=d[i+1][k])
		{
			u=d[i][k]; v=d[i+1][k];
			if(u>v)
			{
				if(to[u]==2)//_
				{
					puts("No");
					return 0;
				}
				
				if(to[v]==1)
				{
					puts("No");
					return 0;
				}
				
				to[u]=1;  
				to[v]=2;  
				break;
			}
			if(to[u]==2 && to[v]==1)
			{
				puts("No");
				return 0;
			}
			to1[v].push_back(u);
			to2[u].push_back(v);
			break;
		}
		if(k==ll)
		{
			if(l>r)
			{
				puts("No");
				return 0; 
			}
		}
	}
	qn=0;
	for(int i=1; i<=mm; ++i)if(to[i]==1)q[++qn]=i;
		for(int q1=1; q1<=qn; ++q1)  
		{
			u=q[q1];
			oo=to1[u].size();
			for(int j=0; j<oo; ++j)
			{
				v=to1[u][j];
				if(to[v]==2)
				{
					puts("No");
					return 0;
				}
				if(!to[v])
				{
					to[v]=1;
					q[++qn]=v; 
				}
			}
		}
	
	qn=0;
	for(int i=1; i<=mm; ++i)
	{
		if(to[i]==2)q[++qn]=i;
	}
		for(int q1=1; q1<=qn; ++q1)   
		{
			u=q[q1];
			oo=to2[u].size();
			for(int j=0; j<oo; ++j)
			{
				v=to2[u][j];
				if(to[v]==1)
				{
					puts("No");
					return 0; 
				}
				if(!to[v])
				{
					to[v]=2;
					q[++qn]=v; 
				}
			}
		}
	puts("Yes");  
	for(int i=1; i<=mm; ++i)if(to[i]==1)++cnt;
	printf("%d\n",cnt);
	for(int i=1; i<=mm; ++i)if(to[i]==1)printf("%d ",i);
}