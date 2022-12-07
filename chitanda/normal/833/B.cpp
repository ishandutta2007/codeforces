#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 35100, maxk = 55;
const int maxp = maxn * 16 * 2 * 2;

int tot, n, k;
int f[maxk][maxn];
int tr[maxp], ls[maxp], rs[maxp];
int a[maxn], w[maxn], rt[maxn];
pair<pair<int, int>, int> sta[maxn];

int insert(int rt, int l, int r, int x, int v){
	int t = ++tot; tr[t] = tr[rt], ls[t] = ls[rt], rs[t] = rs[rt];
	if(l == r){
		tr[t] += v;
		return t;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) ls[t] = insert(ls[rt], l, mid, x, v);
	else rs[t] = insert(rs[rt], mid + 1, r, x, v);
	tr[t] = tr[ls[t]] + tr[rs[t]];
	return t;
}

int ask(int t, int l, int r, int w){
	if(!t) return 0;
	if(w <= l) return tr[t];
	int mid = (l + r) >> 1;
	if(w <= mid) return ask(ls[t], l, mid, w) + ask(rs[t], mid + 1, r, w);
	else return ask(rs[t], mid + 1, r, w);
}

inline int calc(int i, int l, int r){
	return f[i - 1][l] + ask(rt[r], 1, n, l + 1);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i){
		rt[i] = insert(rt[i - 1], 1, n, i, 1);
		if(w[a[i]]) rt[i] = insert(rt[i], 1, n, w[a[i]], -1);
		w[a[i]] = i;
	}
	
	for(int i = 1; i <= k; ++i){
		sta[1] = mkp(mkp(1, n), 0);
		int l = 1, r = 1;
		for(int j = 1; j <= n; ++j){
			f[i][j] = calc(i, sta[l].se, j);
			if(sta[l].fi.fi == j) sta[l].fi.fi++;
			if(sta[l].fi.fi > sta[l].fi.se) ++l;
			if(j == n) continue;
			if(l > r){
				sta[++r] = mkp(mkp(j + 1, n), j);
				continue;
			}
			if(calc(i, j, n) <= calc(i, sta[r].se, n)) continue;
			while(l <= r && calc(i, sta[r].se, sta[r].fi.fi) <= calc(i, j, sta[r].fi.fi)) --r;
			
			if(l > r) sta[++r] = mkp(mkp(j + 1, n), j);
			else{
				int lt = sta[r].fi.fi, rt = sta[r].fi.se + 1;
				while(lt + 1 < rt){
					int d = (lt + rt) >> 1;
					if(calc(i, sta[r].se, d) > calc(i, j, d)) lt = d;
					else rt = d;
				}
				sta[r].fi.se = lt;
				sta[++r] = mkp(mkp(rt, n), j);
			}
		}
	}
	printf("%d\n", f[k][n]);
	
	return 0;
}