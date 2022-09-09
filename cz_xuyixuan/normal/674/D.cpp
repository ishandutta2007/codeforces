#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long long INF = 1e18;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct MaxHeap {
	priority_queue <ll> Heap, Delt;
	void ins(ll x) {Heap.push(x); }
	void del(ll x) {Delt.push(x); }
	ll top() {
		while (!Heap.empty() && !Delt.empty() && Heap.top() == Delt.top()) {
			Heap.pop();
			Delt.pop();
		}
		if (Heap.empty()) return -INF;
		else return Heap.top();
	}
} Max[MAXN];
struct MinHeap {
	priority_queue <ll, vector <ll>, greater <ll>> Heap, Delt;
	void ins(ll x) {Heap.push(x); }
	void del(ll x) {Delt.push(x); }
	ll top() {
		while (!Heap.empty() && !Delt.empty() && Heap.top() == Delt.top()) {
			Heap.pop();
			Delt.pop();
		}
		if (Heap.empty()) return INF;
		else return Heap.top();
	}
} Min[MAXN];
int n, q, f[MAXN], d[MAXN];
ll t[MAXN], inc[MAXN], val[MAXN];
void mod(int pos, ll d) {
	int x = f[pos];
	Max[0].del(Max[x].top() + inc[x]);
	Min[0].del(Min[x].top() + inc[x]);
	Max[x].del(val[pos]);
	Min[x].del(val[pos]);
	val[pos] += d;
	Max[x].ins(val[pos]);
	Min[x].ins(val[pos]);
	Max[0].ins(Max[x].top() + inc[x]);
	Min[0].ins(Min[x].top() + inc[x]);
}
void add(int x, ll d) {
	Max[0].del(Max[x].top() + inc[x]);
	Min[0].del(Min[x].top() + inc[x]);
	inc[x] += d;
	Max[0].ins(Max[x].top() + inc[x]);
	Min[0].ins(Min[x].top() + inc[x]);
}
void ins(int x, ll val) {
	Max[0].del(Max[x].top() + inc[x]);
	Min[0].del(Min[x].top() + inc[x]);
	Max[x].ins(val - inc[x]);
	Min[x].ins(val - inc[x]);
	Max[0].ins(Max[x].top() + inc[x]);
	Min[0].ins(Min[x].top() + inc[x]);
}
void del(int x, ll val) {
	Max[0].del(Max[x].top() + inc[x]);
	Min[0].del(Min[x].top() + inc[x]);
	Max[x].del(val - inc[x]);
	Min[x].del(val - inc[x]);
	Max[0].ins(Max[x].top() + inc[x]);
	Min[0].ins(Min[x].top() + inc[x]);
}
int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++)
		read(t[i]);
	for (int i = 1; i <= n; i++)
		read(f[i]), d[f[i]]++;
	for (int i = 1, j = f[i]; i <= n; i++, j = f[i]) {
		val[i] += t[i] - t[i] / (d[i] + 2) * (d[i] + 1);
		val[j] += t[i] / (d[i] + 2);
		val[i] += t[j] / (d[j] + 2);
	}
	for (int i = 1; i <= n; i++) {
		Max[f[i]].ins(val[i]);
		Min[f[i]].ins(val[i]);
	}
	for (int i = 1; i <= n; i++) {
		Max[0].ins(Max[i].top() + inc[i]);
		Min[0].ins(Min[i].top() + inc[i]);
	}
	while (q--) {
		int opt, x, y; read(opt);
		if (opt == 1) {
			read(x), read(y); int z = f[x];
			if (y == z) continue;
			val[x] += inc[z], del(z, val[x]);
			ll ov = t[z] / (d[z] + 2);
			ll nv = t[z] / (d[z] + 1);
			add(z, nv - ov), mod(f[z], nv - ov), mod(z, -t[x] / (d[x] + 2));
			mod(z, (t[z] - nv * (d[z] + 0)) - (t[z] - ov * (d[z] + 1)));
			val[x] -= ov;
			
			ov = t[y] / (d[y] + 2);
			nv = t[y] / (d[y] + 3);
			add(y, nv - ov), mod(f[y], nv - ov), mod(y, t[x] / (d[x] + 2));
			mod(y, (t[y] - nv * (d[y] + 2)) - (t[y] - ov * (d[y] + 1)));
			val[x] += nv - inc[y], ins(y, val[x] + inc[y]);
			
			d[z]--, d[y]++, f[x] = y;
		} else if (opt == 2) {
			int x; read(x);
			printf("%lld\n", val[x] + inc[f[x]]);
		} else printf("%lld %lld\n", Min[0].top(), Max[0].top());
	}
	return 0;
}