//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

const int N = 10100;

std::vector<int> g[N];
int mt[N], used[N];

bool kuhn(int v, int it) {
	if (used[v] == it) {
		return false;
	}

	used[v] = it;

	for (auto to : g[v]) {
		if (mt[to] == -1) {
			mt[to] = v;
			return true;
		}
	}

	for (auto to : g[v]) {
		if (kuhn(mt[to], it)) {
			mt[to] = v;
			return true;
		}
	}

	return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for (auto& [i, x, y] : edges) {
    cin >> x >> y >> i;
    --x, --y;
  }
  sort(edges.begin(), edges.end());

  auto can = [&](int mid) {
  	for (int i = 0; i < n; ++i) {
  		g[i].clear();
  		mt[i] = -1;
  		used[i] = -1;
  	}
    // matching match(n, n);
    for (int i = 0; i < mid; ++i) {
      // match.add(get<1>(edges[i]), get<2>(edges[i]));
    	g[get<1>(edges[i])].push_back(get<2>(edges[i]));
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	if (kuhn(i, i)) {
    		++cnt;
    	}
    } 
    return cnt == n;
    // return match.solve() == n;
  };

  int l = 0; // cant
  int r = m + 1; // can
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << (r > m ? -1 : get<0>(edges[r - 1])) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}