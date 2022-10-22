#include <bits/stdc++.h>
using namespace std;
const int MN = 1e4 + 5, MM = 30;
struct Basis {
	array<int,2> basis[MM];
	int rep[MM];
	bool at[MN];
	Basis () {
		for (int i = 0; i < MM; i++) basis[i] = {0,0}, rep[i] = 0;
		for (int i = 0; i < MN; i++) at[i] = false;
	}
	void insert (int x, int id) {
		int wee = 0;
		for (int i = MM-1; i >= 0; i--) if (x >> i & 1) {
			if (!basis[i][0]) {
				basis[i] = {x,id};
				rep[i] = wee | (1 << i);
				at[id] = true;
				return;
			}
			else {
				x ^= basis[i][0];
				wee ^= rep[i];
			}
		}
	}
	bool query (int x) {
		for (int i = MM-1; i >= 0; i--) if (x >> i & 1) {
			if (!basis[i][0]) return false;
			x ^= basis[i][0];
		}
		assert(x == 0);
		return true;
	}
	vector<int> getRep (int x) {
		int wee = 0;
		for (int i = MM-1; i >= 0; i--) if (x >> i & 1) {
			assert(basis[i][0]);
			x ^= basis[i][0];
			wee ^= rep[i];
		}
		vector<int> ret;
		for (int i = 0; i < MM; i++) if (wee >> i & 1) ret.push_back(basis[i][1]);
		return ret;
	}
};
int x[MN], y[MN];
bool done[MN];
int main () {
	int n; scanf ("%d",&n);
	Basis B = Basis();
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&x[i]);
		B.insert(x[i],i);
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&y[i]);
		if (!B.query(y[i])) {
			printf ("-1\n");
			return 0;
		}
	}
	vector<array<int,2>> ret;
	vector<int> later;
	for (int i = 1; i <= n; i++) if (!B.at[i]) {
		vector<int> go = B.getRep(y[i]);
		ret.push_back({i,i}); x[i] = 0;
		for (int j : go) {
			assert(j != i);
			ret.push_back({i,j});
			x[i] ^= x[j];
		}
	} else later.push_back(i);
	Basis Y = Basis();
	for (int i : later) Y.insert(y[i],i);
	for (int i : later) if (Y.at[i]) {
		Basis X = Basis();
		for (int j : later) X.insert(x[j],j);
		vector<int> v = X.getRep(y[i]);
		bool found = false;
		for (int j : v) if (!done[j]) {
			found = true;
			for (int k : v) if (k != j) ret.push_back({j,k}), x[j] ^= x[k];
			if (i != j) {
				swap(x[i],x[j]);
				ret.push_back({i,j});
				ret.push_back({j,i});
				ret.push_back({i,j});
			}
			break;
		}
		assert(found);
		done[i] = true;
	}
	for (int i : later) if (!Y.at[i]) {
		vector<int> v = Y.getRep(y[i]);
		ret.push_back({i,i}); x[i] = 0;
		for (int j : v) ret.push_back({i,j}), x[i] ^= x[j];
	}
	printf ("%d\n",(int)ret.size());
	for (auto [i,j] : ret) printf ("%d %d\n",i,j);
	for (int i = 1; i <= n; i++) assert(x[i] == y[i]);
	return 0;
}