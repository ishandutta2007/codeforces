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
int T,n,a[200001];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		int num=1,NOWnum=0,minn=0;
		for(int l=2,r;l<=n;l=r+1)
		{
			r=l;
			while(r+1<=n && a[r+1]>a[r])
				++r;
			--num;
			NOWnum+=(r-l+1);
			if(!num)
				num=NOWnum,NOWnum=0,++minn;
		}
		minn+=(NOWnum!=0);
		printf("%d\n",minn);
	}
	return 0;
}