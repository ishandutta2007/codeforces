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
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') x=-1,c=getchar();
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,ans[100010],ANS,res=1;
int gcd(int x,int y)
{
	int z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) if(gcd(i,n)==1) ans[++ANS]=i,res=(ll)res*i%n;
	printf("%d\n",ANS-(res!=1));
	for(int i=1;i<=ANS;++i) if(ans[i]!=res || ans[i]==1) printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}