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
int T;
int main()
{
	T=read();
	while(T--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i) m-=read();
		printf("%d\n",max(0,-m));
	}
	return 0;
}
//ore no turn,draw!