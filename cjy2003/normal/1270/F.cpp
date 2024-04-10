#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
using namespace std;
const int t=600;
char s[200020];
int n,cnt[400040],sum[200020];
long long ans;
int p[200020],num;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(s[i]=='1');
	for(int i=1;i<=t;++i)
		for(int j=0;j<i;++j)
		{
			for(int k=j,l=0;k<=n;k+=i,++l)ans+=cnt[sum[k]-l+200000]++;
			for(int k=j,l=0;k<=n;k+=i,++l)--cnt[sum[k]-l+200000];
		}
	for(int i=1;i<=n;++i)if(s[i]=='1')p[++num]=i;p[num+1]=n+1;
	int pos=0;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='1')++pos;
		for(int j=1,l,r;j<=n/t&&pos+j<=num;++j)
		{
			l=(p[pos+j]-i-1)/j,r=(p[pos+j+1]-i-1)/j;
		//	printf("%d %d\n",l,r);
			if(l<t)l=t;
			if(l<r)ans+=r-l;
		}
	}
	printf("%lld\n",ans);
//	cerr<<t<<':'<<clock();
	return 0;
}