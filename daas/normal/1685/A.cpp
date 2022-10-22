#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[100010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		if(n%2) {puts("NO");continue;}
		sort(a+1,a+n+1);
		int maxn=0,bj;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r+1<=n && a[r+1]==a[r]) ++r;
			if(r-l+1>maxn)
			{
				maxn=r-l+1;
				bj=a[l];
			}
		}
		if(maxn>n/2) {puts("NO");continue;}
		if(maxn==n/2)
		{
			if(bj==a[1] || bj==a[n])
			{
				puts("YES");
				for(int i=1;i<=n;++i) if(a[i]!=bj) printf("%d %d ",a[i],bj);
				putchar('\n');
			}
			else puts("NO");
			continue;
		}
		puts("YES");
		for(int i=1;i<=n/2;++i) printf("%d %d ",a[i],a[n/2+i]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!