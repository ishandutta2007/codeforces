#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = (int) 2e5 + 7;
const int L = (int) 1e6 + 1000;
bool prime[L];
int n;
ll a[N], b[N], ans = (ll) 1e18;

ll get(ll x, ll mod) {
  if (x < mod) {
    return mod - x;
  }
  return min(x % mod, mod - x % mod);
}

void upd(ll x) {
  ll cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += get(a[i], x);
    if (cur >= ans) {
      return;
    }
  }
  ans = cur;
}

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
clock_t be;

double tt() {
  clock_t en = clock();
  return double(en - be) / CLOCKS_PER_SEC;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  be = clock();

  for (int i = 3; i < L; i += 2) {
    prime[i] = 1;
  }
  prime[2] = 1;
  for (int i = 3; i * i < L; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j < L; j += 2 * i) {
        prime[j] = 0;
      }
    }
  }
  vector<int> pr;
  for (int i = 1; i < L; i++) {
    if (prime[i]) {
      pr.push_back(i);
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  shuffle(a + 1, a + n + 1, rng);
  for (int i = 1; i < L; i++) {
    if (prime[i]) {
      upd(i);
    }
  }
  int C = 100;
  while (tt() < 2.2) {
    int i = rng() % n + 1;
    int j = rng() % n + 1;
    for (ll x = max(2LL, a[i] - C); x <= a[i] + C; x++) {
      for (ll y = max(2LL, a[j] - C); y <= a[j] + C; y++) {
        ll g = gcd(x, y);
        if (g >= L) {
          for (auto &p : pr) {
            while (g % p == 0) {
              g /= p;
            }
            if (g < L) {
              break;
            }
          }
          if (g >= L) {
            upd(g);
          }
        }
      }
    }
  }
  cout << ans << "\n";
}