#include<bits/stdc++.h>
#define MaxN 200123
int n,k,cnt;
char s[MaxN];
int dfn[MaxN];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int tmp=(n-k)/2;
	std::stack<int>stk;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')
		{
			stk.push(i);
			dfn[i]=++cnt;
		}
		else
		{
			int tp=stk.top();
			stk.pop();
			dfn[i]=dfn[tp];
		}
	}
	for(int i=1;i<=n;++i)
	if(dfn[i]>tmp)putchar(s[i]);
	return 0;
}