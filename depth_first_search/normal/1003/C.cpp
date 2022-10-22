#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 5000
using namespace std;
int n,m,sum[N+5];
double ans;
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
	for(int i=1;i<=n;i++) {sum[i]=sum[i-1]+read();for(int j=m;j<=i;j++) ans=max(ans,(double)(sum[i]-sum[i-j])/j);}
	return printf("%.15lf",ans),0;
}