#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef pair<int, int> pii;

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = (gr).size();
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = gr[x].size();
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || ret.size() != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<pii>> gr(k);
  for (int i=0; i<k; ++i) {
    for (int j=0; j<k; ++j) {
      gr[i].push_back({j, i*k+j});
    }
  }
  auto wlk = eulerWalk(gr, k*k);
  for (int i=0; i<n; ++i) {
    int j = i%(k*k);
    cout << (char) (wlk[j] + 'a');
  }
  cout << "\n";

  return 0;
}