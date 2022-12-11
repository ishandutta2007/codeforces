#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#include<algorithm>
using namespace std;
#define MAXN 200000
int a[MAXN+5];
int main()
{
	int n,s,i,ans=0,r,u=0,k=0;
	n=read();s=read()-1;
	for(i=0;i<n;i++)a[i]=read();
	if(a[s])k++;a[s]=0;
	for(i=0;i<n;i++)if(i!=s&&!a[i])a[i]=n,u++;
	sort(a,a+n);
	for(i=1;i<n-ans;i++)if(a[i]-a[i-1]>1)
		if(n-ans-i<a[i]-a[i-1]-1)ans+=n-ans-i;
		else ans+=a[i]-a[i-1]-1;
	if(ans<u)ans=u;
	printf("%d",ans+k);
}