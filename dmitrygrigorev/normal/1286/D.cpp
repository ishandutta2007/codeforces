#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

int sum(int x, int y) {
	if (x+y < 0) return x+y+mod;
	if (x + y >= mod) return x+y-mod;
	return x+y;
}

int mult(int x, int y) {
	return ((ll) x * y) % mod;
}

struct Proton{int x; int v; int p_right; int p_left;};

int pw(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return mult(x, pw(x, y-1));
	int t = pw(x, y/2);
	return mult(t, t);
}

struct Event{ll dx; ll dt; int index; int type;};

bool cmp(Event &a, Event &b) {
	ll A = a.dx * b.dt, B = a.dt * b.dx;
	return (A<B);
}

struct Vertex{int f; int r; int L; int R;};
vector<Vertex> snm;

int get(int v) {
	if (snm[v].f != v) snm[v].f = get(snm[v].f);
	return snm[v].f;
}

void unite(int u, int v) {
	if (snm[u].r > snm[v].r) swap(u, v);
	snm[u].f = v;
	if (snm[u].r == snm[v].r) snm[v].r++;

	snm[v].L = min(snm[v].L, snm[u].L);
	snm[v].R = max(snm[v].R, snm[u].R);

}

struct RMQ {
	int mult_left; int mult_right; int mult_spec;
};

vector<RMQ> rmq;

void change(RMQ &res, RMQ &a, RMQ &b) {
	res.mult_left = mult(a.mult_left, b.mult_left);
	res.mult_right = mult(a.mult_right, b.mult_right);
	//cout << a.mult_right << " " << b.mult_right << " " << res.mult_right << endl;
	int A = sum(mult(a.mult_left, b.mult_spec), mult(a.mult_spec, b.mult_right));
	A = sum(A, -mult(a.mult_left, b.mult_right));
	res.mult_spec = A;
}

void build(int i, int l, int r, vector<Proton> &v) {
	if (r-l == 1){
		rmq[i] = {v[l].p_left, v[l].p_right, 1};
		return;
	}
	int mid = (l+r)/2;
	build(2*i+1, l, mid, v);
	build(2*i+2, mid, r, v);

	change(rmq[i], rmq[2*i+1], rmq[2*i+2]);

	//cout << i << "!!" << rmq[i].mult_right << endl;

}

bool Y = false;
RMQ subl;

int n;

void get(int i, int l, int r, int l1, int r1) {
	if (l1 >= r1) return;
	if (l==l1 && r==r1) {
		if (!Y) {
			Y = true;
			subl = rmq[i];
			return;
		}
		RMQ cp = subl;
		//cout << cp.mult_right << " " << rmq[i].mult_right << endl;
		change(subl, cp, rmq[i]);
		return;
	}

	int mid = (l+r)/2;
	get(2*i+1, l, mid, l1, min(r1, mid));
	get(2*i+2, mid, r, max(l1, mid), r1);
}

int get_res(multiset<int> &left, multiset<int> &right, int index){
	int G = get(index);
	int l = snm[G].L, r = snm[G].R;

	int must_l = 0, must_r = 0;

	if (left.size()) {
		auto it = left.upper_bound(r);
		if (it != left.begin()) {
			it--;
			int x = (*it);
			if (x >= l && x <= r) {
				must_l = x-l+1;
			}
		}
	}
	if (right.size()) {
		auto it = right.upper_bound(l-1);
		if (it != right.end()) {
			int x = (*it);
			if (x >= l && x <= r) {
				must_r = r-x+1;
			}
		}
	}

	//cout << must_l << " " << must_r << " " << l << " " << r << endl;

	if (must_l + must_r > r-l+1) return 0;

	//cout << must_l << " " << must_r << " " << l << " " << r << endl;

	int Q = 1;
	if (must_l != 0) {
		Y = false;
		get(0, 0, n, l, l + must_l);
		//cout << "===" << subl.mult_left << " " << l << " " << l+must_l << endl;
		Q = mult(Q, subl.mult_left);
	}
	if (must_r != 0) {
		Y = false;
		get(0, 0, n, r-must_r+1, r + 1);
		//cout << r-must_r+1 << " " << r << " " << subl.mult_right << endl;
		Q = mult(Q, subl.mult_right);
	}
	if (must_l + must_r != r-l+1){
	 	Y = false;
		get(0, 0, n, l+must_l, r - must_r + 1);
		Q = mult(Q, subl.mult_spec);
	}

	//cout << l << " "  << r << " " << Q << " " << must_l << " " << must_r << endl;

	return Q;


}


int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<Proton> v;
	int T = pw(100, mod-2);

	for (int i = 0; i < n; ++i) {
		Proton x;
		cin >> x.x >> x.v;
		int p;
		cin >> p;
		x.p_right = mult(p, T), x.p_left = mult(100 - p, T);
		v.push_back(x);
	}

	rmq.assign(4*n, {});
	build(0, 0, n, v);

	vector<Event> ev;
	for (int i = 0; i < n-1; ++i) {
		ll sum = v[i].v + v[i+1].v;
		ll delta = abs(v[i].x - v[i+1].x);
		ev.push_back({delta, sum, i, 1});

		sum = max(v[i].v, v[i+1].v) - min(v[i].v, v[i+1].v);
		if (sum != 0){
			ev.push_back({delta, sum, i, 2});
		}
	}

	sort(ev.begin(), ev.end(), cmp);
	for (int i = 0; i < n; ++i) {
		snm.push_back({i, 1, i, i});
	}

	int ans = 0;
	int current = 1;

	multiset<int> left, right;

	for (int i = 0; i < ev.size(); ++i) {
		int type = ev[i].type;
		int index = ev[i].index;


		if (type == 1) {
			int A = get_res(left, right, index);
			int B = get_res(left, right, index+1);
			current = mult(current, pw(A, mod-2));
			current = mult(current, pw(B, mod-2));

			int tut = current;
			right.insert(index), left.insert(index+1);
			A = get_res(left, right, index);
			B = get_res(left, right, index+1);
			tut = mult(tut, mult(A, B));

			ans = sum(ans, mult(tut, mult(ev[i].dx, pw(ev[i].dt, mod-2))));

			unite(get(index), get(index+1));
			right.erase(right.find(index));
			left.erase(left.find(index+1));
			current = mult(current, get_res(left, right, index));
		}

		else{

			int A = get_res(left, right, index);
			current = mult(current, pw(A, mod-2));

			int tut = current;
			if (v[index].v > v[index+1].v) {

				//cout << "==== " << index << endl;

				right.insert(index);
				right.insert(index+1);
				A = get_res(left, right, index);
				tut = mult(tut, A);
				ans = sum(ans, mult(tut, mult(ev[i].dx, pw(ev[i].dt, mod-2))));

				right.erase(right.find(index));
				right.erase(right.find(index+1));
				left.insert(index);
				current = mult(current, get_res(left, right, index));
			}
			else{
				left.insert(index);
				left.insert(index+1);
				A = get_res(left, right, index);
				tut = mult(tut, A);

				ans = sum(ans, mult(tut, mult(ev[i].dx, pw(ev[i].dt, mod-2))));

				left.erase(left.find(index));
				left.erase(left.find(index+1));
				right.insert(index+1);
				current = mult(current, get_res(left, right, index));
			}

		}
		//cout << ans << " " << type << endl;
	}
	cout << ans;

}