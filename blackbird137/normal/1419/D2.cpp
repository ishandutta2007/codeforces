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

const int N=1e5+5;
int n,a[N],b[N],m,ans;

signed main()
{
	//("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=(n>>1);++i)
	{
		b[++m]=a[i+(n>>1)];
		b[++m]=a[i];
	}
	if(n%2==1) b[++m]=a[n];
	for(int i=2;i<=n-1;++i)
		if(b[i]<b[i-1]&&b[i]<b[i+1])
			ans++;
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i)
		printf("%lld ",b[i]);
	return 0;
}