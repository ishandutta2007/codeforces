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
int T,n,a[200010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		sort(a+1,a+n+1);
		int ans=0,num=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r+1<=n && a[r+1]==a[r]) ++r;
			if(l!=r) ++ans;
			else ++num;
		}
		printf("%d\n",ans+(num+1)/2);
	}
	return 0;
}
//ore no turn,draw!