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
#define LL long long

using namespace std;

LL read()
{
	LL ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const LL N=1e6+5;
LL t,n,sum,fi[N],ans,mmax;
char s[N];

int main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		sum=0;ans=0;mmax=0;
		memset(fi,-1,sizeof(fi));
		for(LL i=1;i<=n;++i)
		{
			if(sum>=0&&fi[sum]==-1)
				fi[sum]=i-1;
			if(s[i]=='-') sum++,mmax=max(mmax,sum);
			else sum--;
			
		}
		if(sum>=0&&fi[sum]==-1)
			fi[sum]=n;
		for(LL i=0;i<=mmax;++i)
			ans+=fi[i];
		printf("%lld\n",ans+n);
	}
	return 0;
}