#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,x1,x2;
struct ii
{
	long long id,x;
}num[300005];
vector<long long> ans1,ans2;
bool cmp(ii x,ii y)
{
	return x.x>y.x;
}
void check(bool swp)
{
	long long i,cnt=0;
	ans1.clear();
	ans2.clear();
	for (i=1;i<=n;i++)
	{
		cnt++;
		ans1.push_back(num[i].id);
		if (num[i].x*cnt>=x1) break;
	}
	if (i>n) return;
	cnt=0;
	for (i++;i<=n;i++)
	{
		cnt++;
		ans2.push_back(num[i].id);
		if (num[i].x*cnt>=x2) break;
	}
	if (i>n) return;
	puts("Yes");
	if (swp) swap(ans1,ans2);
	printf("%lld %lld\n",(long long)ans1.size(),(long long)ans2.size());
	for (i=0;i<ans1.size();i++) printf("%lld ",ans1[i]);
	puts("");
	for (i=0;i<ans2.size();i++) printf("%lld ",ans2[i]);
	puts("");
	exit(0);
}
int main()
{
	scanf("%lld%lld%lld",&n,&x1,&x2);
	for (i=1;i<=n;i++)
	{
		num[i].id=i;
		scanf("%lld",&num[i].x);
	}
	stable_sort(num+1,num+n+1,cmp);
	check(0);
	swap(x1,x2);
	check(1);
	puts("No");
	return 0;
}