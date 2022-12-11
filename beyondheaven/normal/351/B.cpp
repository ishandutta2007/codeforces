#include<bits/stdc++.h>
#define MaxN 3123
int n,p[MaxN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",p+i);
	
	int ans=0;
	for(int i=1;i<=n;++i)
	for(int j=i+1;j<=n;++j)
	if(p[i]>p[j])++ans;
	
	if(ans&1)printf("%d\n",2*ans-1);
	else printf("%d\n",2*ans);
	
	return 0;
}