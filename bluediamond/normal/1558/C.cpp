#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

/// #define int ll

vector<int> op(vector<int> v, int l) {
  reverse(v.begin(), v.begin() + l);
  return v;
}

vector<int> rec(vector<int> v) {
  int n = (int) v.size();
  assert(n % 2 == 1);
  if (n == 1) {
    return {};
  }
  vector<int> sol;
  for (int i = 0; i < n; i += 2) {
    if (v[i] == n - 1) {
      sol.push_back(i + 1);
      v = op(v, i + 1);
      break;
    }
  }

  for (int i = 1; i < n; i += 2) {
    if (v[i] == n - 2) {
      sol.push_back(i);
      v = op(v, i);
      break;
    }
  }
  sol.push_back(n);
  v = op(v, n);
  for (int i = 0; i < n; i += 2) {
    if (v[i] == n - 1) {
      sol.push_back(i + 1);
      v = op(v, i + 1);
      break;
    }
  }
  sol.push_back(n);
  v = op(v, n);
  assert(v[n - 1] == n - 1 && v[n - 2] == n - 2);
  v.pop_back();
  v.pop_back();
  auto sol2 = rec(v);
  for (auto &x : sol2) {
    sol.push_back(x);
  }
  return sol;
}

vector<int> solve(vector<int> v) {
  int n = (int) v.size();
  for (int i = 0; i < n; i++) {
    if (v[i] % 2 != i % 2) {
      return {-1};
    }
  }
  return rec(v);
}

void test(vector<int> v) {
  auto sol = solve(v);
  int n = (int) v.size();
  if ((int) sol.size() == 1 && sol[0] == -1) {
    return;
  }
  assert((int) sol.size() <= 5 * n / 2);
  for (auto &l : sol) {
    assert(l % 2 == 1);
    v = op(v, l);
  }
  for (int i = 0; i < n; i++) {
    assert(v[i] == i);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
      cin >> x;
      x--;
    }
    auto sol = solve(v);
    if ((int) sol.size() == 1 && sol[0] == -1) {
      cout << "-1\n";
      continue;
    }
    cout << (int) sol.size() << "\n";
    for (auto &i : sol) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;

  cout << "let's goo\n";

  for (int l = 1; l <= 21; l += 2) {
    cout << "started " << l << "\n";

    vector<int> v(l);
    iota(v.begin(), v.end(), 0);
    test(v);

    while (next_permutation(v.begin(), v.end())) {
      test(v);
    }

  }

	return 0;
}