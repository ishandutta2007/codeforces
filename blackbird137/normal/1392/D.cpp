#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2e5+5;
int t,n,ans,len[N],tot,id[N];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);
		int now=0;
		ans=0;tot=0;
		for(int i=1;i<=n;++i)
		{
			if(now==0||(s[i]=='L'&&now==1||s[i]=='R'&&now==2))
			{
				now=(s[i]=='L'?2:1);
				len[++tot]=1;
				id[tot]=now;
			}
			else len[tot]++;
		}
		int l=1,r=tot;
		if(tot==1)
		{
			if(n>=3)
				ans=ceil(n/3.0);
		}
		else
		{
			if(id[1]==id[tot])
			{
				if(len[1]+len[tot]>=3)
					ans=floor((len[1]+len[tot])/3.0);
				l++,r--;
			}
			for(int i=l;i<=r;++i)
				if(len[i]>=3)
					ans+=floor(len[i]/3.0);	
		}	
		
		printf("%lld\n",ans);
	}
	return 0;
}