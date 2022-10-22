#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
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
int T,n,m,a[100],b[100];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		m=read();
		for(int i=1;i<=m;++i) b[i]=read();
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		if(a[n]>=b[m]) puts("Alice");
		else puts("Bob");
		if(b[m]>=a[n]) puts("Bob");
		else puts("Alice");
	}
	return 0;
}
//ore no turn,draw!