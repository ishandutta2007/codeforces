#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
	int minimum;
	ll sum;
	int p;
};

vector<Vertex> rmq;

void build(int i, int l, int r, vector<int> &v) {
	if (r-l==1) {
		rmq[i] = {v[l], v[l], 0};
		return;
	}

	int mid = (l+r)/2;
	build(2*i+1, l, mid, v);
	build(2*i+2, mid, r, v);

	rmq[i].minimum = min(rmq[2*i+1].minimum, rmq[2*i+2].minimum);
	rmq[i].sum = rmq[2*i+1].sum + rmq[2*i+2].sum;
	rmq[i].p = 0;

}

void push(int i, int l, int r) {
	if (r-l<=1) return;

	int p = rmq[i].p;
	rmq[i].p = 0;
	if (p == 0) return;

	int mid = (l+r)/2;
	rmq[2*i+1].minimum = p;
	rmq[2*i+1].p = p;
	rmq[2*i+1].sum = (ll) p * (mid - l);

	rmq[2*i+2].minimum = p;
	rmq[2*i+2].p = p;
	rmq[2*i+2].sum = (ll) p * (r - mid);
}

void upd(int i, int l, int r, int l1, int r1, int x) {

	push(i, l, r);

	if (l1 >= r1) return;

	if (l==l1 && r==r1) {
		rmq[i] = {x, (ll) x * (r - l), x};
		return;
	}

	int mid = (l+r)/2;
	upd(2*i+1, l, mid, l1, min(r1, mid), x);
	upd(2*i+2, mid, r, max(l1, mid), r1, x);

	rmq[i].minimum = min(rmq[2*i+1].minimum, rmq[2*i+2].minimum);
	rmq[i].sum = rmq[2*i+1].sum + rmq[2*i+2].sum;
	rmq[i].p = 0;

}

int n;

int down(int i, int l, int r, int x) {

	push(i, l, r);

	if (r-l==1) return l;

	int mid = (l+r)/2;
	if (rmq[2*i+1].minimum <= x) return down(2*i+1, l, mid, x);
	return down(2*i+2, mid, r, x);

}

int get(int i, int l, int r, int l1, int r1, int x) {
	push(i, l, r);

	if (l1 >= r1) return -1;
	if (l == l1 && r == r1) {
		if (rmq[i].minimum <= x) return down(i, l, r, x);
		return -1;
	}

	int mid = (l+r)/2;
	auto res = get(2*i+1, l, mid, l1, min(r1, mid), x);

	if (res != -1) return res;
	return get(2*i+2, mid, r, max(l1, mid), r1, x);

}

ll cur_val;
ll take;
int tut;

void down2(int i, int l, int r) {
	push(i, l, r);

	if (r-l==1) return;

	int mid = (l+r)/2;

	if (rmq[2*i+1].sum <= cur_val) {
		cur_val -= rmq[2*i+1].sum;
		take += rmq[2*i+1].sum;
		tut += mid - l;
		down2(2*i+2, mid, r);
		return;
	}
	
	down2(2*i+1, l, mid);

}

void go(int i, int l, int r, int l1, int r1) {
	push(i, l, r);

	if (l1 >= r1) return;
	if (l==l1 && r==r1) {
		if (rmq[i].sum <= cur_val) {
			cur_val -= rmq[i].sum;
			take += rmq[i].sum;
			tut += r-l;
			return;
		}
		down2(i, l, r);
		cur_val = 0;
		return;
	}

	int mid = (l+r)/2;
	go(2*i+1, l, mid, l1, min(r1, mid));

	if (cur_val == 0) return;
	go(2*i+2, mid, r, max(l1, mid), r1);


}

void ask(int l, int x) {

	int ans = 0;

	while (l < n) {

		int W = get(0, 0, n, l, n, x);
		if (W == -1) break;

		l = W;

		cur_val = x;
		tut = 0;
		take = 0;

		go(0, 0, n, l, n);

		ans += tut;
		l += tut;
		x -= take;


	}

	cout << ans << '\n';

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> q;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	rmq.assign(4*n, {});

	build(0, 0, n, v);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;

		if (t == 1) {
			int x, y;
			cin >> x >> y;
			int W = get(0, 0, n, 0, x, y);

			if (W != -1) {
				upd(0, 0, n, W, x, y);
			}

		}

		else {
			int x, y;
			cin >> x >> y;
			ask(x - 1, y);
		}

	}

}