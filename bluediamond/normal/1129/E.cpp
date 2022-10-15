#include <bits/stdc++.h>

using namespace std;

void print(vector<int> a) {
  cout << (int) a.size() << endl;
  for (auto &x : a) {
    cout << x << " ";
  }
  cout << endl;
}

int get(vector<int> a, vector<int> b, int v) {
  if (a.empty() || b.empty()) {
    return 0;
  }
  print(a);
  print(b);
  cout << v << endl;
  cin >> v;
  return v;
}

const int N = 500 + 7;
int n, sz[N], ord[N];
vector<pair<int, int>> edges;

bool cmp(int i, int j) {
  return sz[i] < sz[j];
}

void done() {
  assert((int) edges.size() == n - 1);
  cout << "ANSWER" << endl;
  for (auto &it : edges) {
    cout << it.first << " " << it.second << endl;
  }
  exit(0);
}

vector<int> operator - (vector<int> v, int a) {
  vector<int> sol;
  for (auto &x : v) {
    if (x == a) {
      continue;
    }
    sol.push_back(x);
  }
  assert((int) sol.size() == (int) v.size() - 1);
  return sol;
}

signed main() {
  cin >> n;
  sz[1] = n;
  for (int i = 2; i <= n; i++) {
    vector<int> one = {1}, others;
    for (int j = 2; j <= n; j++) {
      others.push_back(j);
    }
    sz[i] = get(one, others, i);
  }
  for (int i = 1; i <= n; i++) {
    ord[i] = i;
  }
  sort(ord + 1, ord + n + 1, cmp);
  vector<int> unmatched;
  for (int it = 1; it <= n; it++) {
    int a = ord[it], kids = get({1}, unmatched, a);
    for (int step = 1; step <= kids; step++) {
      int l = 0, r = (int) unmatched.size() - 1, pos = (int) unmatched.size() - 1;
      while (l <= r) {
        int m = (l + r) / 2;
        vector<int> pref = unmatched;
        pref.resize(m + 1);
        if (get({1}, pref, a) >= 1) {
          pos = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      int b = unmatched[pos];
      unmatched = unmatched - b;
      edges.push_back({a, b});
    }
    unmatched.push_back(a);
  }
  {
    vector<int> one = {1};
    assert(unmatched == one);
  }
  done();
  return 0;
}