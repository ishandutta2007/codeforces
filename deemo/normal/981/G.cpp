#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define plus aksjdfoi

const int MAXN = 2e5 + 10;
const int MOD = 998244353;

int n;
int sum[MAXN<<2], plus[MAXN<<2], mul[MAXN<<2];
set<pii> st[MAXN];

int fix(int x){
	while (x >= MOD) x -= MOD;
	return x;
}

void absorb(int v, int b, int e, int mid){
	if (mul[v] == 1 && !plus[v]) return;

	sum[v<<1] = (1ll*sum[v<<1]*mul[v]+1ll*plus[v]*(mid-b))%MOD;
	plus[v<<1] = (plus[v] + 1ll*plus[v<<1]*mul[v])%MOD;
	mul[v<<1] = 1ll*mul[v<<1]*mul[v]%MOD;

	sum[v<<1^1] = (1ll*sum[v<<1^1]*mul[v]+1ll*plus[v]*(e-mid))%MOD;
	plus[v<<1^1] = (plus[v] + 1ll*plus[v<<1^1]*mul[v])%MOD;
	mul[v<<1^1] = 1ll*mul[v<<1^1]*mul[v]%MOD;

	mul[v] = 1, plus[v] = 0;
}

void inc(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		sum[v] = fix(sum[v]+(e-b));
		plus[v] = fix(plus[v]+1);
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	inc(v<<1, b, mid, l, r);
	inc(v<<1^1, mid, e, l, r);
	sum[v] = fix(sum[v<<1] + sum[v<<1^1]);
}

void mult(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		sum[v] = fix(sum[v]<<1);
		plus[v] = fix(plus[v]<<1);
		mul[v] = fix(mul[v]<<1);
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	mult(v<<1, b, mid, l, r);
	mult(v<<1^1, mid, e, l, r);
	sum[v] = fix(sum[v<<1] + sum[v<<1^1]);
}

int get(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return sum[v];
	if (r <= b || e <= l) return 0ll;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	return fix(get(v<<1, b, mid, l, r) + get(v<<1^1, mid, e, l, r));
}

pii gec[2][MAXN*5]; int tt[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;
	fill(mul, mul+4*MAXN, 1);
	for (int i = 0; i < n; i++) st[i].insert({0, n});
	while (q--){
		int type; cin >> type;
		if (type == 1){
			int l, r, x; cin >> l >> r >> x, l--, x--;
			tt[0] = tt[1] = 0;
			auto it = st[x].lower_bound({l+1, -1});
			if (it != st[x].begin()) it--;

			int last = l;
			while (it != st[x].end() && it->F < r){
				auto seg = *it; it++;
				if (seg.F < l){
					if (seg.S > l)
						gec[1][tt[1]++] = make_pair(seg.F, l), gec[0][tt[0]++] = seg, seg.F = l;
					else
						seg.F = seg.S = -1;
				}
				if (seg.S > r) {
					gec[0][tt[0]++] = seg;
					gec[1][tt[1]++] = make_pair(r, seg.S);
					seg.S = r;
				}
				if (seg.F != -1){
					if (last != seg.F)
						mult(1, 0, n, last, seg.F);

					gec[0][tt[0]++] = seg;
					inc(1, 0, n, seg.F, seg.S);
					last = seg.S;
				}
			}
			if (last != r)
				mult(1, 0, n, last, r);

			for (int i = 0; i < tt[0]; i++)
				st[x].erase(gec[0][i]);
			for (int i = 0; i < tt[1]; i++)
				st[x].insert(gec[1][i]);
		}
		else{
			int l, r; cin >> l >> r, l--;
			cout << get(1, 0, n, l, r) << "\n";
		}
	}
	return 0;
}