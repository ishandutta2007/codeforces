#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int f[1005], cnt[1005], mod;

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n >> mod;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    a[i] %= mod;
    for (int j = 0; j < mod; j++) {
      int val = a[i] - j;
      if (val < 0) {
        val += mod;
      }
      cnt[val] += f[j];
    }
    f[a[i]]++;
  }
  int sol = 1;
  for (int i = 0; i < mod; i++) {
    sol = mul(sol, pw(i, cnt[i]));
  }
  cout << sol << "\n";
}