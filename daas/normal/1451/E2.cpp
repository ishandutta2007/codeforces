#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int x;
	scanf("%d",&x);
	return x;
}
int n,a[70000],v[70000],id[70000];
int main()
{
	n=read();
	for(int i=2;i<=n;++i)
	{
		printf("XOR %d %d\n",1,i);
		fflush(stdout);
		v[i]=read();
	}
	for(int i=1;i<=n;++i)
	{
		if(id[v[i]])
		{
			printf("AND %d %d\n",id[v[i]],i);
			fflush(stdout);
			a[i]=read();
			a[1]=a[i]^v[i];
			for(int j=2;j<=n;++j)
				a[j]=a[1]^v[j];
			putchar('!');
			for(int j=1;j<=n;++j)
				printf(" %d",a[j]);
			putchar('\n');
			fflush(stdout);
			return 0;
		}
		id[v[i]]=i;
	}
	for(int i=2;i<=n;++i)
		if(v[i]==1)
		{
			printf("AND %d %d\n",1,i);
			fflush(stdout);
			int V=read();
			for(int j=2;j<=n;++j)
				if(j!=i && (v[j]&1))
				{
					printf("AND %d %d\n",i,j);
					fflush(stdout);
					int w=read();
					if(w&1)
						a[1]=V;
					else
						a[1]=V+1;
					for(int k=2;k<=n;++k)
						a[k]=a[1]^v[k];
					putchar('!');
					for(int k=1;k<=n;++k)
						printf(" %d",a[k]);
					putchar('\n');
					fflush(stdout);
					return 0;
				}
		}
	return 0;
}