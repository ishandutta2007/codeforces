#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
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
int fun(int l,int r,int L,int R,int v)
{
	if(l>r || r<L || l>R)
		return 0;
	if(l==r)
		return v;
	int mid=(l+r)/2;
	if(R<mid)
		return fun(l,mid-1,L,R,v/2);
	if(mid<L)
		return fun(mid+1,r,L,R,v/2);
	return fun(l,mid-1,L,R,v/2)+fun(mid+1,r,L,R,v/2)+(v%2);
}
signed main()
{
	int n=read(),l=read(),r=read();
	int LOG=log2(n);
	printf("%lld\n",fun(1,(1ll<<LOG+1)-1,l,r,n));
	return 0;
}