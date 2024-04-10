#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
const int M = (int) 1e9 + 7;
int n, q, a[N], ret = 1, mn[N];
map<int, int> t[N];
multiset<int> st[N];
bool prime[N];
vector<int> primes;
vector<int> d[N];

void mul(int i, int x) {
  for (auto &p : d[x]) {
    int cnt = 0;
    while (x % p == 0) {
      x /= p;
      cnt++;
    }
    if (t[p][i]) st[p].erase(st[p].find(t[p][i]));
    t[p][i] += cnt;
    st[p].insert(t[p][i]);
    if ((int) st[p].size() == n) {
      int val = *st[p].begin();
      while (mn[p] < val) {
        mn[p]++;
        ret = (ll) ret * p % M;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  prime[2] = 1;
  for (int i = 3; i < N; i += 2) prime[i] = 1;
  for (int i = 3; i * i < N; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j < N; j += 2 * i) prime[j] = 0;
    }
  }
  for (int i = 1; i < N; i++) {
    if (prime[i]) {
      primes.push_back(i);
    }
  }
  int cnt = 0;
  for (auto &p : primes) {
    for (int i = p; i < N; i += p) {
      d[i].push_back(p);
      cnt++;
    }
  }
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mul(i, x);
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    mul(i, x);
    cout << ret << "\n";
  }
}