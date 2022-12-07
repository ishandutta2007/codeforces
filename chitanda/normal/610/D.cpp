#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long
#define se second
#define fi first
#define pb push_back
#define bk back()
#define ls (o << 1)
#define rs ((o << 1) | 1)
#define mid ((l + r) >> 1)
#define INF (0x3f3f3f3f)

const int maxo = 1000000;
ll cov[maxo], len[maxo];
int dic[maxo];
void update(int o, int a, int b, int x, int l, int r){
	if (a >= r || b <= l) return;
	if (l >= a && r <= b){
		cov[o] += x;
		if(cov[o] == 0){
			if (r - l <= 1) len[o] = 0;
			else len[o] = len[ls] + len[rs];
		}
		if (cov[o] == 1) len[o] = dic[r] - dic[l];
		return;
	}
	update(ls, a, b, x, l, mid);
	update(rs, a, b, x, mid, r);
	if (cov[o] <= 0) len[o] = len[ls] + len[rs];
}
ll query(int o, int a, int b, int l, int r){
	if (a >= r || b <= l) return 0;
	if (l >= a && r <= b) return len[o];
	if (cov[o] >= 1) return min(dic[r], dic[b]) - max(dic[l], dic[a]);
	return query(ls, a, b, l, mid) + query(rs, a, b, mid, r);
}

struct line{
	int a, b, h, v;
	line(int a = 0, int b = 0, int h = 0, int v = 0): a(a), b(b), h(h), v(v) {}
	bool operator < (const line &c)const{
		return h < c.h;
	}
}L[maxo];
int n, dh;
int idx(int x){
	return lower_bound(dic, dic + dh, x) - dic;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("xx.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 0, a, b, c, d; i < n; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a > c || b > d) swap(a, c), swap(b, d);
		L[i] = line(a, c + 1, b, 1);
		L[i + n] = line(a, c + 1, d + 1, -1);
		dic[i] = a;
		dic[i + n] = c + 1;
	}
	sort(dic, dic + n * 2);
	sort(L, L + n * 2);
	dh = unique(dic, dic + n * 2) - dic;
	ll ans = 0;
	ll lastlen = 0, lastpos = INF;
	for(int i = 0; i < n * 2; i++){
		ans += lastlen * (L[i].h - lastpos);
		update(1, idx(L[i].a), idx(L[i].b), L[i].v, 0, dh);
		lastlen = len[1];
		lastpos = L[i].h;
	}
	cout << ans << endl;
  return 0;
}