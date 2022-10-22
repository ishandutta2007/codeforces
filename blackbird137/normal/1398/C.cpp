#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

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

const int N=1e5+5;
int t,n,a[N],sum[N],now,ans;
char s[N];

map<int,int> mp;

signed main()
{
	t=read();
	while(t--)
	{
		mp.clear();
		n=read();
		scanf("%s",s+1);
		sum[0]=0;
		for(int i=1;i<=n;++i)
		{
			sum[i]=sum[i-1]+s[i]-'0';
			mp[sum[i]-i]++;
		}
		now=ans=0;
		for(int i=1;i<=n;++i)
		{
			ans+=mp[now];
			mp[sum[i]-i]--;
			now+=s[i]-'0'-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}