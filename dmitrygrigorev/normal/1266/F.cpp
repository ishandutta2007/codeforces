#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<vector<int> > sticks;
vector<int> h;

int dfs(int vertex, int last) {
	int longest = 0;

	for (int i=0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to==last) continue;
		int len = dfs(to, vertex) + 1;
		sticks[vertex].push_back(len);
		longest = max(longest, len);
	}

	h[vertex] = longest;
	return longest;

} 

void dfs2(int vertex, int last, int fup) {
	if (vertex != 0) {
		sticks[vertex].push_back(fup);
	}
	fup++;

	int mx1 = -100, mx2 = -100;

	for (int i=0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		if (h[to]+1 > mx1) {
			mx2 = mx1;
			mx1 = h[to]+1;
		}
		else mx2 = max(mx2, h[to]+1);
	}
	for (int i=0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		if (h[to] + 1 != mx1) {
			dfs2(to, vertex, max(fup, mx1+1));
		}
		else dfs2(to, vertex, max(fup, mx2+1));
	}

}

int dfslong, dfslen;

void dfs3(int vertex, int last, int d) {
	if (d > dfslen) {
		dfslen = d, dfslong = vertex;
	}

	for (int i=0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to==last) continue;
		dfs3(to, vertex, d+1);
	}

}

int find_diameter() {
	dfslong = 0, dfslen = 0;
	dfs3(0, -1, 0);
	int Q = dfslong;
	dfs3(dfslong, -1, 0);
	return dfslen;
}

vector<bool> deleted;

void dlt(int x) {
	deleted[x] = true;
}

main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	data.assign(n, {});
	sticks.assign(n, {});
	h.assign(n, {});
	deleted.assign(n, false);

	vector<pair<int, int> > edges;

	for (int i=0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		if (u>v) swap(u, v);
		u--, v--;
		data[u].push_back(v), data[v].push_back(u);
		edges.push_back({u, v});
	}

	dfs(0, -1);
	dfs2(0, -1, 0);

	for (int i = 0; i < n; ++i) {
		sort(sticks[i].begin(), sticks[i].end(), greater<int>());
	}

	vector<pair<int, int> > kek;
	for (int i=0; i < n; ++i) {
		for (int j=0; j < sticks[i].size(); ++j) {
			kek.push_back({sticks[i][j], i});
		}
	}

	sort(kek.begin(), kek.end());
	int d = find_diameter();

	for (int i=0; i < n; ++i) {
		if (data[i].size() <= 2) dlt(i);
	}

	set<pair<int, int> > W;
	for (int i=0;i<n; ++i) {
		W.insert({-sticks[i].size(), i});
	}

	auto thtol = W.begin();
	cout << -(*thtol).first + 1 << " ";
	int u = 0;
	vector<int> stake;


	for (int k=2; k <= n; ++k) {
		if (k > d) {
			cout << 1 << " ";
			continue;
		}

		if (k % 2 == 0) {
			while (u < kek.size() && kek[u].first < k/2) {
				stake.push_back(kek[u++].second);
			}
			for (int i=0; i < stake.size(); ++i) {
				int T = stake[i];
				W.erase(W.find({-sticks[T].size(), T}));
				while (sticks[T].size() && sticks[T].back() < k/2) sticks[T].pop_back();
				if (sticks[T].size() <= 2) dlt(T);
				W.insert({-sticks[T].size(), T});
			}
			auto aaa = W.begin();
			int tut = max(2, -(*aaa).first);

			int st = 0;

			while (st < edges.size()) {
				int A = edges[st].first, B = edges[st].second;
				if (deleted[A] || deleted[B]) {
					swap(edges[st], edges.back());
					edges.pop_back();
					continue;
				}
				tut = max(tut, (int) (sticks[A].size() + sticks[B].size() - 2));
				st++;
			}
			cout << tut << " ";
			stake.clear();
		}
		else{
			while (u < kek.size() && kek[u].first < (k+1)/2) {
				stake.push_back(kek[u++].second);
			}
			for (int i=0; i < stake.size(); ++i) {
				int T = stake[i];
				W.erase(W.find({-sticks[T].size(), T}));
				while (sticks[T].size() > 1 && sticks[T][sticks[T].size() - 2] < (k+1)/2) sticks[T].pop_back();
				if (sticks[T].size() <= 2) dlt(T);
				W.insert({-sticks[T].size(), T});
			}
			auto aaa = W.begin();
			int tut = max(2, -(*aaa).first);
			cout << tut << " ";
		}
	}

}