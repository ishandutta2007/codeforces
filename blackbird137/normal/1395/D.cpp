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

const int N=4e5+5;
int n,d,m,a[N],b[N],tot1,tot2,ans;

bool cmp(int a,int b)
{
	return a>b;
}

signed main()
{
	n=read();d=read();m=read();
	for(int i=1;i<=n;++i)
	{
		int x=read();
		if(x>m) a[++tot1]=x;
		else b[++tot2]=x;
	}
	if(tot1==0)
	{
		for(int i=1;i<=tot2;++i)
			ans+=b[i];
		printf("%lld\n",ans);
		return 0;
	}
	sort(a+1,a+1+tot1,cmp);
	sort(b+1,b+1+tot2,cmp);
	for(int i=1;i<=tot1;++i)
		a[i]+=a[i-1];
	for(int i=1;i<=tot2;++i)
		b[i]+=b[i-1];
	for(int i=tot2+1;i<=n;++i)
		b[i]=b[tot2];
	for(int i=(tot1+d)/(d+1);i<=tot1;++i)
		if((i-1)*(d+1)+1<=n)
			ans=max(ans,a[i]+b[n-(i-1)*(d+1)-1]);
	printf("%lld\n",ans);
	return 0;
}