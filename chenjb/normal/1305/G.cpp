
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n,cnt[1<<18],father[1<<18];
int getfather(int x)
{
	return father[x]<0?x:father[x]=getfather(father[x]);
}
long long merge(int x,int y)
{
	x=getfather(x);
	y=getfather(y);
	if (x==y)return 0;
	if (father[x]>father[y])swap(x,y);
	long long ret=0;
	if (father[x]==-1)ret+=cnt[x]; else ret++;
	if (father[y]==-1)ret+=cnt[y]; else ret++;
	father[x]+=father[y];
	father[y]=x;
	return ret-1;
}
int main()
{
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		cnt[x]++;
		ans-=x;
	}
	cnt[0]++;
	memset(father,255,sizeof(father));
	for(int i=(1<<18)-1;i>=0;i--)
		for(int p=i;p>0;p=(p-1)&i)
		{
			int j=i^p;
			if (!cnt[p] || !cnt[j])continue;
			ans+=1ll*i*merge(p,j);
		}
	cout<<ans<<endl;
	return 0;
}