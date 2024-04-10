#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 2000
#define M 2000
using namespace std;
int n,m,a[N+5][M+5],s[M+5];
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
int get_num()
{
	char ch=getchar();
	while(ch==' '||ch=='\n') ch=getchar();
	return ch-'0';
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[j]+=(a[i][j]=get_num());
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=m;j++) if(s[j]-a[i][j]==0) {flag=false;break;}
		if(flag) return puts("YES"),0;
	}
	puts("NO");
	return 0;
}