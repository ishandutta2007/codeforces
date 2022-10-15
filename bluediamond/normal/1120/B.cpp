#include <bits/stdc++.h>

using namespace std;

vector<int> get(string s) {
  vector<int> v;
  for (auto &ch : s) {
    v.push_back(ch - '0');
  }
  return v;
}

int sumalt(vector<int> v) {
  int sol = 0;
  for (auto &x : v) {
    sol = x - sol;
  }
  return sol;
}

vector<pair<int, int>> sol;

void print() {
  for (auto &it : sol) {
    cout << it.first << " " << it.second << "\n";
  }
  exit(0);
}


int n;
vector<int> a, b;

void add(int i);
void sub(int i);

void add(int i) {
  if (a[i + 1] == 9) {
    sub(i + 1);
  }
  a[i]++;
  a[i + 1]++;
  sol.push_back({i + 1, +1});
}

void sub(int i) {
  assert(i < n);
  if (a[i + 1] == 0) {
    add(i + 1);
  }
  a[i]--;
  a[i + 1]--;
  sol.push_back({i + 1, -1});
}

void solve(int i) {
  if (i == n - 1 || (int) sol.size() >= (int) 1e5) {
    if ((int) sol.size() > (int) 1e5) {
      sol.resize((int) 1e5);
    }
    print();
  }
  while (a[i] < b[i]) {
    add(i);
  }
  while (a[i] > b[i]) {
    sub(i);
  }
  solve(i + 1);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

//  freopen ("input", "r", stdin);


  string s, t;
  cin >> n >> s >> t;
  a = get(s);
  b = get(t);

  if (sumalt(a) != sumalt(b)) {
    cout << "-1\n";
    return 0;
  }

  int steps;

  {
    vector<long long> x, y;
    for (auto &val : a) {
      x.push_back(val);
    }
    for (auto &val : b) {
      y.push_back(val);
    }
    long long cost = 0;
    for (int i = 0; i < n - 1; i++) {
      long long dif = x[i] - y[i];
      cost += abs(dif);
      x[i + 1] -= dif;
    }
    assert(x[n - 1] == y[n - 1]);
    cout << cost << "\n";
  }

  solve(0);

  print();

  return 0;
}