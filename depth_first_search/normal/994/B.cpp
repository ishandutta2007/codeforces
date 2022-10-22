#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 100000
#define M 10
using namespace std;
int n,m,s[M+5]={0};
LL ans[N+5];
struct knight
{
	int power,coin,pos;
}a[N+5];
int read()
{
	int x=0,f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(ch>='0'&&ch<='9') (x*=10)+=ch-'0',ch=getchar();
	return x*=f;
}
void write(LL x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool cmp(knight x,knight y) {return x.power<y.power;}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[a[i].pos=i].power=read();
	for(int i=1;i<=n;i++) a[i].coin=read();
	sort(a+1,a+n+1,cmp);
	LL sum=0;
	for(int i=1;i<=n;i++) ans[a[i].pos]=(sum+=a[i].coin),s[0]=a[i].coin,sort(s,s+m+1),sum-=s[0];
	for(int i=1;i<=n;i++) write(ans[i]),putchar(' ');
	return 0;
}