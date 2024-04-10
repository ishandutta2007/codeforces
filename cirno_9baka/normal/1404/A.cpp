#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,k,i,s[N],p[N],ans[N],t,s1;
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		scanf("%s",c+1);
		for(i=0;i<=k;++i)
			p[i]=-1;
		for(i=1;i<=n;++i)
			if(c[i]=='1')
				p[i%k]=1;
			else
				if(c[i]=='0')
					p[i%k]=0;
		for(i=1;i<=n;++i)
			ans[i]=-1;
		for(i=1;i<=n;++i)
			if(p[i%k]!=-1)
				ans[i]=p[i%k];
		s1=0;
		for(i=1;i<=k;++i)
			if(ans[i]==1)
				++s1;
		for(i=1;i<=k;++i)
			if(ans[i]==-1)
				if(s1<k/2)
				{
					ans[i]=1;
					++s1;
				}
				else
					ans[i]=0;
		if(s1!=k/2)
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n;++i)
		{
			if(i>k)
				ans[i]=ans[i-k];
			if(ans[i]!=c[i]-'0'&&c[i]!='?')
				break;
		}
		if(i<=n)
			puts("NO");
		else
			puts("YES");
	}
}