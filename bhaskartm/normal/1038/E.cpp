#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1005;
const int M=16;
 
struct data
{
	int c1, c2, val, idx;
 
	bool operator<(data &b)
	{
		return val<b.val;
	}
};
 
int n, sum=0, ans=0;
bool ban[N], vis[N];
int cnt[M], taken[M];
data blocks[N];
vector<data> g[M], edges[M];
vector<int> path;
 
int compress(int c1, int c2)
{
	if(c1>c2)
		swap(c1, c2);
	return c1*4 + c2;
}
 
bool checker()
{
	memset(cnt, 0, sizeof(cnt));
	for(int i=1;i<path.size();i++)
		cnt[compress(path[i-1], path[i])]++;
	for(int i=0;i<M;i++)
		if(cnt[i]>taken[i])
			return 0;
	return 1;
}
 
void euler(int u)
{
	for(auto &it:g[u])
	{
		int v=it.c2;
		int idx=it.idx;
		if(vis[idx]||ban[idx])
			continue;
		taken[compress(u, v)]++;
		vis[idx]=1;
		sum+=it.val;
		euler(v);
	}
	path.push_back(u);
}
 
int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int c1, val, c2;
		cin>>c1>>val>>c2;
		c1--;
		c2--;
		blocks[i]=(data){c1, c2, val, i};
		g[c1].push_back((data){c1, c2, val, i});
		g[c2].push_back((data){c2, c1, val, i});
		edges[compress(c1, c2)].push_back(blocks[i]);
	}
	for(int i=0;i<M;i++)
		if(edges[i].size())
			sort(edges[i].begin(), edges[i].end());
	for(int mask=0;mask<(1<<M);mask++)
	{
		if(mask>>compress(0, 0)&1)
			continue;
		if(mask>>compress(1, 1)&1)
			continue;
		if(mask>>compress(2, 2)&1)
			continue;
		if(mask>>compress(3, 3)&1)
			continue;
 
		int check=0;
		memset(ban, 0, sizeof(ban));
		for(int i=0;i<M;i++)
		{
			if(!(mask>>i & 1))
				continue;
			if(edges[i].empty())
				check=1;
			else
				ban[edges[i][0].idx]=1;
		}
		if(!check)
			continue;
 
		for(int i=0;i<4;i++)
		{
			memset(vis, 0, sizeof(vis));
			path.clear();
			sum=0;
			memset(taken, 0, sizeof(taken));
			euler(i);
			if(checker())
				ans=max(ans, sum);
		}
	}
	cout<<ans;
	return 0;
}