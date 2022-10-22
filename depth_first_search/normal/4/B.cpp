#include<bits/stdc++.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define LL long long
#define N 30
using namespace std;
int n,m,Min[N+5],Max[N+5],f[N+5][300];
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
	int SumMin=0,SumMax=0;
	for(int i=1;i<=n;i++) SumMin+=(Min[i]=read()),SumMax+=(Max[i]=read());
	if(SumMin>m||SumMax<m) return puts("NO"),0;
	puts("YES");
	int tot=SumMin;
	for(int i=1;i<=n;i++)
	{
		if(tot==m) {write(Min[i]),putchar(' ');continue;}
		if(tot+Max[i]-Min[i]<m) write(Max[i]),putchar(' '),tot+=Max[i]-Min[i];
		else write(Min[i]+m-tot),putchar(' '),tot=m;
	}
	return 0;
}