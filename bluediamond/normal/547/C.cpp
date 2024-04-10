#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
const int L = (int) 5e5 + 7;
vector<int> primes;
int n, q, a[N], lp[L], t[L], cnt[L], univ;
bool act[N];
long long ans;

void gen() {
  t[1] = 1;
  for (int i = 2; i < L; i++) {
    if (lp[i] == 0) {
      primes.push_back(i);
      lp[i] = i;
    }
    for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i < L; j++) {
      lp[primes[j] * i] = primes[j];
    }
    if (t[i / lp[i]] % lp[i]) {
      t[i] = t[i / lp[i]] * lp[i];
    } else {
      t[i] = t[i / lp[i]];
    }
  }
}

void gen(int i, int num, int sgn) {
  if (i == 1) {
    if (univ == 1) {
      ans += cnt[num] * sgn;
    }
    cnt[num] += univ;
    if (univ == -1) {
      ans += cnt[num] * sgn;
    }
    return;
  }
  gen(i / lp[i], num, sgn);
  gen(i / lp[i], num * lp[i], -sgn);
}

void add(int i, int sgn) {
  univ = sgn;
  gen(i, 1, sgn);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  gen();
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = t[a[i]];
  }
  while (q--) {
    int i;
    cin >> i;
    if (act[i] == 0) {
      add(a[i], +1);
    } else {
      add(a[i], -1);
    }
    act[i] ^= 1;
    cout << ans << "\n";
  }
  return 0;
}