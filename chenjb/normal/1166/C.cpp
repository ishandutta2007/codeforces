#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n;
int a[210000];
int main()
{
	cin>>n;
	rep(i,n){ scanf("%d",&a[i]); a[i]=abs(a[i]); }
	sort(a+1,a+n+1);
	int head=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		while (head<n && 2*a[i]>=a[head+1])head++;
		//cout<<i<<" "<<head<<endl;
		ans=ans+head-i;
	}
	cout<<ans<<endl;
	return 0;
}
/*
x<y

|x-y|=y-x

if y>x>0 |x+y|=x+y    y-x <= x  y<=x+y   ==>   y<=2x 
if y>0>x>-y  |x+y|=x+y  x+y <= x  y<= y-x    y<=0  XXXXXXX
if y>0>x>-y  |x+y|=-x-y  -x-y <= x y<=y-x   -y<=2x  y>=-2x
if 0>y>x  |x+y|=-x-y   y-x <=x  y<=-x-y   y<=2x  XXXXXXXXX
*/