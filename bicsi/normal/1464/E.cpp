#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353;

struct ModInt {
  int x;
  ModInt(int _x) : x(_x) {
    while (x < 0) x += MOD;
    while (x >= MOD) x -= MOD;
  }
  ModInt operator+(const ModInt& oth) const {
    return x + oth.x;
  }
  ModInt operator-(const ModInt& oth) const {
    return x - oth.x;
  }
  ModInt operator*(const ModInt& oth) const {
    return 1LL * x * oth.x % MOD;
  }
};
ostream& operator<<(ostream& out, const ModInt& x) {
  out << x.x;
  return out;
}

ModInt lgpow(ModInt b, int e) {
  ModInt r = 1;
  while (e) {
    if (e % 2) r = r * b;
    b = b * b;
    e /= 2;
  }
  return r;
}
ModInt inv(ModInt x) { 
  return lgpow(x, MOD - 2); 
}

vector<ModInt> Transform(vector<ModInt> P, bool iv) {
  int n = P.size();
  for (int step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) {
      for (int j = i; j < i + step; ++j) {
        ModInt u = P[j], v = P[j + step];
        tie(P[j], P[j + step]) = make_pair(u + v, u - v);
      }
    }
  }
  if (iv) {
    ModInt in = inv(n);
    for (auto& x : P) x = x * in; 
  }
  return P;
}

vector<ModInt> Mul(vector<ModInt> A, vector<ModInt> B) {
  A = Transform(A, false); B = Transform(B, false);
  for (int i = 0; i < (int)A.size(); ++i)
    A[i] = A[i] * B[i];
  A = Transform(A, true);
  return A;
}
vector<ModInt> Add(vector<ModInt> A, vector<ModInt> B) {
  for (int i = 0; i < (int)A.size(); ++i)
    A[i] = A[i] + B[i];
  return A;
}
vector<ModInt> Neg(vector<ModInt> A) {
  for (int i = 0; i < (int)A.size(); ++i)
    A[i] = A[i] * (-1);
  return A;
}

vector<ModInt> Invert(vector<ModInt> P) {
  int n = P.size();
  if (n == 1) {
    return vector<ModInt>(1, inv(P[0]));
  }
  vector<ModInt> A(P.begin(), P.begin() + n/2);
  vector<ModInt> B(P.begin() + n/2, P.end());
  vector<ModInt> MAGIC = Invert(Add(Mul(A, A), Neg(Mul(B, B))));
  vector<ModInt> C = Mul(A, MAGIC);
  vector<ModInt> D = Mul(Neg(B), MAGIC);
  debug(n, A, B, C, D, Mul(A, A), Mul(B, B));
  C.insert(C.end(), D.begin(), D.end());
  debug(P, C, Mul(C, P));
  return C;
}

vector<vector<int>> graph;
vector<int> dp;
int DFS(int node) {
  if (dp[node] != -1) return dp[node];
  
  set<int> vals;
  for (auto vec : graph[node]) {
    vals.insert(DFS(vec));
  }
  dp[node] = 0;
  while (vals.count(dp[node])) ++dp[node];
  return dp[node];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m; cin >> n >> m;
  graph.assign(n, {});
  dp.assign(n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    graph[a - 1].push_back(b - 1);
  }
  int N = n;
  while (N != (N & -N)) ++N;
  vector<ModInt> P(N, 0);
  P[0] = 1;
  ModInt in = inv(n + 1);
  for (int i = 0; i < n; ++i) {
    int now = DFS(i);
    P[now] = P[now] - in;
  }
  auto IP = Invert(P);
  //auto CHK = Mul(P, IP);
  //debug(P, IP, CHK);
  cout << (ModInt(1) - (in * IP[0])).x << endl;

  return 0;
}