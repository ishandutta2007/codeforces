#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
map<int,int> cur,nxt;
int arr[maxn];
map<int,long long> ans;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		nxt.clear();
		for(auto &p:cur)
		{
			nxt[__gcd(p.first,arr[i])]+=p.second;
		}
		nxt[arr[i]]++;
		swap(cur,nxt);
		for(auto &p:cur) ans[p.first]+=p.second;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",ans[x]);
	}
}