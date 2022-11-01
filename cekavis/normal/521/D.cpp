#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int k, n, m, cnt, a[N];
pair<int,int> g[N];
vector<vector<int>> f[N];
struct item{
	int id, tp, x;
	ll y;
	bool operator<(const item &r)const{ return x*r.y>y*r.x;}
} p[N];
int main() {
	scanf("%d%d%d", &k, &n, &m);
	for(int i=1; i<=k; ++i) scanf("%d", a+i), g[i].first=a[i];
	for(int i=1, x, y, z; i<=n; ++i){
		scanf("%d%d%d", &x, &y, &z);
		if(x==1) g[y]=max(g[y], make_pair(z, i));
		else if(x==3) p[++cnt]=(item){i, 3, z-1, 1};
		else f[y].push_back({z, i, 2});
	}
	for(int i=1; i<=k; ++i){
		if(g[i].second) f[i].push_back({g[i].first-a[i], g[i].second, 1});
		sort(f[i].begin(), f[i].end(), greater<vector<int>>());
		ll last=a[i];
		for(auto &x:f[i]) p[++cnt]=(item){x[1], x[2], x[0], last}, last+=x[0];
	}
	printf("%d\n", m=min(m, cnt)), nth_element(p+1, p+m, p+cnt+1);
	for(int j=1; j<=3; ++j) for(int i=1; i<=m; ++i)
		if(p[i].tp==j) printf("%d ", p[i].id);
	return 0;
}