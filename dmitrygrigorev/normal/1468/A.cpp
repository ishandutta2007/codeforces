#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void relax(pair<int, int> &mx, pair<int, int> &mx2, pair<int, int> &a) {
	if (a > mx) {
		mx2 = mx;
		mx = a;
	}
	else mx2 = max(mx2, a);
}

struct Vertex {
	pair<int, int> mx;
	pair<int, int> mx2;
};

vector<Vertex> rmq;

Vertex gl;

void get(int i, int l, int r, int l1, int r1) {
	if (l1 >= r1) return;
	if (l==l1 && r==r1) {
		relax(gl.mx, gl.mx2, rmq[i].mx);
		relax(gl.mx, gl.mx2, rmq[i].mx2);
		return;
	}

	int mid = (l+r)/2;
	get(2*i+1, l, mid, l1, min(r1, mid));
	get(2*i+2, mid, r, max(l1, mid), r1);

}

void upd(int i, int l, int r, int index, int val, int Q) {
	if (r - l == 1) {
		rmq[i].mx = mp(val, -Q);
		return;
	}

	int mid = (l+r)/2;
	if (index < mid) upd(2*i+1, l, mid, index, val, Q);
	else upd(2*i+2, mid, r, index, val, Q);

	relax(rmq[i].mx, rmq[i].mx2, rmq[2*i+1].mx);
	relax(rmq[i].mx, rmq[i].mx2, rmq[2*i+1].mx2);

	relax(rmq[i].mx, rmq[i].mx2, rmq[2*i+2].mx);
	relax(rmq[i].mx, rmq[i].mx2, rmq[2*i+2].mx2);

}

void solve() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	int ans = 2;

	rmq.assign(4*n, {mp(-1e9, -1), mp(-1e9, -1)});

	reverse(all(v));
	int u = 0;

	vector<int> nxt(n, -1);
	vector<pair<int, int> > st;

	for (int i = 0; i < n; ++i) {
		while (st.size() && st.back().x < v[i]) st.pop_back();
		if (st.size()) nxt[i] = st.back().y;
		st.pb(mp(v[i], i)); 
	}

	for (auto x : v) {
		x--;
		gl = {mp(-1e9, -1), mp(-1e9, -1)};
		get(0, 0, n, x, n);

		int T = 1;

		auto p = gl.mx;

		if (-p.y == u - 1) {
			T = max(T, p.x + 1);
			p = gl.mx2;
		}
		u++;

		T = max(T, p.x + 1);
		if (nxt[u - 1] != -1 && nxt[u - 1] > (-p.y)) {
			T = max(T, p.x + 2);
		}

		//cout << x << " " << T << endl;

		ans = max(ans, T + (u != n));
		upd(0, 0, n, x, T, u-1);
	}

	cout << ans << '\n';

}

int main(){
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