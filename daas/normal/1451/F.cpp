#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,val[210];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		memset(val,0,sizeof(val));
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				val[i+j]^=read();
			}
		}
		int flag=0;
		for(int i=2;i<=n+m;++i) if(val[i]) flag=1;
		if(flag) puts("Ashish");
		else puts("Jeel");
	}
	return 0;
}
//ore no turn,draw!