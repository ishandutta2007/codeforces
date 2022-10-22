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

const int N=50;
int t,n,k,a[N],b[N],ans;

int main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			b[i]=read();
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(int i=1;i<=k;++i)
			if(a[i]<b[n-i+1])
				swap(a[i],b[n-i+1]);
		ans=0;
		for(int i=1;i<=n;++i)
			ans+=a[i];
		printf("%d\n",ans);
	}
	return 0;
}