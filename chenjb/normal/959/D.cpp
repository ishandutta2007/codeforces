#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int divide[7000000],forbidden[7000000];
int n;
int a[110000],ans[110000];
bool check(int x) //
{
	for(;x!=1;x/=divide[x])
		if (forbidden[divide[x]])return 0;
	return 1;
}
void update(int x) //forbidden
{
	for(;x!=1;x/=divide[x])forbidden[divide[x]]=1;
}
int main()
{
	for(int i=2;i<=6000000;i++)divide[i]=forbidden[i]=0;
	for(int i=2;i<=6000000;i++) //
	{
		if (divide[i])continue;
		for(int j=i;j<=6000000;j+=i)
			if (!divide[j])divide[j]=i;
	} 

	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	int now=1;
	while (now<=n)
	{
		if (check(a[now])){ update(a[now]); ans[now]=a[now]; now++; continue; } //
		ans[now]=a[now]; 
		for(;!check(ans[now]);ans[now]++); //
		update(ans[now]);
		break;
	}
	int t=2;
	for(int i=now+1;i<=n;i++)
	{
		while (divide[t]!=t || forbidden[t])t++; //
		ans[i]=t++;
	}

	for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
}