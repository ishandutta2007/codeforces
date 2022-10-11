#include <iostream>
#include <vector>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

class MergeTech {
public:
	vector<long long> group, dat;
	vector<vector<long long>>G;

	void init(int sz) {
		group.resize(sz, 0);
		G.resize(sz, vector<long long>(0, 0));
		dat.resize(sz, 0);

		for (int i = 0; i < sz; i++) { group[i] = i; G[i].push_back(i); }
	}
	bool same(int u, int v) {
		if (group[u] == group[v]) return true;
		return false;
	}
	void unite(int u, int v, long long x) {
		long long E = (x ^ (dat[u] ^ dat[v]));
		u = group[u]; v = group[v];
		if (G[u].size() < G[v].size()) swap(u, v);

		for (int i = 0; i < G[v].size(); i++) {
			dat[G[v][i]] ^= E;
			group[G[v][i]] = u;
			G[u].push_back(G[v][i]);
		}
		G[v].clear();
	}
};

long long Q, last, cnts; map<long long, int>Map;

int main() {
	scanf("%lld", &Q);

	MergeTech Z; Z.init(Q * 2);
	for (int i = 1; i <= Q; i++) {
		long long ty; scanf("%lld", &ty);
		if (ty == 1) {
			long long l, r, x; scanf("%lld%lld%lld", &l, &r, &x);
			l ^= last; r ^= last; x ^= last; if (l > r) swap(l, r); r++;
			if (Map[l] == 0) { cnts++; Map[l] = cnts; l = cnts; }
			else l = Map[l];
			if (Map[r] == 0) { cnts++; Map[r] = cnts; r = cnts; }
			else r = Map[r];

			if (Z.same(l, r) == false) Z.unite(l, r, x);
		}
		if (ty == 2) {
			long long l, r; scanf("%lld%lld", &l, &r);
			l ^= last; r ^= last; if (l > r) swap(l, r); r++;
			if (Map[l] == 0) { cnts++; Map[l] = cnts; l = cnts; }
			else l = Map[l];
			if (Map[r] == 0) { cnts++; Map[r] = cnts; r = cnts; }
			else r = Map[r];

			long long ans = -1;
			if (Z.same(l, r) == false) ans = -1;
			else ans = (Z.dat[l] ^ Z.dat[r]);

			printf("%lld\n", ans);
			last = ans; if (last == -1) last = 1;
		}
	}
	return 0;
}