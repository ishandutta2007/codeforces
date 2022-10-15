#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937 rng((long long) (new char));

int getINT() {
  ll val = (1 << 30);
  return rng() % val;
}

ll get() {
  ll val = (1 << 30);
  return getINT() * val + getINT();
}

const int N = (int) 1e6 + 7;
int lp[N];
vector<int> primes;
int n;
ll forp[N];
ll guy[N];

void exclude(vector<int> unlucky) {
  set<int> good;
  for (int i = 1; i <= n; i++) {
    good.insert(i);
  }
  for (auto &x : unlucky) {
    good.erase(x);
  }
  cout << (int) good.size() << "\n";
  for (auto &x : good) {
    cout << x << " ";
  }
  cout << "\n";
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);


  cin >> n;

  for (int i = 2; i <= n; i++) {
    if (!lp[i]) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int) primes.size() && primes[j] <= lp[i] && primes[j] * i <= n; j++) {
      lp[primes[j] * i] = primes[j];
    }
  }

  for (auto &p : primes) {
    forp[p] = get();
  }

  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j > 1) {
      guy[i] ^= forp[lp[j]];
      j /= lp[j];
    }
  }

  for (int i = 1; i <= n; i++) {
    guy[i] ^= guy[i - 1];
  }

  ll total = 0;
  for (int i = 1; i <= n; i++) {
    total ^= guy[i];
  }

  if (total == 0) {
    exclude({});
  }

  for (int i = 1; i <= n; i++) {
    if ((total ^ guy[i]) == 0) {
      exclude({i});
    }
  }

  map<ll, ll> who;
  for (int i = 1; i <= n; i++) {
    if (who.count(total ^ guy[i])) {
      exclude({i, who[total ^ guy[i]]});
    }
    who[guy[i]] = i;
  }
  assert(n % 2 == 1);
  exclude({n, 2, n / 2});
}