#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 100
#define M 100
using namespace std;
int n,m,a[N+5],s[N+5],w[N+5];
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
	for(int i=1;i<=n;i++) a[i]=read(),s[i]=s[i-1]+(a[i]&1);
	int k=0,tot=0;
	for(int i=2;i<n;i+=2) if(s[i]*2==i) w[++k]=abs(a[i+1]-a[i]);
	sort(w+1,w+k+1);
	for(int i=1,x=0;i<=k&&(x+=w[i])<=m;i++,tot++); 
	return write(tot),0;
}