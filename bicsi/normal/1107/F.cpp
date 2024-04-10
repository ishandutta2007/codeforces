#include <bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
int MinAssignment(const vector<vector<T>> &c) {
  int n = c.size(), m = c[0].size();       // assert(n <= m);
  vector<T> v(m), dist(m);                 // v: potential
  vector<int> L(n, -1), R(m, -1);          // matching pairs
  vector<int> index(m), prev(m);
  iota(index.begin(), index.end(), 0);
  
  auto residue = [&](int i, int j) { return c[i][j] - v[j]; };
  for (int f = 0; f < n; ++f) {
    for (int j = 0; j < m; ++j) {
      dist[j] = residue(f, j); prev[j] = f;
    }
    T w; int j, l;
    for (int s = 0, t = 0;;) {
      if (s == t) {
        l = s; w = dist[index[t++]];
        for (int k = t; k < m; ++k) {
          j = index[k]; T h = dist[j];
          if (h <= w) {
            if (h < w) { t = s; w = h; }
            index[k] = index[t]; index[t++] = j;
          }
        }
        for (int k = s; k < t; ++k) {
          j = index[k];
          if (R[j] < 0) goto aug;
        }
      }
      int q = index[s++], i = R[q];
      for (int k = t; k < m; ++k) {
        j = index[k];
        T h = residue(i,j) - residue(i,q) + w;
        if (h < dist[j]) {
          dist[j] = h; prev[j] = i;
          if (h == w) {
            if (R[j] < 0) goto aug;
            index[k] = index[t]; index[t++] = j;
          }
        }
      }
    }
  aug:
    for(int k = 0; k < l; ++k)
      v[index[k]] += dist[index[k]] - w;
    int i;
    do {
      R[j] = i = prev[j];
      swap(j, L[i]);
    } while (i != f);
  }
  T ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += c[i][L[i]]; // (i, L[i]) is a solution
  }
  return ret;
}

int32_t main() {
    int n; cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        int a, b, k; cin >> a >> b >> k;
        for (int j = 0; j < n; ++j) {
            mat[i][j] = -a;
            if (j < k)
                a = max(0LL, a - b);
        }
    }
    cout << -MinAssignment(mat) << endl;
}