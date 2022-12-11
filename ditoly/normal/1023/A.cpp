#include<bits/stdc++.h>
using namespace std;
#define MN 200000
char s[MN+5],t[MN+5];
int main()
{
	int n,m,i,j;
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	for(i=1;i<=n;++i)if(s[i]=='*')
	{
		if(n-1>m)return 0*puts("NO");
		for(j=1;j<i;++j)if(s[j]!=t[j])return 0*puts("NO");
		for(j=n;j>i;--j)if(s[j]!=t[m-n+j])return 0*puts("NO");
		return 0*puts("YES");
	}
	if(n!=m)return 0*puts("NO");
	for(i=1;i<=n;++i)if(s[i]!=t[i])return 0*puts("NO");
	puts("YES");
}