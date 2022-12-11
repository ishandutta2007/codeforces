#include<bits/stdc++.h>
#define MaxN 200123
typedef long long LL;

char a[MaxN],b[MaxN];
int s[MaxN],t[MaxN];

int main()
{
	int T;scanf("%d",&T);
	while(T-->0)
	{
		int n,p,k,x,y;
		scanf("%d%d%d",&n,&p,&k);
		scanf("%s",a+1);
		scanf("%d%d",&x,&y);
		
		for(int i=1;i<=n;++i)
		if(i-(p-1)>0)b[i-(p-1)]=a[i];
		n-=(p-1);
		
		for(int i=n;i;--i)
		s[i]=s[i+k]+(b[i]-'0'),
		t[i]=t[i+k]+1;
		
		int ans=INT_MAX;
		for(int i=1;i<=n;++i)
		ans=std::min(ans,(i-1)*y+(t[i]-s[i])*x);
		printf("%d\n",ans);
		
		for(int i=1;i<=n;++i)
		a[i]=b[i]=0,s[i]=t[i]=0;
	}
	
	return 0;
}