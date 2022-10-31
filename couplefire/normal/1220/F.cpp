#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, p, k, a[N], b[N];
pii t[N << 2];
int tt[N << 2], u[N << 2];
pii ans;
int L[N], R[N];
void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = {b[tl], tl};
		return;	
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}
pii get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l || l > r)
		return {inf, inf};
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return min(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}
void upd(int v, int tl, int tr, int l, int r, int k){
	if(r < tl || tr < l || l > r)
		return;
	if(l <= tl && tr <= r){
		tt[v] += k;
		u[v] += k;		
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, r, k);
	upd(v << 1 | 1, tm + 1, tr, l, r, k);
	tt[v] = max(tt[v << 1], tt[v << 1 | 1]) + u[v];
}
void ff(int l, int r, int pr){
	if(l > r)
		return;
	int i = get(1, 0, k - 1, l, r).s;
	L[i] = l;
	R[i] = r;
	ff(l, i - 1, i);
	ff(i + 1, r, i);
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
		if(a[i] == 0)
			p = i;	
	}
	for(int i = 1; i < n; i++)
		b[k++] = a[(p + i) % n];
	b[k++] = a[p];
	for(int i = 1; i < n; i++)
		b[k++] = a[(p + i) % n];
	build(1, 0, k - 1);	
	ff(0, k - 1, -1);
	
	for(int i = 0; i < n; i++)
		upd(1, 0, k - 1, L[i], R[i], 1);
	ans = {inf, inf};
	for(int i = 0; i < n; i++){
		pii cur = {tt[1], (p + i + 1) % n};
		ans = min(ans, cur);
		upd(1, 0, k - 1, L[i], R[i], -1);	
		upd(1, 0, k - 1, L[n + i], R[n + i], 1);
	}
	printf("%d %d", ans.f, ans.s);	
	return 0;
}