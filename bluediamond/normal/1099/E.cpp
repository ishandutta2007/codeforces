#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> lib(int n, int m) {
  vector<vector<int>> sol(n);
  for (int i = 0; i < n; i++) {
    sol[i].resize(m, 0);
  }
  return sol;
}

vector<vector<int>> get(vector<vector<int>> a) {
  int n = (int) a.size(), m = (int) a[0].size();
  vector<vector<int>> b = lib(m, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[j][i] = a[i][j];
    }
  }
  return b;
}

int solve(vector<vector<int>> v) {
  int sol = (int) 1e9;
  int n = (int) v.size(), m = (int) v[0].size();
  for (int a = 1; a <= 4; a++) {
    for (int b = a + 1; b <= 4; b++) {
      set<int> s;
      s.insert(1);
      s.insert(2);
      s.insert(3);
      s.insert(4);
      s.erase(a);
      s.erase(b);
      int c = *s.begin();
      s.erase(s.begin());
      int d = *s.begin();
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int cost1 = 0, cost2 = 0;
        if (i % 2 == 0) {
          for (int j = 0; j < m; j++) {
            if (j % 2 == 0) cost1 += (v[i][j] != a), cost2 += (v[i][j] != b);
            if (j % 2 == 1) cost1 += (v[i][j] != b), cost2 += (v[i][j] != a);
          }
        } else {
          for (int j = 0; j < m; j++) {
            if (j % 2 == 0) cost1 += (v[i][j] != c), cost2 += (v[i][j] != d);
            if (j % 2 == 1) cost1 += (v[i][j] != d), cost2 += (v[i][j] != c);
          }
        }
        cur += min(cost1, cost2);
      }
      sol = min(sol, cur);
    }
  }
  return sol;
}

void print(vector<vector<int>> v) {
  int n = (int) v.size(), m = (int) v[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 1) cout << "A";
      if (v[i][j] == 2) cout << "G";
      if (v[i][j] == 3) cout << "C";
      if (v[i][j] == 4) cout << "T";
    }
    cout << "\n";
  }
}

void print(bool inv, int sol, vector<vector<int>> v) {
  int n = (int) v.size(), m = (int) v[0].size();
  for (int a = 1; a <= 4; a++) {
    for (int b = a + 1; b <= 4; b++) {
      set<int> s;
      s.insert(1);
      s.insert(2);
      s.insert(3);
      s.insert(4);
      s.erase(a);
      s.erase(b);
      int c = *s.begin();
      s.erase(s.begin());
      int d = *s.begin();
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int cost1 = 0, cost2 = 0;
        if (i % 2 == 0) {
          for (int j = 0; j < m; j++) {
            if (j % 2 == 0) cost1 += (v[i][j] != a), cost2 += (v[i][j] != b);
            if (j % 2 == 1) cost1 += (v[i][j] != b), cost2 += (v[i][j] != a);
          }
        } else {
          for (int j = 0; j < m; j++) {
            if (j % 2 == 0) cost1 += (v[i][j] != c), cost2 += (v[i][j] != d);
            if (j % 2 == 1) cost1 += (v[i][j] != d), cost2 += (v[i][j] != c);
          }
        }
        cur += min(cost1, cost2);
      }
      if (cur == sol) {
        vector<vector<int>> sol = lib(n, m);
        for (int i = 0; i < n; i++) {
          int cost1 = 0, cost2 = 0;
          if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
              if (j % 2 == 0) cost1 += (v[i][j] != a), cost2 += (v[i][j] != b);
              if (j % 2 == 1) cost1 += (v[i][j] != b), cost2 += (v[i][j] != a);
            }
            if (cost1 < cost2) {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) sol[i][j] = a; else sol[i][j] = b;
              }
            } else {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) sol[i][j] = b; else sol[i][j] = a;
              }
            }
          } else {
            for (int j = 0; j < m; j++) {
              if (j % 2 == 0) cost1 += (v[i][j] != c), cost2 += (v[i][j] != d);
              if (j % 2 == 1) cost1 += (v[i][j] != d), cost2 += (v[i][j] != c);
            }
            if (cost1 < cost2) {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) sol[i][j] = c; else sol[i][j] = d;
              }
            } else {
              for (int j = 0; j < m; j++) {
                if (j % 2 == 0) sol[i][j] = d; else sol[i][j] = c;
              }
            }
          }
        }
        if (inv) {
          sol = get(sol);
        }
        print(sol);
        exit(0);
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a = lib(n, m);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'A') a[i][j] = 1;
      if (s[j] == 'G') a[i][j] = 2;
      if (s[j] == 'C') a[i][j] = 3;
      if (s[j] == 'T') a[i][j] = 4;
    }
  }
  int ans = min(solve(a), solve(get(a)));
  print(0, ans, a);
  print(1, ans, get(a));
  cout << ans << "\n";
  return 0;
}