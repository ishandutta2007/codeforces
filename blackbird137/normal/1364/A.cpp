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
int t,n,k,a[N],pre[N],suc[N],ans,now,len;

int main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		memset(pre,0,sizeof(pre));
		memset(suc,0,sizeof(suc));
		for(int i=1;i<=n;++i)
			pre[i]=pre[i-1]+a[i];
		for(int i=n;i>=1;--i)
			suc[i]=suc[i+1]+a[i];
		ans=-1;now=pre[n],len=n;
		if(now%k!=0) ans=len;
		for(int i=1;i<=n;++i)
			if((now-pre[i])%k!=0)
				ans=max(ans,n-i);
			else if((now-suc[i])%k!=0)
				ans=max(ans,i-1);
		printf("%d\n",ans);
	}
	return 0;
}