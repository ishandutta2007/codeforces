#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
using namespace std;
int a,b,x;
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
	a=read(),b=read(),x=read();
	if(x%2)
	{
		for(int i=1;i<=a-(x>>1);i++) putchar('0');
		for(int i=1;i<=x>>1;i++) putchar('1'),putchar('0');
		for(int i=1;i<=b-(x>>1);i++) putchar('1');
	}
	else
	{
		if(x>>1==a) {for(int i=1;i<=x>>1;i++) putchar('1'),putchar('0');for(int i=x+1;i<=a+b;i++) putchar('1');}
		else if(x>>1==b) {for(int i=1;i<=x>>1;i++) putchar('0'),putchar('1');for(int i=x+1;i<=a+b;i++) putchar('0');}
		else {for(int i=1;i<=x>>1;i++) putchar('0'),putchar('1');for(int i=1;i<=b-(x>>1);i++) putchar('1');for(int i=1;i<=a-(x>>1);i++) putchar('0');}
	}
	return 0;
}