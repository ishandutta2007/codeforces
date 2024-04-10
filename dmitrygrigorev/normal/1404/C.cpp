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
	int leftest;
	int add;
};

vector<Vertex> rmq;

void push(int i, int l, int r) {
	if (r - l <= 1) return;
	int x = rmq[i].add;

	rmq[i].add = 0;
	for (int j = 2*i+1; j <= 2*i+2; ++j) {
		rmq[j].add += x;
		rmq[j].leftest += x;
	}

}

int get(int i, int l, int r, int x) {

	//cout << i << " " << l << " " << r << " " << rmq[i].leftest << " " << x << endl;

	push(i, l, r);

	if (r - l == 1) {
		if (rmq[i].leftest >= x) return l+1;
		return l;
	}

	int mid = (l+r)/2;
	if (rmq[2*i+2].leftest >= x) {
		return get(2*i+2, mid, r, x);
	}
	return get(2*i+1, l, mid, x);

}

void add(int i, int l, int r, int l1, int r1) {
	push(i, l, r);
	if (l1 >= r1) return;
	if (l == l1 && r == r1) {
		rmq[i].add++;
		rmq[i].leftest++;
		return;
	}

	int mid = (l+r)/2;
	add(2*i+1, l, mid, l1, min(r1, mid));
	add(2*i+2, mid, r, max(l1, mid), r1);

	rmq[i].leftest = rmq[2*i+1].leftest;

}

int get_val(int i, int l, int r, int index) {
	if (r-l==1) return rmq[i].leftest;

	push(i, l, r);
	int mid = (l+r)/2;

	if (index < mid) return get_val(2*i+1, l, mid, index);
	return get_val(2*i+2, mid, r, index);

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<int> ans(q);

	vector<vector<pair<int, int> > > queries(n);
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;

		queries[y].pb(mp(x, i));
	}

	rmq.assign(4*n, {0, 0});
	for (int i = 0; i < n; ++i) {
		int must_delete = (i+1) - v[i];
		if (must_delete < 0) {
			for (auto query : queries[n - i - 1]) {
				ans[query.y] = get_val(0, 0, n, query.x);
			}
			continue;
		}

		int take = min(i + 1, get(0, 0, n, must_delete));

		add(0, 0, n, 0, take);

		for (auto query : queries[n - i - 1]) {
			ans[query.y] = get_val(0, 0, n, query.x);
		}

	}

	for (auto x : ans) cout << x << "\n";

}