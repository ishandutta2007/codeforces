#include<bits/stdc++.h>
#define MaxN 200123
int n,m;
char S[MaxN],T[MaxN];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s",S+1,T+1);
	if(n-1>m)
	{
		puts("NO");
		return 0;
	}
	bool flag=false;
	for(int i=1;i<=n;++i)
	if(S[i]=='*')flag=true;
	if(!flag)
	{
		if(n!=m)
		{
			puts("NO");
			return 0;
		}
		for(int i=1;i<=n;++i)
		if(S[i]!=T[i])
		{
			puts("NO");
			return 0; 
		}
		puts("YES");
		return 0;
	}
	for(int i=1;S[i]!='*';++i)
	if(S[i]!=T[i])
	{
		puts("NO");
		return 0;
	}
	for(int i=1;S[n-i+1]!='*';++i)
	if(S[n-i+1]!=T[m-i+1])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}