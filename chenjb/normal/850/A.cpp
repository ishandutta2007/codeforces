#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#define LL long long
using namespace std;
struct node
{
	int a,b,c,d,e;
	double len() { return sqrt(a*a+b*b+c*c+d*d+e*e); }
	friend node operator -(node x,node y)
	{
		node z;
		z.a=x.a-y.a; z.b=x.b-y.b; z.c=x.c-y.c; z.d=x.d-y.d; z.e=x.e-y.e;
		return z;
	}
}a[1100];
int stack[1100];
int ans[1100];
int cnt;
int dianji(node x,node y)
{
	return x.a*y.a+x.b*y.b+x.c*y.c+x.d*y.d+x.e*y.e;
}
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d%d%d",&a[i].a,&a[i].b,&a[i].c,&a[i].d,&a[i].e);
	if (n>200)
	{
		cout<<0<<endl;
		return 0;
	}
	memset(ans,1,sizeof(ans));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if (i!=j&&j!=k&&k!=i)
					if (dianji(a[j]-a[i],a[k]-a[i])>0)ans[i]=0;
	cnt=0;
	for(int i=1;i<=n;i++)
			if (ans[i])cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if (ans[i])cout<<i<<endl;

}