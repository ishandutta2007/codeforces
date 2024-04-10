#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int min(LL x,LL y)
{
	if (x<y)return x; return y;
}
struct node
{
	LL k,l;
	friend bool operator <(node x,node y)
	{
		return min(2*x.k,x.l)-min(x.k,x.l)>min(2*y.k,y.l)-min(y.k,y.l);
	}
}a[100100];

int main()
{	
	int n,f;
	cin>>n>>f;
	for(int i=1;i<=n;i++)cin>>a[i].k>>a[i].l;
	sort(a+1,a+n+1);
	LL ans=0;
	for(int i=1;i<=f;i++)ans+=min(2*a[i].k,a[i].l);
	for(int i=f+1;i<=n;i++)ans+=min(a[i].k,a[i].l);
	cout<<ans<<endl;
	return 0;
}