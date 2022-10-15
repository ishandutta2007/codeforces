#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

string ask(vector<int> a, vector<int> b) {
  cout << "? " << (int) a.size() << " " << (int) b.size() << endl;
  for (auto &x : a) {
    cout << x << " ";
  }
  cout << endl;
  for (auto &x : b) {
    cout << x << " ";
  }
  cout << endl;
  string s;
  cin >> s;
  return s;
}

void print(int i) {
  cout << "! " << i << endl;
}

void solve_test() {
  int n, k;
  cin >> n >> k;
  vector<int> elements;
  for (int i = 2; i <= n; i++) {
    elements.push_back(i);
  }
  shuffle(elements.begin(), elements.end(), rng);
  int C = min(30, (int) elements.size()), mx = 1;
  for (int i = 0; i < C; i++) {
    int j = elements[i];
    string s = ask({mx}, {j});
    if (s == "SECOND") {
      mx = j;
    }
  }
  if (mx != 1) {
    print(1);
    return;
  }
  int sz = 1;
  while (1) {
    if (sz * 2 > n) {
      break;
    }
    vector<int> a, b;
    for (int i = 1; i <= sz; i++) {
      a.push_back(i);
    }
    for (int i = sz + 1; i <= 2 * sz; i++) {
      b.push_back(i);
    }
    string s = ask(a, b);
    if (s == "FIRST") {
      break;
    }
    sz *= 2;
  }
 /// cout << "started the binary search!\n";
  int lo = sz, hi = 2 * sz - 1;
  if (hi > n) {
    hi = n;
  }
  while (lo <= hi) {
    if (lo == hi) {
      print(lo + 1);
      break;
    }
    if (lo + 1 == hi) {
      string s;
      if (lo + 1 == mx) {
        s = "EQUAL";
      } else {
        s = ask({lo + 1}, {mx});
      }
      if (s == "EQUAL") {
        print(lo + 2);
      } else {
        print(lo + 1);
      }
      break;
    }
    int mid = (lo + hi) / 2;
    vector<int> a, b;
    for (int j = lo; j <= mid; j++) {
      a.push_back(j - lo + 1);
      b.push_back(j);
    }
    string s = ask(a, b);
    if (s == "EQUAL") {
      lo = mid;
    } else {
      hi = mid;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve_test();
  }
}