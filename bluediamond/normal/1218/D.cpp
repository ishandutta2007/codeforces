#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int pw(int a, int b, int M) {
  int r = 1;
  while (b) {
    if (b & 1) r = (ll) r * a % M;
    a = (ll) a * a % M;
    b /= 2;
  }
  return r;
}

int inv(int a, int M) {
  return pw(a, M - 2, M);
}


const int M = (int) 1e9 + 7;
const int M2 = (int) 1e9 + 123123;

const int A = (1 << 17);
const int IA1 = inv(A, M), IA2 = inv(A, M2);

void fft(vector<pair<int, int>> &a) {
  for (int l = 2; l <= A; l *= 2) {
    for (int i = 0; i < A; i += l) {
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j].first + a[i + l / 2 + j].first, y = a[i + j].first - a[i + l / 2 + j].first;
        if (x >= M) x -= M;
        if (y < 0) y += M;
        a[i + j].first = x;
        a[i + l / 2 + j].first = y;

        x = a[i + j].second + a[i + l / 2 + j].second, y = a[i + j].second - a[i + l / 2 + j].second;
        if (x >= M2) x -= M2;
        if (y < 0) y += M2;
        a[i + j].second = x;
        a[i + l / 2 + j].second = y;
      }
    }
  }
}

void fftrev(vector<pair<int, int>> &a) {
  for (int l = 2; l <= A; l *= 2) {
    for (int i = 0; i < A; i += l) {
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j].first + a[i + l / 2 + j].first, y = a[i + j].first - a[i + l / 2 + j].first;
        if (x >= M) x -= M;
        if (y < 0) y += M;
        a[i + j].first = x;
        a[i + l / 2 + j].first = y;

        x = a[i + j].second + a[i + l / 2 + j].second, y = a[i + j].second - a[i + l / 2 + j].second;
        if (x >= M2) x -= M2;
        if (y < 0) y += M2;
        a[i + j].second = x;
        a[i + l / 2 + j].second = y;
      }
    }
  }
  for (auto &x : a) {
    x.first = (ll) x.first * IA1 % M;
    x.second = (ll) x.second * IA2 % M2;
  }
}

vector<pair<int, int>> xorConvolution(vector<pair<int, int>> a, vector<pair<int, int>> b) {
  fft(a);
  fft(b);
  for (int i = 0; i < A; i++) {
    a[i].first = (ll) a[i].first * b[i].first % M;
    a[i].second = (ll) a[i].second * b[i].second % M2;
  }
  fftrev(a);
  return a;
}

const int N = (int) 1e5 + 7;
int n, m, dep[N];
vector<pair<int, int>> ret(A, {0, 0});
vector<int> wghs;
vector<pair<int, int>> g[N];

void dfs(int a) {
  for (auto &it : g[a]) {
    int b = it.first, w = it.second;
    if (dep[b] == -1) {
      dep[b] = 1 + dep[a];
      wghs.push_back(w);
      dfs(b);
      wghs.pop_back();
      continue;
    }
    if (dep[b] < dep[a] - 1) {
      /// we have a back edge
      vector<pair<int, int>> f(A, {0, 0});
      f[w].first++;
      f[w].second = 1;
      for (int j = (int) wghs.size() - (dep[a] - dep[b]); j < (int) wghs.size(); j++) {
        f[wghs[j]].first++;
        f[wghs[j]].second = 1;
      }
      ret = xorConvolution(ret, f);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ret[0] = {1, 1};
  cin >> n >> m;
  for (int i = 1; i <= n; i++) dep[i] = -1;
  int totalXor = 0;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    totalXor ^= z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  dep[1] = 0;
  dfs(1);
  for (int j = 0; j < A; j++) {
    if (ret[j ^ totalXor].second) {
      cout << j << " " << ret[j ^ totalXor].first << "\n";
      return 0;
    }
  }
}