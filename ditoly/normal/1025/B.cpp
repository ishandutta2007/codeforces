#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 150000
int n,a[MN+5],b[MN+5];
void check(int x)
{
	for(int i=1;i<=n;++i)
		if(a[i]%x!=0&&b[i]%x!=0)return;
	printf("%d",x);exit(0);
}
int main()
{
	int i,x;
	for(n=read(),i=1;i<=n;++i)a[i]=read(),b[i]=read();
	for(x=a[1],i=2;i*i<=x;++i)if(x%i==0){check(i);while(x%i==0)x/=i;}
	if(x>1)check(x);
	for(x=b[1],i=2;i*i<=x;++i)if(x%i==0){check(i);while(x%i==0)x/=i;}
	if(x>1)check(x);
	puts("-1");
}