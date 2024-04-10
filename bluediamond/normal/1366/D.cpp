#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 5e5 + 7;
const int L = (int) 1e7 + 7;
int lp[L];
vector<int> primes;
int print[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i < L; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i < L; j++) {
      lp[primes[j] * i] = primes[j];
    }
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    int p = lp[x];
    while (x % p == 0) {
      x /= p;
    }
    int d1 = p;
    int d2 = x;
    if (x == 1) {
      d1 = d2 = -1;
    }
    cout << d1 << " ";
    print[i] = d2;
  }
  cout << "\n";
  for (int i = 1; i <= q; i++) {
    cout << print[i] << " ";
  }
  cout << "\n";
  return 0;
}