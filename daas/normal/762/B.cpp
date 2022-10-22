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
int A,B,C,n,ans1;
long long ans2;
struct data
{
	int v,type;
	bool operator <(const data &Z)const {return v<Z.v;}
}a[300010];
int main()
{
	A=read(),B=read(),C=read();
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].v=read();
		char s[10];
		scanf("%s",s);
		a[i].type=(s[0]=='U');
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		if(a[i].type)
		{
			if(A) --A,++ans1,ans2+=a[i].v;
			else if(C) --C,++ans1,ans2+=a[i].v;
		}
		else
		{
			if(B) --B,++ans1,ans2+=a[i].v;
			else if(C) --C,++ans1,ans2+=a[i].v;
		}
	printf("%d %lld\n",ans1,ans2);
	return 0;
}