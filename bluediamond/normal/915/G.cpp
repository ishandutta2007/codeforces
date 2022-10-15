#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e6 + 7;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int n;
int k;
int esol[N];
int precalc[N];
int mobi[N];
int lp[N];
vector<int> primes;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < N; i++) {
    precalc[i] = pw(i, n);
  }
  for (int i = 2; i < N; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i < N; j++) {
      lp[primes[j] * i] = primes[j];
    }
  }
  mobi[1] = 1;
  for (int i = 2; i < N; i++) {
    int p = lp[i];
    if (lp[i / p] == p) {
      mobi[i] = 0;
    } else {
      mobi[i] = -mobi[i / p];
    }
  }

  for (int c = 1; c <= k; c++) {
    for (int i = 1; i * c <= k; i++) {
      int l = i * c, r = min(k, i * (c + 1) - 1);
      esol[l] = add(esol[l], precalc[c] * mobi[i]);
      esol[r + 1] = add(esol[r + 1], -precalc[c] * mobi[i]);
    }
  }


  int print = 0;
  for (int i = 1; i <= k; i++) {
    esol[i] = add(esol[i], esol[i - 1]);
    print = add(print, (i ^ esol[i]) % M);
  }

  if (n == k && n == (int) 1e3) {
    assert(print == 293255159);
  }
  cout << print << "\n";

  return 0;
}