#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 100000 + 7;

int n, aib[N];

void addAib(int i, int x) {
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int getAib(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}

void clrAib() {
  for (int i = 1; i <= n; i++) {
    aib[i] = 0;
  }
}

string s;
map<char, int> f;

int computeCost(string ord) {
  clrAib();
  string t;
  for (auto &ch : ord) {
    for (int j = 1; j <= f[ch]; j++) {
      t += ch;
    }
  }

  assert((int) s.size() == (int) t.size());

  map<char, int> Pointer;

  int Inversions = 0;

  for (auto &ch : s) {
    while (t[Pointer[ch]] != ch) Pointer[ch]++;

    Pointer[ch]++;

    Inversions += getAib(n + 1 - Pointer[ch]);
    addAib(n + 1 - Pointer[ch], +1);
  }
  return Inversions;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    f.clear();
    cin >> s;
    n = (int) s.size();

    for (auto &ch : s) {
      f[ch]++;
    }

    string ord = "ANTO";
    sort(ord.begin(), ord.end());

    string sol = ord;
    while (next_permutation(ord.begin(), ord.end())) {
      ///cout << " : " << computeCost(ord) << "\n";
      if (computeCost(ord) > computeCost(sol)) {
        sol = ord;
      }
    }

    string t;
    for (auto &ch : sol) {
      for (int j = 1; j <= f[ch]; j++) {
        t += ch;
      }
    }
    cout << t << "\n";
  }

  return 0;
}