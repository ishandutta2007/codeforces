#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 300000
int a[MN+5],s[MN+5];
int main()
{
	int n,k,i,j,l,r,mid,ans;
	n=read();k=read();
	for(i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(l=0,r=1e9;l<=r;)
	{
		mid=l+r>>1;
		for(i=s[0]=1;i<=n;++i)
		{
			j=lower_bound(a+1,a+n+1,a[i]-mid)-a;
			if(j-1<=i-k)s[i]=s[i-1]+(s[i-k]>s[j-2]);else s[i]=s[i-1];
		}
		if(s[n]>s[n-1])ans=mid,r=mid-1;else l=mid+1;
	}
	printf("%d",ans);
}