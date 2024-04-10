#include<bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l+r) >> 1)
using namespace std;

const int maxn = 200009;
const int maxm = 1000009;
const int MOD = 1000000007;
vector<int> f[maxm], g[maxn];
vector<pair<int, int> > q[maxn];
int p[maxm], val[maxn], T[maxn<<2], a[maxn], ans[maxn];
int pre[maxn], preRev[maxn];
int n, cnt, Q, limit, L, R, pri;

int power(int x, int p){
	int res = 1;
	while (p){
		if (p&1) res = 1LL*res*x%MOD;
		x = 1LL*x*x%MOD; p >>= 1;
	}
	return res;
}

void init(){
	for (int i=2; i<=limit; i++){
		if (!f[i].size()){
			p[++cnt] = i; f[i].push_back(cnt);
			val[cnt] = 1LL*(i-1)*power(i, MOD-2)%MOD;
		}
		for (int j=1; j<=cnt&&i*p[j]<=limit; j++){
			if (i % p[j] == 0){
				f[i*p[j]] = f[i]; break;
			}
			f[i*p[j]] = f[i]; f[i*p[j]].push_back(j);
		}
	}
	for (int i=n; i>=1; i--)
		for (int j=0; j<f[a[i]].size(); j++)
			g[f[a[i]][j]].push_back(i);
}

void update(int o, int l, int r, int x, int y){
	if (l == r){ T[o] = 1LL*T[o]*y%MOD; return; }
	if (x <= mid) update(lc, l, mid, x, y);
	else update(rc, mid+1, r, x, y);
	T[o] = 1LL*T[lc]*T[rc]%MOD;
}

int query(int o, int l, int r, int x, int y){
	if (l == x && y == r) return T[o];
	if (y <= mid) return query(lc, l, mid, x, y);
	if (mid+1 <= x) return query(rc, mid+1, r, x, y);
	return 1LL*query(lc, l, mid, x, mid)*query(rc, mid+1, r, mid+1, y)%MOD;
}

int main(){
	scanf("%d", &n);
	pre[0] = preRev[0] = 1;
	for (int i=1; i<=n; i++){
		scanf("%d", &a[i]); 
		limit = max(limit, a[i]);
		pre[i] = 1LL*pre[i-1]*a[i]%MOD;
		preRev[i] = power(pre[i], MOD-2);
	}
	init();
	scanf("%d", &Q);
	for (int i=1; i<=Q; i++){
		scanf("%d%d", &L, &R);
		q[L].push_back(make_pair(R, i));
	}
	for (int i=1; i<=4*n; i++) T[i] = 1;
	for (int i=1; i<=cnt; i++)
		if (g[i].size()){ 
			update(1, 1, n, g[i].back(), val[i]); g[i].pop_back();
		}
	for (int i=1; i<=n; i++){
		for (int j=0; j<q[i].size(); j++){
			ans[q[i][j].second] = 1LL * pre[q[i][j].first]*preRev[i-1] % MOD
									  * query(1, 1, n, i, q[i][j].first) % MOD;
			}
		for (int j=0; j<f[a[i]].size(); j++){
			pri = f[a[i]][j];
			if (g[pri].size()){
				update(1, 1, n, g[pri].back(), val[pri]); g[pri].pop_back();
			}
		}
	}
	for (int i=1; i<=Q; i++) printf("%d\n", ans[i]);
	return 0;
}