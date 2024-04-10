#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<int> all;
int arr[maxn];
int n,k,A,B;
int tree[maxn];
void add(int x)
{
	while(x<maxn)
	{
		tree[x]++;
		x+=x&-x;
	}
}
int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
int getid(int x)
{
	return upper_bound(all.begin(),all.end(),x)-all.begin()+2;
}
long long solve(int l,int r)
{
	int mid=l+r>>1;
	int all=query(getid(r))-query(getid(l-1));
	if(all==0) return A;
	if(l==r) return B*all;
	long long cost;
	cost=1LL*all*B*(r-l+1);
	return min(cost,solve(l,mid)+solve(mid+1,r));
}
int main()
{
	scanf("%d%d%d%d",&n,&k,&A,&B);
	for(int i=0,temp;i<k;i++)
	{
		scanf("%d",&arr[i]);
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<k;i++) add(getid(arr[i]));
	printf("%lld\n",solve(1,1<<n));
}