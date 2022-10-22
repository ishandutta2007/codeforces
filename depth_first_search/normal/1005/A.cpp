#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 1000
using namespace std;
int n,ans[N+5];
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
	int x=read(),lst=x,tot=0;
	for(int i=2;i<=n;i++) 
		if((x=read())==1) ans[++tot]=lst,lst=x;else lst=x;
	write(++tot),putchar('\n');
	for(int i=1;i<tot;i++) write(ans[i]),putchar(' ');
	return write(lst),0;
}