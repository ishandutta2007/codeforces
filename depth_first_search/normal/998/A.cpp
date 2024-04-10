#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 10
using namespace std;
int n,a[N+5],s[N+5];
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
	for(int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	if(n==1||(n==2&&a[1]==a[2])) return puts("-1");
	for(int i=1;i<=n;i++) if(a[i]!=s[n]-a[i]) return puts("1"),write(i),0;
	return 0;
}