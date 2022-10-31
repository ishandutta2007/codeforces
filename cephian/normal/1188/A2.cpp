#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int,int> pii;

const int N = 1005;
vector<pii> T[N];
int w[N], n;

vector<tuple<int,int,int>> ans;

int fix_odd(int v, int p = -1) {
	if(T[v].size() == 1) {
		if(w[T[v][0].second] % 2 == 0) {
			return -1;
		}
		return v;
	}
	bool par = 0;
	int last = -1;
	for(auto& x : T[v]) {
		if(x.first  == p) continue;
		int leaf = fix_odd(x.first, v);
		if(leaf != -1) {
			par ^= 1;
			w[x.second] -= 1;
			if(last == -1)
				last = leaf;
			else {
				cout << "matching " << leaf << " and " << last << endl;
				ans.emplace_back(leaf, last, 1);
				last = -1;
			}
		}
	}
	return last;
}

int nonleaf() {
	for(int i = 1; i <= n; ++i) {
		if(T[i].size() != 1)
			return i;
	}
	assert(false);
	return -1;
}

int get_one(int v, int p) {
	for(auto& x : T[v]) {
		if(x.first == p) continue;
		return get_one(x.first, v);
	}
	return v;
}

pair<int,int> get_two(int v, int p) {
	assert(T[v].size() >= 3);
	int a = -1;
	for(auto& x : T[v]) {
		if(x.first == p) continue;
		if(a == -1) a = get_one(x.first, v);
		else {
			return make_pair(a, get_one(x.first, v));
		}
	}
	assert(false);
	return make_pair(-1,-1);
}

bool leaf(int v) {
	return T[v].size() == 1;
}

bool removed[N] = {};

int compress(int v, int p = -1, int t = -1) {
	//cout << "here i am at " << v << endl;
	if(T[v].size() == 2) {
		for(auto& x : T[v]) {
			if(x.first == p) continue;
			// only runs once
			if(w[t] != w[x.second]) {
				cout << "NO\n";
				exit(0);
			}
			removed[v] = true;
			return compress(x.first, v, x.second);
		}
	}
	for(auto& x : T[v]) {
		if(x.first == p) continue;
		//cout << "going " << v << " to " << x.first << endl;
		x.first = compress(x.first, v, x.second);
	}
	return v;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v >> w[i];
		T[u].emplace_back(v, i);
		T[v].emplace_back(u, i);
	}

	if(n == 2) {
		cout << "YES\n" << endl;
		cout << "1\n 1 2 " << w[1] << "\n";
		return 0;
	}

	int root = nonleaf();

	// all match
	if(fix_odd(root) != -1) {
		cout << "NO\n";
		return 0;
	}

	//for(int i = 1; i <= n; ++i) {
	//	for(auto x : T[i])
	//		cout << i << " to " << x.first << " with wt index " << x.second << endl;
	//}

	// all even
	for(int i = 1; i < n; ++i) {
		if(w[i] % 2 != 0) {
			cout << "NO\n";
			return 0;
		}
	}

	// compress tree
	int lf = -1;
	for(int i = 1; i <= n; ++i) {
		if(leaf(i)) {
			lf = i;
			break;
		}
	}

	compress(lf);
	//cout << "made it out" << endl;

	for(int i = 1; i <= n; ++i) {
		if(removed[i]) continue;
		for(auto& x : T[i]) {
			int wt = w[x.second];
			if(wt == 0) continue;
			int u = i;
			int v = x.first;
			if(leaf(u) || leaf(v)) {
				if(leaf(v)) swap(u, v);
				// one leaf
				//cout << " proc " << u << "," << v << endl;
				int c, d;
				tie(c, d) = get_two(v, u);
				ans.emplace_back(u, c, wt/2);
				ans.emplace_back(u, d, wt/2);
				ans.emplace_back(c, d, -wt/2);
				w[x.second] = 0;
			} else {
				// no leaf
				//cout << " doin " << u << "," << v << endl;
				int a, b, c, d;
				tie(a,b) = get_two(u, v);
				tie(c,d) = get_two(v, u);
				//cout << " got " << a << " " << b << " " << c << " " << d << endl;
				ans.emplace_back(a, b, -wt/2);
				ans.emplace_back(c, d, -wt/2);
				ans.emplace_back(a, d, wt/2);
				ans.emplace_back(b, c, wt/2);
				w[x.second] = 0;
			}
		}
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); ++i) {
		int u, v, w;
		tie(u, v, w) = ans[i];
		cout << u << " " << v << " " << w << "\n";
	}
}