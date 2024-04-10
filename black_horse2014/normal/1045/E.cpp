#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
int n;

struct pt{
	int x, y, c, id;
	pt () {}
	pt (int x, int y, int c) : x(x), y(y), c(c) {}
	void in(int i) { cin >> x >> y >> c; id = i; }
	bool operator < (const pt & p) const {
		return make_pair(x, y) < make_pair(p.x, p.y);
	}
	bool operator == (const pt &p) const {
		return id == p.id;
	}
} P[N];

int vect(pt p, pt p1, pt p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}

vector<pt> convex(vector<pt> &vec) {
	if (vec.size() <= 1) return vec;
	int n = vec.size(), k = 0;
	vector<pt> ch(2 * n);
	for (int i = 0; i < n; ch[k++] = vec[i++]) 
		while (k >= 2 && vect(ch[k - 2], ch[k - 1], vec[i]) <= 0) k--;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = vec[i--])
		while (k >= t && vect(ch[k - 2], ch[k - 1], vec[i]) <= 0) k--;
	ch.resize(k - 1);
	return ch;
}

vector<pair<int, int>> ans;

int sgn(int x) { return (x > 0) - (x < 0); }

bool isin(pt p, pt p1, pt p2, pt p3) {
	int sg1 = sgn(vect(p, p1, p2));
	int sg2 = sgn(vect(p, p2, p3));
	int sg3 = sgn(vect(p, p3, p1));
	return sg1 * sg2 == 1 && sg1 * sg3 == 1;
}

void insert(int x, int y) {
	if (x > y) swap(x, y);
	ans.emplace_back(x, y);
}

void solve(pt p, pt p1, pt p2) {
	vector<pt> in;
	for (int i = 1; i <= n; i++) {
		if (!isin(P[i], p, p1, p2)) continue;
		if (P[i].c == p.c) {
			solve(p1, P[i], p);
			solve(p2, P[i], p);
			solve(P[i], p1, p2);
			insert(i, p.id);
			return;
		}
		in.push_back(P[i]);
	}
	sort(in.begin(), in.end(), [&](pt a, pt b) {
		int v1 = abs(vect(a, p1, p2)), v2 = abs(vect(b, p1, p2));
		if (v1 != v2) return v1 < v2;
		return a < b;
	});
	if (in.size()) insert(p1.id, in[0].id);
	for (int i = 1; i < in.size(); i++) {
		insert(in[i-1].id, in[i].id);
	}
} 

void print() {
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << endl;
	for (auto t : ans) {
		cout << t.first-1 << ' ' << t.second-1 << endl;
	}
	exit(0);
}

int main() {
	cin >> n;
	vector<pt> all;
	for (int i = 1; i <= n; i++) P[i].in(i), all.push_back(P[i]);
	sort(all.begin(), all.end());
	auto ch = convex(all);
	int cnt = 0;
	for (int i = 0; i < ch.size(); i++) {
		pt p1 = ch[i], p2 = ch[(i+1)%ch.size()];
		if (p1.c != p2.c) cnt++;
	}
	if (cnt > 2) return puts("Impossible"), 0;
	if (cnt == 0) {
		for (int i = 1; i <= n; i++) {
			int flg = 0;
			for (pt c : ch) { 
				if (c == P[i]) {
					flg = 1;
					break;
				}
			}
			if (!flg && P[i].c != ch[0].c) {
				for (int j = 1; j < ch.size(); j++) {
					insert(ch[j-1].id, ch[j].id);
				}
				for (int j = 0; j < ch.size(); j++) {
					pt p1 = ch[j], p2 = ch[(j+1)%ch.size()];
					solve(P[i], p1, p2);
				}
				print();
			}
		}
		for (int i = 1; i < all.size(); i++) {
			insert(all[i-1].id, all[i].id);
		}
		print();
	}
	pt A, B;
	for (int i = 0; i < ch.size(); i++) {
		pt p1 = ch[i], p2 = ch[(i+1)%ch.size()];
		if (p1.c == p2.c) insert(p1.id, p2.id);
		if (p1.c == 0 && p2.c == 1) A = p1;
		if (p1.c == 1 && p2.c == 0) B = p1;
	}
	for (int i = 0; i < ch.size(); i++) {
		pt p1 = ch[i], p2 = ch[(i+1)%ch.size()];
		if (p1.c != p2.c) continue;
		if (p1.c == 0) solve(B, p1, p2);
		else solve(A, p1, p2);
	}
	print();
}