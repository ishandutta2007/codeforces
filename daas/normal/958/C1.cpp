#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
inline int lowbit(int x){return x&-x;}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,p,a[500001],ans=-0x3f3f3f3f;
inline int MOD(int x){return x+((x>>31)&p);}
int main()
{
	n=read(),p=read();
	for(int i=1;i<=n;++i) a[i]=MOD(a[i-1]+read()%p-p);
	for(int i=1;i<n;++i) ans=max(ans,a[i]+MOD(a[n]-a[i]));
	printf("%d\n",ans);
	return 0;
}