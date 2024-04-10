#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
#define lowbit(k) (k&-k)
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,ans;
char s[100001];
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s",s);
		ans=0;
		for(int i=1;i<n;++i)
			if(s[i-1]!=s[i])
				++ans;
		ans=n-1-ans;
		printf("%lld\n",ans/2+ans%2);
	}
	return 0;
}