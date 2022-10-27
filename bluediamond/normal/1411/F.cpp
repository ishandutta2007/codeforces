#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int)1e9 + 7;
const int B = 4;

int greedy(vector<int> cnt) {
  cnt[0] = 0;
  int sol = 0;
  vector<int> f(3, 0);
  int sl = 0;
  for (int i = 1; i <= B; i++) {
    sl += cnt[i] * i;
    f[i % 3] += cnt[i];
  }
  int take = min(f[1], f[2]);
  sol += take;
  f[0] += take;
  f[1] -= take;
  f[2] -= take;
  sol += (f[1] / 3) * 2;
  sol += (f[2] / 3) * 2;
  f[0] += f[1] / 3;
  f[0] += f[2] / 3;
  return sol + sl / 3 - f[0];
}

void minup(int& a, int b) {
  a = min(a, b);
}

int main() {

  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  vector<vector<vector<int>>> cew(5);
  for (int a = 0; a <= 4; a++) {
    for (int b = a; b <= 4; b++) {
      for (int c = b; c <= 4; c++) {
        for (int d = c; d <= 4; d++) {
          if (a + b + c + d == 4 || a + b + c + d == 2) {
            vector<int> sol;
            if (a) sol.push_back(a);
            if (b) sol.push_back(b);
            if (c) sol.push_back(c);
            if (d) sol.push_back(d);
            cew[a + b + c + d].push_back(sol);
          }
        }
      }
    }
  }

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> vis(n, 0);
    vector<int> cnt(B + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    int extracost = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i]) {
        continue;
      }
      int len = 0, cur = i;
      while (vis[cur] == 0) {
        len++;
        vis[cur] = 1;
        cur = a[cur];
      }
      while (len > B) {
        len -= 3;
        extracost++;
      }
      cnt[len]++;
    }
    int ways = 1;
    {
      int cop = n;
      while (cop > 4) {
        cop -= 3;
        ways = ways * (ll)3 % M;
      }
      ways = ways * (ll)cop % M;
    }
    int sol = (int)1e9 + 7;
    if (n % 3 == 2) {
      for (int x = 1; x <= B; x++) {
        if (cnt[x] && x >= 2) {
          cnt[x]--;
          cnt[x - 2]++;
          sol = min(sol, greedy(cnt) + (x > 2));
          cnt[x - 2]--;
          cnt[x]++;
        }
      }
      for (auto& v : cew[2]) {
        int cost = -1;
        for (auto& i : v) {
          cost++;
          cnt[i]--;
        }
        if (*min_element(cnt.begin(), cnt.end()) >= 0) {
          sol = min(sol, greedy(cnt) + cost);
        }
        for (auto& i : v) {
          cnt[i]++;
        }
      }
    }
    if (n % 3 == 1) {
      {
        for (int x = 1; x <= B; x++) {
          if (cnt[x] && x >= 4) {
            cnt[x]--;
            cnt[x - 4]++;
            sol = min(sol, greedy(cnt) + (x > 4));
            cnt[x - 4]--;
            cnt[x]++;
          }
        }
        for (auto& v : cew[4]) {
          int cost = -1;
          for (auto& i : v) {
            cost++;
            cnt[i]--;
          }
          if (*min_element(cnt.begin(), cnt.end()) >= 0) {
            sol = min(sol, greedy(cnt) + cost);
          }
          for (auto& i : v) {
            cnt[i]++;
          }
        }
      }
      {
        for (int x = 1; x <= B; x++) {
          if (cnt[x] && x >= 2) {
            cnt[x]--;
            cnt[x - 2]++;
            for (int y = 1; y <= B; y++) {
              if (cnt[y] && y >= 2) {
                cnt[y]--;
                cnt[y - 2]++;
                sol = min(sol, greedy(cnt) + (x > 2) + (y > 2));
                cnt[y - 2]--;
                cnt[y]++;
              }
            }
            cnt[x - 2]--;
            cnt[x]++;
          }
        }
        for (auto& v1 : cew[2]) {
          for (auto& v2 : cew[2]) {
            vector<int> v;
            for (auto& i : v1)v.push_back(i);
            for (auto& i : v2)v.push_back(i);
            int cost = -2;
            for (auto& i : v) {
              cost++;
              cnt[i]--;
            }
            if (*min_element(cnt.begin(), cnt.end()) >= 0) {
              sol = min(sol, greedy(cnt) + cost);
            }
            for (auto& i : v) {
              cnt[i]++;
            }
          }
          int cost = -1;
          for (auto& i : v1) {
            cost++;
            cnt[i]--;
          }
          if (*min_element(cnt.begin(), cnt.end()) >= 0) {
            for (int x = 1; x <= B; x++) {
              if (cnt[x] && x >= 2) {
                cnt[x]--;
                cnt[x - 2]++;
                sol = min(sol, greedy(cnt) + (x > 2) + cost);
                cnt[x - 2]--;
                cnt[x]++;
              }
            }
          }
          for (auto& i : v1) {
            cnt[i]++;
          }
        }
      }

    }
    if (n % 3 == 0) {
      int cnt3 = n / 3;
      minup(sol, greedy(cnt));
    }
    cout << ways << " " << extracost + sol << "\n";
  }

}