#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=2e5+7;
int arr[maxn];
int pre[maxn];
vector<int> all;
int tree[maxn];
struct Seg{
	int l,r;
	bool operator< (const Seg &a) const{
		return l<a.l;
	}
};
vector<Seg> seg;
int getid(int x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
long long quick(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	memset(pre,-1,sizeof(pre));
	memset(tree,0,sizeof(tree));
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int index=getid(arr[i]);
		seg.push_back(Seg{i,i});
		if(pre[index]!=-1)
		{
			seg.push_back(Seg{pre[index],i});
		}
		pre[index]=i;
	}
	sort(seg.begin(),seg.end());
	int le=0,ri=0;
	for(int i=0;i<seg.size();i++)
	{
		if(seg[i].l<=ri) ri=max(ri,seg[i].r);
		else {le=seg[i].l,cnt++;ri=seg[i].r;};
	}
	printf("%lld\n",quick(2,cnt));
}