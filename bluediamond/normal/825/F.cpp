#include <bits/stdc++.h>

using namespace std;

void print(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

vector<int> build(vector<int> v) {
  int n = (int) v.size();
  vector<int> ps(n, 0);
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j && v[j] != v[i]) {
      j = ps[j - 1];
    }

    if (v[j] == v[i]) {
      j++;
    }
    ps[i] = j;
  }
  return ps;
}

typedef unsigned long long ll;
const int N = 8000 + 7;
int n;
bitset<N> ok[N];
int dp[N];
string s;

int cntDigits(int x) {
  if (x <= 9) return 1;
  return 1 + cntDigits(x / 10);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> s;
  n = (int) s.size();

  for (int i = 1; i <= n; i++) {
    dp[i] = (int) 1e9;
  }

  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = i; j < n; j++) {
      v.push_back(s[j]);
    }

    auto ps = build(v);
    for (int j = i; j < n; j++) {
      int len = j - i + 1 - ps[j - i];
      int cnt;
      if ((j - i + 1) % len != 0) {
        len = 1;
        cnt = j - i + 1;
      } else {
        cnt = cntDigits((j - i + 1) / len);
      }
      dp[j + 1] = min(dp[j + 1], dp[i] + cnt + len);
    }
  }
  cout << dp[n] << "\n";




  return 0;
}