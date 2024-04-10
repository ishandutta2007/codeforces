#include <bits/stdc++.h>


using namespace std;

int get(vector < int > a) {
  int s = 0;
  for (int i = 1; i < (int) a.size(); i++) {
    s = max(s, a[i] ^ a[i - 1]);
  }
  return s;
}

int tst(int n) {
  vector < int > a(n);
  iota(a.begin(), a.end(), 0);
  int sol = get(a);
  while (next_permutation(a.begin(), a.end())) sol = min(sol, get(a));
  return sol;
}

vector < int > eval(int n) {
  int k = log2(max(1, n - 1));
  k = (1 << k);
  vector < int > a, b;
  for (int i = 0; i < k; i++) a.push_back(i);
  for (int i = k; i < n; i++) b.push_back(i);
  assert((int) a.size() >= (int) b.size());
  vector < int > sol;
  for (int i = (int) b.size(); i < (int) a.size(); i++) {
    sol.push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    if (i % 2 == 0) {
      sol.push_back(a[i]);
      sol.push_back(b[i]);
    } else {
      sol.push_back(b[i]);
      sol.push_back(a[i]);
    }
  }

  return sol;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto a = eval(n);
    for (auto & x: a) {
      cout << x << " ";
    }
    cout << "\n";

  }

}