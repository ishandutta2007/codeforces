#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long) (new char));

int n, x, y, qs;
map<vector<int>, int> mp;

int ask(vector<int> v) {
  if (mp.count(v)) {
    return mp[v];
  }
  qs++;
  if (qs > 19) {
    while (1) {

    }
    exit(0);
  }
  cout << "? " << (int) v.size() << " ";
  for (auto &i : v) {
    cout << i + 1 << " ";
  }
  cout << endl;
  int sol;
  cin >> sol;

  mp[v] = sol;
  return sol;
}

int fnd(vector<int> v) {
  assert(!v.empty());
  if ((int) v.size() == 1) {
    return v[0];
  }
  shuffle(v.begin(), v.end(), rng);
  vector<int> c1, c2;
  for (int i = 0; i < (int) v.size(); i++) {
    if (i < (int) v.size() / 2) {
      c1.push_back(v[i]);
    } else {
      c2.push_back(v[i]);
    }
  }
  if (ask(c1) == x || ask(c1) == (x ^ y)) {
    return fnd(c1);
  } else {
    return fnd(c2);
  }
}

int main() {
  cin >> n >> x >> y;
  swap(x, y);
  vector<int> c1, c2;
  while (1) {
    c1.clear();
    c2.clear();
    for (int i = 0; i < n; i++) {
      if (rng() & 1) {
        c1.push_back(i);
      } else {
        c2.push_back(i);
      }
    }
    if (ask(c1) == x || ask(c1) == (x ^ y)) {
      break;
    }
  }
  int p1 = fnd(c1);
  int p2 = fnd(c2);
  if (p1 > p2) {
    swap(p1, p2);
  }
  cout << "! " << p1 + 1 << " " << p2 + 1 << endl;

  /**
  x ^ y == 1 =>

  0 x | sz % 2 == 0 => 0 sau => y
  1 x | sz % 2 == 1 => x sau => x ^ y
  2 x | sz % 2 == 0 => 0 sau => y

  prob = 1 / 2

  E = 1 + 1 / 2 * E
  1 / 2 * E = 1 => E = 2

  excepted = 2 pasi

  **/



  return 0;
}