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
int t,n,a[N],now,ans[N],tot;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		tot=0;now=0;
		ans[++tot]=a[1];
		for(int i=2;i<=n-1;++i)
			if(a[i]>a[i-1]&&a[i]>a[i+1]||a[i]<a[i-1]&&a[i]<a[i+1])
				ans[++tot]=a[i];
		ans[++tot]=a[n];
		printf("%d\n",tot);
		for(int i=1;i<=tot;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}