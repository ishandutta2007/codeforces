#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 100
using namespace std;
int n,a[N+5];
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
	n=read();
	for(int i=1;i<=n/2;i++) a[i]=read();
	sort(a+1,a+n/2+1);
	int ans=0,tot=0;
	for(int i=1;i<=n/2;i++) ans+=abs(a[i]-i*2+1),tot+=abs(a[i]-i*2);
	ans=min(ans,tot);
	write(ans);
	return 0;
}