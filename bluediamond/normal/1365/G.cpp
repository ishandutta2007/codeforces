/// https://codeforces.com/problemset/problem/1365/G
#include <bits/stdc++.h>

using namespace std;

int cnt_bits(int x) {
  int sol = 0;
  for (int i = 0; (1 << i) <= x; i++) {
    if (x & (1 << i)) {
      sol++;
    }
  }
  return sol;
}

typedef long long ll;

map<vector<int>, ll> memo;

ll ask(vector<int> v) {
  if (v.empty()) {
    return 0LL;
  }
  if (memo.count(v)) {
    return memo[v];
  }
  for (int i = 1; i < (int) v.size(); i++) {
    assert(v[i - 1] < v[i]);
  }
  cout << "? " << (int) v.size() << " ";
  for (auto &i : v) {
    cout << i + 1 << " ";
  }
  cout << endl;
  ll x;
  cin >> x;
  memo[v] = x;

  return x;
}

const int N = 1000 + 7;
int n;
ll have0[13];
int id[N];

int main() {
  cin >> n;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    while (cnt_bits(cur) != 6) cur++;
    id[i] = cur++;
  }
  for (int bit = 0; bit < 13; bit++) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (!(id[i] & (1 << bit))) {
        v.push_back(i);
      }
    }
    have0[bit] = ask(v);
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    ll sol = 0;
    for (int bit = 0; bit < 13; bit++) {
      if (id[i] & (1 << bit)) {
        sol |= have0[bit];
      }
    }
    cout << sol << " ";
  }
  cout << endl;



  return 0;
}