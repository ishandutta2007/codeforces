#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 5000
char s[MN+5],c;
int u[MN+5];
int main()
{
	int n,l,i,j,k;
	scanf("%s",s+1);n=strlen(s+1);
	for(l=0,i=1;i<=n;++l,i*=2);--l; 
	for(u[0]=i=1;i<=n-(1<<l)+1;++i)
	{
		for(j=0,c='z';j<1<<l;++j)if(u[j])
			for(c=min(c,s[i+j]),k=0;k<l;++k)u[j|(1<<k)]=1;
		putchar(c);
		for(j=0;j<1<<l;++j)u[j]&=s[i+j]==c;
	}
}