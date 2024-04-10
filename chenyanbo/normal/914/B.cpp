#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,tot,a[1000006],b[1000006];
int main()
{
	n=read();
	
	for(int i=1; i<=n; ++i)a[i]=read();
	sort(a+1,a+n+1);
	b[tot=1]=1;
	for(int i=2; i<=n; ++i)if(a[i]!=a[i-1])
	{
		b[++tot]=1;
	}else ++b[tot];
	for(int i=tot; i>=1; --i)if(b[i]&1)
	{//
		puts("Conan");
		exit(0);//return 0
	}//else 
	
	puts("Agasa");
}