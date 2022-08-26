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
int n,m,i,j,pos[25],pos2[25],ans[25];
struct ii
{
	int num,pos,ans;
}num[25];
bool cmp(ii x,ii y)
{
	return x.num<y.num;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>num[i].num;
		num[i].pos=i;
	}
	sort(num+1,num+n+1,cmp);
	for (i=1;i<n;i++) num[i].ans=num[i+1].num;
	num[n].ans=num[1].num;
	for (i=1;i<=n;i++) ans[num[i].pos]=num[i].ans;
	for (i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}