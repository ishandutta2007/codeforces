#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int N = 22000;

int x[N], y[N];

bool cmp(int a, int b) { return make_pair(x[a], y[a]) < make_pair(x[b], y[b]); }

int scal(int p, int p1, int p2) {
	return (x[p1] - x[p]) * (x[p2] - x[p]) + (y[p1] - y[p]) * (y[p2] - y[p]);
}

int vect(int p, int p1, int p2) {
	return (x[p1] - x[p]) * (y[p2] - y[p]) - (x[p2] - x[p]) * (y[p1] - y[p]);
}

bool cmp(pii p1, pii p2) {
	return 1LL * p1.first * p2.second < 1LL * p1.second * p2.first;
}

bool lcmp(pii p1, pii p2) {
	return 1LL * p1.first * p2.second <= 1LL * p1.second * p2.first;
}

inline int sqr(int v) { return v * v; }

int dis2(int a, int b) {
	return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}

pii den(int p, int p1, int p2) {
	int s = scal(p, p1, p2), v = vect(p, p1, p2);
	return pii(s, abs(v));
}

vector<int> convex(vector<int> ps) {
	if (ps.size() <= 1) return ps; 
	sort(ps.begin(), ps.end(), [](int a, int b) { return cmp(a, b); });
	int n = ps.size(), k = 0;
	vector<int> ch(n + n);
	for (int i = 0; i < n; ch[k++] = ps[i++])
		while (k >= 2 && vect(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--])
		while (k >= t && vect(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	ch.resize(k - 1);
	return ch;
}

vector<pair<int, int>> vp;
vector<int> ch;

void split(vector<int> vec) {
	if (vec.size() <= 3) return;
	pii ma = {INT_MIN, 1};
	int id = -1;
	for (int i = 2; i < vec.size(); i++) {
		pii vv = den(ch[vec[i]], ch[vec[0]], ch[vec[1]]);
		if (cmp(ma, vv)) ma = vv, id = i;
	}
	assert(id != -1);
	if (id != vec.size()-1) vp.emplace_back(vec[0], vec[id]);
	if (id != 2) vp.emplace_back(vec[1], vec[id]);
	vector<int> ve;
	if (id > 3) {
		for (int i = 1; i <= id; i++) ve.push_back(vec[i]);
		assert(ve.size() < vec.size());
		split(ve);
	}
	if (id < vec.size() - 2) {
		ve.clear();
		for (int i = id; i < vec.size(); i++) ve.push_back(vec[i]);
		ve.push_back(vec[0]);
		assert(ve.size() < vec.size());
		split(ve);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cerr.setf(ios::fixed), cerr << setprecision(16);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n+m; i++) cin >> x[i] >> y[i];
	if (n == 1 || m == 1) return cout << "YES" << endl, 0;
	for (int T : {0, 1}) {
		vp.clear();
		vector<int> ps, sp;
		for (int i = 0; i < n; i++) ps.push_back(i);
		ch = convex(ps);
		for (int i = 0; i < ch.size(); i++) {
			vp.emplace_back(i, (i+1)%ch.size());
			sp.push_back(i);
		}
		split(sp);
		for (auto t : vp) {
			int a = t.first, b = t.second;
			if (a > b) swap(a, b);
			int A = ch[a], B = ch[b];
			pii Rmi = {INT_MAX, 1}, Lmi = {INT_MAX, 1};
			int flg = 0;
			for (int i = n; i < n+m; i++) {
				int v = vect(i, A, B), s = scal(i, A, B);
				if (v == 0) {
					if (s < 0) {
						flg = 1;
						break;
					} else {
						continue;
					}
				}
				pii cc = pii(s, abs(v));
				if (v > 0) {
					if (cmp(cc, Rmi)) Rmi = cc;
				} else if (cmp(cc, Lmi)) Lmi = cc;
			}
			if (flg) continue;
			Lmi.first *= -1;
			if (lcmp(Rmi, Lmi)) continue;
			Lmi.first *= -1;
			pii rma = {INT_MIN, 1}, lma = {INT_MIN, 1};
			for (int i = a+1; i < b; i++) {
				pii cc = den(ch[i], A, B);
				if (cmp(lma, cc)) lma = cc;
			}
			if (lcmp(Lmi, lma)) continue;
			int cn = ch.size();
			for (int i = b+1; i < a+cn; i++) {
				pii cc = den(ch[i % cn], A, B);
				if (cmp(rma, cc)) rma = cc;
			}
			if (lcmp(Rmi, rma)) continue;
			cout << "YES" << endl;
			return 0;
		}
		reverse(x, x + n + m);
		reverse(y, y + n + m);
		swap(n, m);
	}
	cout << "NO" << endl;
}