#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
      rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

struct Pt {
	ld x,y;
	Pt(ld a, ld b) : x(a), y(b) {}
	Pt() {}
};

typedef pair<ld, Pt> plp;

const ld eps = 1e-7;

bool EQ(ld a, ld b) {
	return abs(a-b) < eps;
}

bool operator<(Pt a, Pt b) {
	if (EQ(a.y,b.y)) return a.x < b.x;
	return a.y < b.y;
}

Pt operator-(Pt a, Pt b) {
	return Pt(a.x - b.x, a.y - b.y);
}

ld operator*(Pt a, Pt b) {
	return a.x*b.x + a.y*b.y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Pt> V(n);
	for (auto& p : V) cin >> p.x >> p.y;
	sort(V.begin(), V.end());
	ll res = 0;
	for (int in = 0; in < n-4; ++in) {
		vector<plp> vp;
		for (int i = in+1; i < n; ++i) {
			Pt c = V[i] - V[in];
			ld val = c.x/sqrt(c*c);
			vp.push_back({val,c});
		}
		int m = vp.size();
		ll D[m][m];
		memset(D, 0, sizeof(D));
		sort(vp.begin(), vp.end());
		for (int i = 0; i < m; ++i) {
			ordered_set<ld> S1,S2;
			auto vec = vp[i].second;
			ld c = sqrt(vec*vec);
			for (int j = 0; j < m; ++j) {
				if (i == j) continue;
				auto aux = vp[j].second;
				ld a = sqrt(aux*aux);
				auto v2 = aux - vec;
				ld b = sqrt(v2*v2);
				ld val = (a*a - b*b - c*c)/(2.0*b*c);
				if (j < i) S1.insert(val);
				else S2.insert(val);
			}
			for (int j = 0; j < m; ++j) {
				if (i == j) continue;
				auto aux = vp[j].second;
				ld a = sqrt(aux*aux);
				auto v2 = aux - vec;
				ld b = sqrt(v2*v2);
				ld val = (-a*a + b*b + c*c)/(2.0*b*c);
				if (i < j) D[i][j] = S1.order_of_key(val);
				else D[i][j] = S2.order_of_key(val);
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = i+1; j < m; ++j) {
				res += D[i][j]*D[j][i];
			}
		}
	}
	cout << res << '\n';
}