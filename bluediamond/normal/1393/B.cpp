#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int> freq;
multiset<int> vals;

void op(int x, int sgn) {
  if (freq[x]) {
    vals.erase(vals.find(-freq[x]));
  }
  freq[x] += sgn;
  if (freq[x]) {
    vals.insert(-freq[x]);
  }
}

bool check() {
  vector<int> a;
  int steps = 0;
  for (auto &it : vals) {
    steps++;
    if (steps == 5) {
      break;
    }
    a.push_back(-it);
  }
  bool ok = 0;
  ok |= (a[0] >= 8);
  ok |= (a[0] >= 6 && a[1] >= 2);
  ok |= (a[0] >= 4 && a[1] >= 4);
  ok |= (a[0] >= 4 && a[1] >= 2 && a[2] >= 2);
  return ok;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int j = 1; j <= 5; j++) {
    vals.insert(0);
  }
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    op(x, +1);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    string s;
    int x;
    cin >> s >> x;
    if (s == "+") {
      op(x, +1);
    } else {
      op(x, -1);
    }
    if (check()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}