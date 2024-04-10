#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,cnt,ans[1001];
int main()
{
	n=read(),K=read();
	for(int i=1;i<=K;++i)
	{
		ans[++cnt]=i;
		for(int j=i+1;j<=K;++j)
		{
			ans[++cnt]=i;
			ans[++cnt]=j;
		}
	}
	//ans[++cnt]=1;
	for(int i=1;i<=n/cnt;++i)
	{
		for(int j=1;j<=cnt;++j) printf("%c",'a'+ans[j]-1);
	}
	for(int i=1;i<=n%cnt;++i) printf("%c",'a'+ans[i]-1);
	return 0;
}