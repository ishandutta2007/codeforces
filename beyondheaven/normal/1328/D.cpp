#include<bits/stdc++.h>
#define MaxN 200123
int q,n;
int t[MaxN],ans[MaxN];
std::set<int>s;
inline void Solve()
{
	scanf("%d",&n);
	s.clear();
	for(int i=1;i<=n;++i)scanf("%d",t+i);
	for(int i=1;i<=n;++i)s.insert(t[i]);
	if(s.size()==1)
	{
		puts("1");
		for(int i=1;i<=n;++i)
		printf("1%c"," \n"[i==n]);
		return;
	}
	else if(s.size()==2)
	{
		puts("2");
		ans[1]=1;
		for(int i=2;i<=n;++i)
		ans[i]=(t[i]==t[i-1]?ans[i-1]:3-ans[i-1]);
		for(int i=1;i<=n;++i)
		printf("%d%c",ans[i]," \n"[i==n]);
		return;
	}
	else if(n%2==0)
	{
		puts("2");
		for(int i=1;i<=n;++i)
		printf("%d%c",2-i%2," \n"[i==n]);
		return;
	}
	else
	{
		if(t[n]==t[1])
		{
			puts("2");
			for(int i=1;i<=n;++i)
			printf("%d%c",(i-1)%2+1," \n"[i==n]);
			return;
		}
		int pos=0;
		for(int i=1;i<=n;++i)
		if(t[i]==t[i-1])
		{
			pos=i;break;
		}
		if(!pos)
		{
			puts("3");
			for(int i=1;i<=n;++i)
			ans[i]=(i-1)%3+1;
			if(ans[n]==1)ans[n]=2;
		}
		else
		{
			puts("2");
			for(int i=1;i<=n;++i)
			if(i==pos)ans[i]=ans[i-1];
			else ans[i]=(ans[i-1]==1?2:1);
		}
		for(int i=1;i<=n;++i)
		printf("%d%c",ans[i]," \n"[i==n]);
	}
}
int main()
{
	scanf("%d",&q);
	while(q--)Solve();
	return 0;
}