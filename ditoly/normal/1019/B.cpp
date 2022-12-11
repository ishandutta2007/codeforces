#include<bits/stdc++.h>
using namespace std;
int query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
void ans(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int main()
{
	int n,al,ar,bl,br;
	scanf("%d",&n);n/=2;
	if(n&1)ans(-1);
	al=query(1);bl=query(1+n);ar=bl;br=al;
	if(al==bl)ans(1);
	int l=2,r=n,mid,aa,bb;
	while(l<=r)
	{
		mid=l+r>>1;
		aa=query(mid);bb=query(mid+n);
		if(aa==bb)ans(mid);
		if((al>bl&&aa<bb)||(al<bl&&aa>bb))r=mid-1;
		else l=mid+1;
	}
}