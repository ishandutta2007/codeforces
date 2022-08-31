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
	int zeros;
	int ones;
	int p;
};

vector<Vertex> rmq;

void build(int i, int l, int r, string &x) {
	if (r-l==1) {
		if (x[l] == '0') rmq[i].zeros++;
		else rmq[i].ones++;
		return;
	}

	int mid = (l+r)/2;
	build(2*i+1, l, mid, x);
	build(2*i+2, mid, r, x);

	rmq[i].zeros = rmq[2*i+1].zeros + rmq[2*i+2].zeros;
	rmq[i].ones = rmq[2*i+1].ones + rmq[2*i+2].ones;

}

void push(int i, int l, int r) {
	if (r-l <= 1) return;
	if (rmq[i].p == -1) return;

	if (rmq[i].p == 0) {
		int mid = (l+r)/2;
		rmq[2*i+1] = {mid - l, 0, 0};
		rmq[2*i+2] = {r - mid, 0, 0};

		rmq[i].p = -1;
		return;

	}

	int mid = (l+r)/2;
	rmq[2*i+1] = {0, mid - l, 1};
	rmq[2*i+2] = {0, r - mid, 1};

	rmq[i].p = -1;
	return;

}

pair<int, int> get(int i, int l, int r, int l1, int r1) {
	push(i, l, r);
	if (l1 >= r1) return mp(0, 0);
	if (l == l1 && r == r1) return mp(rmq[i].zeros, rmq[i].ones);

	int mid = (l+r)/2;
	auto A = get(2*i+1, l, mid, l1, min(r1, mid)), B = get(2*i+2, mid, r, max(l1, mid), r1);
	return mp(A.x+B.x, A.y+B.y);

}

void upd(int i, int l, int r, int l1, int r1, int t) {
	push(i, l, r);
	if (l1 >= r1) return;
	if (l == l1 && r == r1) {
		if (t == 0) {
			rmq[i] = {r-l, 0, 0};
			return;
		}
		else {
			rmq[i] = {0, r-l, 1};
			return;
		}
	} 

	int mid = (l+r)/2;
	upd(2*i+1, l, mid, l1, min(r1, mid), t);
	upd(2*i+2, mid, r, max(l1, mid), r1, t);

	rmq[i].zeros = rmq[2*i+1].zeros + rmq[2*i+2].zeros;
	rmq[i].ones = rmq[2*i+1].ones + rmq[2*i+2].ones;

}

void solve() {
	
	int n, q;
	cin >> n >> q;

	string s, t;
	cin >> s >> t;

	vector<pair<int, int> > queries(q);

	for (auto &x : queries) {
		cin >> x.x >> x.y;
		x.x--, x.y--;
	}

	rmq.assign(4*n, {0, 0, -1});
	build(0, 0, n, t);

	reverse(all(queries));

	for (auto x : queries) {
		pair<int, int> p = get(0, 0, n, x.x, x.y + 1);
		if (p.x == p.y) {
			cout << "NO\n";
			return;
		}

		if (p.x > p.y) {
			upd(0, 0, n, x.x, x.y + 1, 0);
		}
		else {
			upd(0, 0, n, x.x, x.y + 1, 1);
		}

	}

	for (int i = 0; i < n; ++i) {
		auto Q = get(0, 0, n, i, i+1);
		if (Q == mp(1, 0) && s[i] == '0') continue;
		if (Q == mp(0, 1) && s[i] == '1') continue;
		cout << "NO\n";
		return;
	}

	cout << "YES\n";



}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}