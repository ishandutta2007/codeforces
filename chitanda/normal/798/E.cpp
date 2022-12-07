#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 500100;
int n;
bool vis[maxn];
int a[maxn], b[maxn];
int ans[maxn];
vector<int> res;
pair<int, int> tr[maxn * 4];

void build(int t, int l, int r){
	if(l == r){
		tr[t] = mkp(b[l], l);
		return;
	}
	int d = (l + r) >> 1;
	build(ls, l, d);
	build(rs, d + 1, r);
	tr[t] = max(tr[ls], tr[rs]);
}

void del(int t, int l, int r, int x){
	if(l == r){
		tr[t] = {0, 0};
		return;
	}
	int d = (l + r) >> 1;
	if(x <= d) del(ls, l, d, x);
	else del(rs, d + 1, r, x);
	tr[t] = max(tr[ls], tr[rs]);
}

pair<int, int> ask(int t, int l, int r, int y){
	if(y >= r) return tr[t];
	int d = (l + r) >> 1;
	auto res = ask(ls, l, d, y);
	if(y > d) res = max(res, ask(rs, d + 1, r, y));
	return res;
}

void dfs(int t){
	if(b[t] != n + 1 && !vis[b[t]]) dfs(b[t]);
	del(1, 1, n, t);
	while(a[t] > 1 && 1){
		auto tmp = ask(1, 1, n, a[t] - 1);
		if(tmp.fi > t) dfs(tmp.se);
		else break;
	}
	vis[t] = 1;
	res.pb(t);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) b[i] = n + 1;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		if(a[i] != -1) b[a[i]] = i;
		else a[i] = n + 1;
	}
	build(1, 1, n);
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) dfs(i);
	int now = 0;
	for(auto v : res) ans[v] = ++now;
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}