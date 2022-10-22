#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 100000
using namespace std;
int n,m,a[N+5],sum[N+5];
int read()
{
	int x=0,f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') (x*=10)+=ch-'0',ch=getchar();
	return x*=f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+(i%2?a[i]-a[i-1]:0);
	int ans=sum[n+1]=sum[n]+(n%2?0:m-a[n]);
	for(int i=1;i<=n;i++) ans=max(ans,sum[i]+(m-a[i])-(sum[n+1]-sum[i])-1);
	return write(ans),0;
}