#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define N 150
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int f[N],n,u,v,tot,c[100050],d[100050];
char s[100050],p[100050];
int fid(int p)
{
	if(f[p]==p)return p;
	return f[p]=fid(f[p]);
}

int main()
{
	n=read();
	scanf("%s",s+1);
	scanf("%s",p+1);//strlen On
	for(int i=97; i<=122; ++i)f[i]=i;
	for(int i=1; i<=n; ++i)
	{
		//find fin
		//std::max  max       namespace nei//youxian nei bianlinag   hanshu //a a[] //0
		u=fid(s[i]);
		v=fid(p[i]);
		if(u!=v){
			c[++tot]=u;
			d[tot]=v;
			f[u]=v;
		}
	}
	printf("%d\n",tot);  //printf   "" "\n"
	for(int i=1; i<=tot; ++i)printf("%c %c\n",c[i],d[i]);
}//set map  vector  //hanshuzhong// nameapce nei //0?
//array arr