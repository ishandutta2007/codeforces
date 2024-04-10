#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int C = 2;
int mods[C];

class T {
public:
  int a[C];
  T() {
    for (int i = 0; i < C; i++) {
      a[i] = 0;
    }
  }
  T(int x) {
    ///assert(x <= (int) 1e9);
    for (int i = 0; i < C; i++) {
      a[i] = x;
      assert(x < mods[i]);
    }
  }
};

const int P = (int) 1e9 + 7;
const int A = 97;
const int B = 37;

bool operator < (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    if (ff.a[i] != ss.a[i]) return ff.a[i] < ss.a[i];
  }
  return (1 < 1);
}

T operator + (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    ff.a[i] += ss.a[i];
    if (ff.a[i] >= mods[i]) ff.a[i] -= mods[i];
  }
  return ff;
}

T operator - (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    ff.a[i] -= ss.a[i];
    if (ff.a[i] < 0) ff.a[i] += mods[i];
  }
  return ff;
}

T operator * (T ff, T ss) {
  for (int i = 0; i < C; i++) {
    ff.a[i] = (ll) ff.a[i] * ss.a[i] % mods[i];
  }
  return ff;
}

mt19937 rng((long long) (new char));

bool isprime(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

const int N = (int) 1e5 + 7;
int n, sub[N];
vector<int> g[N];
T dp[N];
T sol[N];
T put[2 * N];
T aa;
T bb;

void calc(int a, int p = -1) {
  vector<pair<T, int>> cox;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;
    sub[a] += sub[b];
    cox.push_back({dp[b], b});
  }
  sort(cox.begin(), cox.end());
  int pt = 0;
  T cur(0);
  cur = cur + put[pt] * aa;
  pt++;
  for (auto &it : cox) {
    cur = cur + put[pt] * it.first;
    pt += 2 * sub[it.second];
  }
  cur = cur + put[pt] * bb;
  dp[a] = cur;
}

void rer(int a, int b) {
  calc(a, b);
  calc(b, -1);
}


void dfs(int a, int p = -1) {
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
  }
  calc(a, p);
}

void solve(int a, int p = -1) {
  sol[a] = dp[a];
  for (auto &b : g[a]) {
    if (b == p) continue;
    rer(a, b);
    solve(b, a);
    rer(b, a);
  }
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  for (int it = 0; it < C; it++) {
    while (1) {
      int x = (int) 1e9 + 100 + rng() % 10000;
      if (!isprime(x)) continue;
      mods[it] = x;
      break;
    }
  }


  put[0] = 1;
  put[1] = P;
  for (int i = 2; i < 2 * N; i++) {
    put[i] = put[1] * put[i - 1];
  }

  aa = A;
  bb = B;

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1);
  solve(1);


  set<T> st;
  for (int i = 1; i <= n; i++) {
    if ((int) g[i].size() <= 3) {
      st.insert(sol[i]);
    }
  }
  cout << (int) st.size() << "\n";

  return 0;
}