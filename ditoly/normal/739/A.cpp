#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
int main()
{
	int n,m,i,mn;
	mn=n=read();m=read();
	while(m--){i=read();i=read()-i;if(i<mn)mn=i;}
	printf("%d\n",++mn);
	for(i=0;i<n;i++)printf("%d ",i%mn);
}