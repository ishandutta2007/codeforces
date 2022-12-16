#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int to(char x) {
  return x-'a';
}

struct Trie {
  vector<array<int, 26>> v;
  void insert() {
    v.emplace_back(array<int, 26>());
    fill(v.back().begin(), v.back().end(), 0);
  }

  Trie() {
    insert();
  }

  void insert(string s) {
    int x = 0;
    for (int i=0; i<s.size(); ++i) {
      int c = to(s[i]);
      if (v[x][c] == 0) {
        v[x][c] = v.size();
        insert();
      }
      x = v[x][c];
    }
  }

  bool find(string s) {
    int x = 0;
    for (int i=0; i<s.size(); ++i) {
      int c = to(s[i]);
      if (v[x][c] == 0) {
        return false;
      }
      x = v[x][c];
    }
    return true;
  }
};

bool solve() {
  int n;
  cin >> n;
  //cerr << "! " << n << endl;
  vector<string> t(n);
  bool good = false;
  for (int i=0; i<n; ++i) {
    cin >> t[i];
    if (t[i].size() == 1) {
      //cerr << " LEN 1 " << endl;
      good = true;
    }
  }
  if (good) {
    return true;
  }
  for (int _i=0; _i<2; ++_i) {
    Trie tr;
    for (int i=n-1; i>=0; --i) {
      string r = t[i];
      reverse(t[i].begin(), t[i].end());
      if (r == t[i]) {
        //cerr << " PALINDROMIC SS " << r << endl;
        return true;
      }
      if (tr.find(r)) {
        //cerr << " FOUND MATCH " << r << endl;
        return true;
      }
      //cerr << " -> insert " << t[i] << endl;
      tr.insert(t[i]);
    }
    reverse(t.begin(), t.end());
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}