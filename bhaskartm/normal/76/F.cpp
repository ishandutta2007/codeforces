#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
pair<long long,long long>eve[100010];
int n,v;
int seq[100010],l;
int x[100010],t[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,t+i);
	scanf("%d",&v);
	for(int i=1;i<=n;i++)eve[i]=make_pair(1LL*t[i]*v-x[i],1LL*t[i]*v+x[i]);
	sort(eve+1,eve+n+1);
	l=0;
	for(int i=1;i<=n;i++)
	{
		if(eve[i].first<0 || eve[i].second<0)continue;
		if(!l || seq[l]<=eve[i].second)seq[++l]=eve[i].second;
		else seq[upper_bound(seq+1,seq+l+1,eve[i].second)-seq]=eve[i].second;
	}
	printf("%d ",l);
	l=0;
	for(int i=1;i<=n;i++)
	{
		if(!l || seq[l]<=eve[i].second)seq[++l]=eve[i].second;
		else seq[upper_bound(seq+1,seq+l+1,eve[i].second)-seq]=eve[i].second;
	}
	printf("%d",l);
	return 0;
}