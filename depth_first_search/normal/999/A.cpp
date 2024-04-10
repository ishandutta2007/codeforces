#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 100
using namespace std;
int n,k,a[N+5];
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
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int tot=0;
	for(int i=1;i<=n&&k>=a[i];i++) tot++;
	if(tot==n) return write(n),0;
	for(int i=n;i>=1&&k>=a[i];i--) tot++;
	return write(tot),0;
}