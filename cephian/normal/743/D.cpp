#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 200005;
const ll NINF = -1e18;
ll segt[4*N]={0};
int l[4*N],r[4*N],n,a[N];

void build(int v, int i, int j) {
	l[v]=i;
	r[v]=j;
	if(i!=j) {
		build(v*2,i,(i+j)/2);
		build(v*2+1,(i+j)/2+1,j);
	}
}

void update(int v, int i, ll a) {
	if(i < l[v] || r[v] < i)
		return;
	if(l[v] == r[v])
		segt[v] = a;
	else {
		update(v*2,i,a);
		update(v*2+1,i,a);
		segt[v] = max(segt[v*2],segt[v*2+1]);
	}
}

ll query(int v, int i, int j) {
	if(j < l[v] || r[v] < i) return NINF;
	if(i <= l[v] && r[v] <= j) return segt[v];
	return max(query(v*2,i,j),query(v*2+1,i,j));
}

vvi T;
int s[N],e[N];
ll sum[N];
int ctr=0;
ll dfs(int v, int f) {
	s[v] = ctr++;
	sum[v]=a[v];
	for(auto u : T[v]) {
		if(u==f) continue;
		sum[v]+=dfs(u,v);
	}
	e[v]=ctr-1;
	update(1,s[v],sum[v]);
	return sum[v];
}
ll ans = NINF;
void solve(int v, int f) {
	ll sol = max(query(1,0,s[v]-1),query(1,e[v]+1,n-1));
	if(sol != NINF)
		ans = max(ans,sol+sum[v]);
	update(1,s[v],NINF);
	for(auto u : T[v]) {
		if(u==f) continue;
		solve(u,v);
	}
	update(1,s[v],sum[v]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> n;
	build(1,0,n-1);

	for(int i = 0; i < n; ++i)
		cin >> a[i];
	T = vvi(n,vi());
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		T[--u].push_back(--v);
		T[v].push_back(u);
	}
	dfs(0,-1);
	solve(0,-1);
	if(ans==NINF) cout << "Impossible\n";
	else cout << ans << "\n";
 	return 0;
}