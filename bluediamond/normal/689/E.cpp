#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {return a * (ll) b % M;}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a); b /= 2;
  }
  return r;
}

int dv(int a, int b) {return mul(a, pw(b, M - 2));}


const int N = 200000 + 7;
int fact[N], ifact[N];

int c(int n, int k) {
  if (k > n) return 0;
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  fact[0] = 1; for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]); for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

  map<int, int> mars;

  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    mars[l]++;
    mars[r + 1]--;
  }
  int cur = 0, last, sol = 0;
  for (auto &it : mars) {
    int now = it.first;
    if (cur) {
      int len = (now - last) % M;
      sol = add(sol, mul(len, c(cur, k)));
    }
    last = now;
    cur += it.second;
  }
  cout << sol << "\n";

}