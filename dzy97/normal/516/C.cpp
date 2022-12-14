#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PI;
#define MP make_pair
#define N 200010

int d[N], h[N], n, Q;
ll s[N], bin[N];

struct Segtree{
	struct segnode{
		ll v1, v2;
		int id;
	}t[N << 2];
	#define ls (x << 1)
	#define rs (x << 1 | 1)

	void upd(int x){
		if(t[ls].v1 > t[rs].v1) t[x].v1 = t[ls].v1, t[x].id = t[ls].id, t[x].v2 = max(t[ls].v2, t[rs].v1);
		else t[x].v1 = t[rs].v1, t[x].id = t[rs].id, t[x].v2 = max(t[rs].v2, t[ls].v1);
	}

	void build(int l, int r, int x){
		if(l == r){
			t[x].v1 = bin[l];
			t[x].v2 = -1e16;
			t[x].id = l;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		upd(x);
	}

	PI query(int ql, int qr, int l, int r, int x){
		if(ql <= l && r <= qr) return MP(t[x].v1, t[x].id);
		int mid = (l + r) >> 1;
		PI ret = MP(-1e16, -1e16);
		if(ql <= mid) ret = max(ret, query(ql, qr, l, mid, ls));
		if(mid < qr)  ret = max(ret, query(ql, qr, mid + 1, r, rs));
		return ret;
	}

	PI query2(int ql, int qr, int l, int r, int x){
		if(ql <= l && r <= qr) return MP(t[x].v1, t[x].v2);
		int mid = (l + r) >> 1;
		PI ret = MP(-1e16, -1e16), t;
		if(ql <= mid){
			t = query2(ql, qr, l, mid, ls);
			if(t.first > ret.first){
				ret.second = ret.first;
				ret.first = t.first;
			}else if(t.first == ret.first){
				ret.second = t.first;
			}else if(t.first > ret.second){
				ret.second = t.first;
			}
			if(t.second > ret.second) ret.second = t.second;
		}
		if(mid < qr){
			t = query2(ql, qr, mid + 1, r, rs);
			if(t.first > ret.first){
				ret.second = ret.first;
				ret.first = t.first;
			}else if(t.first == ret.first){
				ret.second = t.first;
			}else if(t.first > ret.second){
				ret.second = t.first;
			}
			if(t.second > ret.second) ret.second = t.second;
		}
		return ret;
	}
}TL, TR;

ll work(int l, int r){
	if(l >= r) return -1e9;
	PI tl = TL.query(l, r, 1, 2 * n, 1);
	PI tr = TR.query(l, r, 1, 2 * n, 1);
	if(tl.second != tr.second) return tl.first + tr.first;
	PI tl2 = TL.query2(l, r, 1, 2 * n, 1);
	PI tr2 = TR.query2(l, r, 1, 2 * n, 1);
	return max(tl2.first + tr2.second, tl2.second + tr2.first);
}

int main(){
	scanf("%d%d", &n, &Q);
	for(int i = 1;i <= n;i ++) scanf("%d", &d[i]);
	for(int i = 1;i <= n;i ++) scanf("%d", &h[i]);
	for(int i = 1;i <= 2 * n;i ++){
		if(i <= n) s[i] = s[i - 1] + d[i];
		else s[i] = s[i - 1] + d[i - n];
	}
	for(int i = 1;i <= 2 * n;i ++){
		if(i <= n) bin[i] = 2LL * h[i] - s[i - 1];
		else bin[i] = 2LL * h[i - n] - s[i - 1];
	}
	TL.build(1, 2 * n, 1);
	for(int i = 1;i <= 2 * n;i ++){
		if(i <= n) bin[i] = 2LL * h[i] + s[i - 1];
		else bin[i] = 2LL * h[i - n] + s[i - 1];
	}
	TR.build(1, 2 * n, 1);
	int x, y;
	while(Q --){
		scanf("%d%d", &x, &y);
		if(x > y) cout << work(y + 1, x - 1) << endl;
		else cout << max(work(1, x - 1), work(y + 1, n + x - 1)) << endl;
	}
	return 0;
}