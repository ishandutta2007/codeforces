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
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,a,b;
int calc(int m,int v)
{
	int l=b+1,r=1000000001,bck;
	while(l<=r)
	{
		int mid=(l+r)/2,mem=0,fb=v;
		while(fb)
		{
			fb/=mid;
			++mem;
		}
		if(mem<=m) bck=mid,r=mid-1;
		else l=mid+1;
	}
	return bck;
}
int main()
{
	T=read();
	while(T--)
	{
		a=read(),b=read();
		int ans,cnt=0,st=0;
		if(b==1) st=1,b=2;
		int fb=a;
		while(fb)
		{
			fb/=b;
			++cnt;
		}
		ans=cnt;
		for(int i=1;i<cnt;++i) ans=min(ans,i+calc(i,a)-b);
		printf("%d\n",ans+st);
	}
	return 0;
}