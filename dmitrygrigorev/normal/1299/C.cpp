#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex{db k; db b; db l; db r;int index;};

vector<Vertex> cht;

db inter(Vertex &a, Vertex &b) {
	return (b.b - a.b) / (a.k - b.k);
}

const db INF = 1e18;

int add(Vertex &x) {
	if (!cht.size()) {
		x.l = -INF, x.r = INF;
		cht.push_back(x);
		return -1;
	}

	while (true) {
		db I = inter(cht.back(), x);
		if (I >= cht.back().r) {
			cht.pop_back();
			continue;
		}
		cht.back().l = I;
		x.r = I;
		x.l = -INF;
		cht.push_back(x);
		return cht[cht.size() - 2].index;
	}

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += v[i];
	}
	vector<int> opt(n+1);
	for (int i = n; i >= 0; i--) {
		Vertex T = {-i, sum, -1, -1, i};
		int R = add(T);
		opt[i] = R;
		if (i==0) break;
		sum -= v[i-1];
	}
	cout.precision(10);

	int cur = 0;
	while (cur < n) {
		int go = opt[cur] - cur;
		ll tut = 0;
		for (int i = 0; i < go; ++i) {
			tut += v[cur+i];
		}
		for (int i = 0; i < go; ++i) {
			cout << fixed << (db) tut / (db) go << "\n";
		}
		cur += go;
	}

}