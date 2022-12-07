#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int maxn = 100100;
struct node{
	int x, r, f;
	void input() { scanf("%d%d%d", &x, &r, &f); }
	bool operator < (const node &a) const{
		return r > a.r;
	}
}sta[maxn];
int n, k;
vector<int> c[10001], F[10001];

void add(int j, int x){
	for(; x < c[j].size(); x += x & -x) ++c[j][x];
}

int ask(int j, int x){
	int res = 0;
	for(; x; x -= x & -x) res += c[j][x];
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) sta[i].input(), F[sta[i].f].pb(sta[i].x);
	sort(sta, sta + n);
	for(int i = 1; i <= 10000; ++i){
		sort(F[i].begin(), F[i].end());
		F[i].erase(unique(F[i].begin(), F[i].end()), F[i].end());
		c[i].resize(F[i].size() + 1);
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i){
		int x = sta[i].x, f = sta[i].f, r = sta[i].r;
		int lt = x - r, rt = x + r;
		for(int j = max(1, sta[i].f - k); j <= min(10000, sta[i].f + k); ++j){
			int li = lower_bound(F[j].begin(), F[j].end(), lt) - F[j].begin();
			int ri = upper_bound(F[j].begin(), F[j].end(), rt) - F[j].begin();
			ans += ask(j, ri) - ask(j, li);
		}
		int w = lower_bound(F[f].begin(), F[f].end(), x) - F[f].begin();
		add(f, w + 1);
	}
	return 0 * printf("%lld\n", ans);
}