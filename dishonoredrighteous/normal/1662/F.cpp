//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

int const INF = int(1e9);
struct SegTree {
  int n;
  vector<pair<int, int>> rmq;
  int pw;

  SegTree(vector<int> a) {
    n = int(a.size());
    pw = 1;
    while (pw < n) pw *= 2;
    rmq.resize(2 * pw, make_pair(INF, -1));
    for (int i = 0; i < n; ++i) {
      rmq[pw + i] = make_pair(a[i], i);
    }
    for (int i = pw - 1; i > 0; --i) {
      rmq[i] = min(rmq[2 * i], rmq[2 * i + 1]);
    }
  }

  pair<int, int> get(int l, int r) {
    pair<int, int> res{INF, -1};
    for (l += pw, r += pw; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        smin(res, rmq[l++]);
      }
      if (r & 1) {
        smin(res, rmq[--r]);
      }
    }
    return res;
  }

  void kill(int i) {
    for (rmq[i += pw] = make_pair(INF, -1); i /= 2; ) {
      rmq[i] = min(rmq[2 * i], rmq[2 * i + 1]);
    }
  }
};

void solveTest() {
  int n, s, t;
  cin >> n >> s >> t;
  --s, --t;
  vector<int> p(n);
  for (int& x : p) {
    cin >> x;
  }
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i - p[i];
    b[i] = -i - p[i];
  }
  SegTree ta(a), tb(b);

  vector<int> dist(n, -1);
  queue<int> q;

  auto Add = [&](int i, int d) {
    assert(dist[i] == -1);
    dist[i] = d;
    ta.kill(i);
    tb.kill(i);
    q.push(i);
  };

  Add(s, 0);

  auto GoLeft = [&](int i, int d) {
    int from = i - p[i];
    int to = i;
    smax(from, 0);
    while (true) {
      auto[val, pos] = tb.get(from, to);
      // debug("left");
      // debug(val);
      // debug(pos);
      if (val > -i) {
        break;
      }
      Add(pos, d);
    }
  };
  auto GoRight = [&](int i, int d) {
    int from = i;
    int to = p[i] + i;
    smin(to, n - 1);
    ++to;
    while (true) {
      auto[val, pos] = ta.get(from, to);
      // debug("right");
      // debug(val);
      // debug(pos);
      if (val > i) {
        break;
      }
      Add(pos, d);
    }
  };

  while (!q.empty()) {
    int i = q.front(); q.pop();
    GoRight(i, dist[i] + 1);
    GoLeft(i, dist[i] + 1);
  }

  cout << dist[t] << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solveTest();
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}