#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
using namespace std;
int n,ans=0,Min=2147483647;
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
int ff(int x,int y) {return (y-x+n-1)/n*n+x;}
int main()
{
	n=read();
	for(int i=1,x;i<=n;i++) if(ff(i,x=read()+1)<Min) Min=ff(i,x),ans=i;
	return write(ans),0;
}