#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

struct Sweet {
	int x;
	int y;
	int colour;
};

void change(vector<int> &v, int &x) {

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] >= x) {
			x = i - 1;
			return;
		}
	}

}

vector<int> suff_sum;

bool cmp(Sweet &a, Sweet &b) {
	return (a.y > b.y);
}

bool cmp2(Sweet &a, Sweet &b) {
	return (a.x > b.x);
}

struct Vertex {
	int leftest;
	int sum;
	int sum_factor;
	int p;
};

vector<Vertex> rmq;
vector<int> gy;

void build(int i, int l, int r, vector<int> &v) {

	if (r - l == 1) {
		rmq[i] = {v[l], ((ll) suff_sum[v[l]] * gy[l]) % mod, gy[l], -1};
		return;
	}

	int mid = (l+r)/2;
	build(2*i+1, l, mid, v);
	build(2*i+2, mid, r, v);

	rmq[i].leftest = rmq[2*i+1].leftest;
	rmq[i].sum = (rmq[2*i+1].sum + rmq[2*i+2].sum) % mod;
	rmq[i].sum_factor = (rmq[2*i+1].sum_factor + rmq[2*i+2].sum_factor) % mod;


}

void push(int i, int l, int r) {
	if (rmq[i].p == -1 || r - l <= 1) return;

	int Q = rmq[i].p;
	rmq[i].p = -1;

	rmq[2*i+1].p = Q;
	rmq[2*i+1].sum = ((ll) suff_sum[Q] * rmq[2*i+1].sum_factor) % mod;
	rmq[2*i+1].leftest = Q;

	rmq[2*i+2].p = Q;
	rmq[2*i+2].sum = ((ll) suff_sum[Q] * rmq[2*i+2].sum_factor) % mod;
	rmq[2*i+2].leftest = Q;


}

int get(int i, int l, int r, int x) {

	push(i, l, r);
	if (r - l == 1) {
		if (rmq[i].leftest >= x) return 1;
		return 0;
	}

	int mid = (l+r)/2;

	if (rmq[2*i+2].leftest < x) {
		return get(2*i+1, l, mid, x);
	}
	return (mid - l) + get(2*i+2, mid, r, x);

}



void apply(int i, int l, int r, int l1, int r1, int Q) {

	push(i, l, r);
	if (l1 >= r1) return;
	if (l == l1 && r == r1) {
		rmq[i].p = Q;
		rmq[i].sum = ((ll) suff_sum[Q] * rmq[i].sum_factor) % mod;
		rmq[i].leftest = Q;
		return;
	}
	int mid = (l+r)/2;
	apply(2*i+1, l, mid, l1, min(r1, mid), Q);
	apply(2*i+2, mid, r, max(l1, mid), r1, Q);

	rmq[i].leftest = rmq[2*i+1].leftest;
	rmq[i].sum = (rmq[2*i+1].sum + rmq[2*i+2].sum) % mod;

}

void process(int n, int x, int val) {

	int cnt = get(0, 0, n, val);
	cnt -= x;

	cnt = max(cnt, 0);

	apply(0, 0, n, x, x + cnt, val);

}

void solve(vector<int> &x, vector<int> &y, vector<Sweet> &v, int k) {

	gy = y;

	int ans = 0;
	suff_sum.pb(0);

	reverse(all(y));
	for (auto x : y) suff_sum.pb(suff_sum.back() + x);
	reverse(all(y));

	for (int pos = 0; pos + 1 < x.size(); ++pos) {

		sort(all(v), cmp);

		int here = 0;
		vector<multiset<int> > arr(k);

		for (auto sweet : v) {
			if (sweet.x < pos) continue;
			arr[sweet.colour].insert(sweet.y);
		}

		vector<int> can_take(y.size());

		vector<int> mx_arr(y.size() + 1, 0);
		mx_arr.back() = k;
		int cur_mx = y.size();

		vector<int> now_opt(k, y.size());

		int u = 0;
		for (int j = y.size() - 1; j >= 0; j--) {
			while (u < v.size() && v[u].y >= j) {
				if (v[u].x < pos) {
					u++;
					continue;
				}
				int Q = v[u].colour;
				if (now_opt[Q] > j+1) {
					mx_arr[now_opt[Q]]--;
					now_opt[Q] = j+1;
					mx_arr[now_opt[Q]]++;
				}
				u++;
			}
			while (mx_arr[cur_mx] == 0) cur_mx--;
			can_take[j] = y.size() - cur_mx;
		}

		rmq.assign(4*y.size(), {0, 0, 0, -1});
		build(0, 0, y.size(), can_take);

		sort(all(v), cmp2);
		u = 0;

		for (int bound = x.size() - 1; bound > pos; bound--) {

			here += ((ll) rmq[0].sum * x[bound]) % mod;
			here %= mod;

			while (u < v.size() && v[u].x == bound - 1) {


				int C = v[u].colour;
				int Y = v[u].y;

				arr[C].erase(arr[C].find(Y));

				int new_reality;

				auto it = arr[C].upper_bound(Y);
				if (it == arr[C].end()) new_reality = 0;
				else new_reality = y.size() - (*it) - 1;

				int start;

				if (!arr[C].size() || it == arr[C].begin()) {
					start = 0;
				}

				else {
					it--;
					start = (*it) + 1;
				}

				process(y.size(), start, new_reality);
				u++;
			}

		}

		here = ((ll) here * x[pos]) % mod;

		ans += here;
		ans %= mod;

	}

	cout << ans;

}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, l;
	cin >> n >> k >> l;

	vector<Sweet> v;

	set<int> xm, ym;
	xm.insert(-1), xm.insert(l), ym.insert(-1), ym.insert(l);

	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		xm.insert(x);
		ym.insert(y);
		v.pb({x, y, z});
	}

	vector<int> vx, vy;
	for (auto p : xm) vx.pb(p);
	for (auto p : ym) vy.pb(p);

	for (auto &s : v) {
		change(vx, s.x);
		change(vy, s.y);
		s.colour--;
	}

	vector<int> var_x, var_y;
	for (int i = 1; i < vx.size(); ++i) {
		var_x.pb(vx[i] - vx[i-1]);
	}

	for (int i = 1; i < vy.size(); ++i) {
		var_y.pb(vy[i] - vy[i-1]);
	}

	solve(var_x, var_y, v, k);

}