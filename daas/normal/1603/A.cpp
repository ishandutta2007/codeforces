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
const int inf=1e9;
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[MAXN],z[MAXN];
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
	T=read();
	int tim=0;
	while(T--)
	{
		n=read();
		int flag=0;
		for(int i=1,cur=1;i<=n;++i)
		{
			if(cur!=-1)
			{
				int d=gcd(cur,i+1);
				if((ll)cur/d*(i+1)>inf) cur=-1;
				else cur=cur/d*(i+1);
			}
			a[i]=read();
			if(cur!=-1 && a[i]%cur==0) flag=1;
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
//ore no turn,draw!