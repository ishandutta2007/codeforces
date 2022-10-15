#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

vector<int> kmp(string s, string pat) {
  int m = (int) pat.size();
  int n = (int) s.size();
  vector<int> ps(m, 0);
  int j = 0;
  for (int i = 1; i < m; i++) {
    while (j && pat[i] != pat[j]) {
      j = ps[j - 1];
    }
    if (pat[i] == pat[j]) {
      j++;
    }
    ps[i] = j;
  }
  j = 0;
  vector<int> ret;
  for (int i = 0; i < n; i++) {
    while (j && s[i] != pat[j]) {
      j = ps[j - 1];
    }
    if (pat[j] == s[i]) {
      j++;
    }
    if (j == m) {
      j = ps[m - 1];
      ret.push_back(i - m + 1);
    }
  }
  return ret;
}

const int N = (int) 1e5 + 7;
int n;
int q;
int y;
int p2[N * 10];
int pinv2[N * 10];
string s[N];
string t;
int pre[N][26];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  p2[0] = 1;
  for (int i = 1; i < N * 10; i++) {
    p2[i] = mul(p2[i - 1], 2);
  }
  pinv2[N * 10 - 1] = dv(1, p2[N * 10 - 1]);
  for (int i = N * 10 - 2; i >= 0; i--) {
    pinv2[i] = mul(pinv2[i + 1], 2);
  }
  cin >> n >> q >> s[0] >> t;
  while (y < n && (int) s[y].size() <= (int) 1e6) {
    y++;
    s[y] = s[y - 1] + t[y - 1] + s[y - 1];
  }
  for (int x = 0; x < 26; x++) {
    for (int i = 1; i <= n; i++) {
      if (t[i - 1] - 'a' == x) {
        pre[i][x] = add(pre[i - 1][x], p2[n - i]);
      } else {
        pre[i][x] = pre[i - 1][x];
      }
    }
  }
  while (q--) {
    int k;
    string ask;
    cin >> k >> ask;
    if ((int) s[y].size() < (int) ask.size()) {
      cout << "0\n";
      continue;
    }
    int p = min(k, y);
    while (p - 1 >= 0 && (int) s[p - 1].size() >= (int) ask.size()) {
      p--;
    }
    int ret = (int) kmp(s[p], ask).size();
    ret = mul(ret, p2[k - p]);
    for (int x = 0; x < 26; x++) {
      int sum = add(pre[k][x], -pre[p][x]);
      sum = mul(sum, pinv2[n - (k - 1) - 1]);
      if (sum) {
        string put = s[p] + (char) ('a' + x) + s[p];
        int position = (int) s[p].size();
        vector<int> pos = kmp(put, ask);
        int add_ret = 0;
        for (auto &j : pos) {
          add_ret += (j <= position && position <= j + (int) ask.size() - 1);
        }
        ret = add(ret, mul(sum, add_ret));
      }
    }
    cout << ret << "\n";
  }

}