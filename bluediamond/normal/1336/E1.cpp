#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a - M;
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


const int N = (int) 2e5 + 7;
const int B = 35 + 1;
int n;
int m;
int pos = 1;
int cnt[B];
int id[B];
ll a[N];
int dp[B][1 << 15];

ll how_many(ll x) {
  if (x == 0) {
    return 0;
  }
  x -= x & (-x);
  return 1 + how_many(x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int b = 0; b < m; b++) {
    int where = -1;
    for (int i = pos; i <= n; i++) {
      if (a[i] & (1LL << b)) {
        where = i;
        break;
      }
    }
    if (where == -1) {
      continue;
    }
    swap(a[where], a[pos]);
    id[b] = pos;
    pos++;
    for (int j = 1; j <= n; j++) {
      if ((a[j] & (1LL << b)) && j != pos - 1) {
        a[j] ^= a[pos - 1];
      }
    }
  }
  int rem = n - pos + 1;
  rem = pw(2, rem);
  n = pos - 1;
  for (int i = 0; i < n; i++) {
    a[i] = a[i + 1];
  }
  if (n <= 20) {
    for (int mask = 0; mask < (1 << n); mask++) {
      ll val = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          val ^= a[i];
        }
      }
      cnt[how_many(val)]++;
    }
  } else {
    int ov = 0;
    for (int i = 0; i < m; i++) {
      if (id[i] == 0) {
        id[i] = ov++;
      } else {
        id[i] = -1;
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      int mask = 0;
      for (int j = 0; j < m; j++) {
        if (id[j] != -1) {
          if (a[i] & (1LL << j)) {
            mask += (1 << id[j]);
          }
        }
      }
      for (int cnt = i; cnt >= 0; cnt--) {
        for (int m = 0; m < (1 << ov); m++) {
          if (dp[cnt][m]) dp[cnt + 1][m ^ mask] = add(dp[cnt + 1][m ^ mask], dp[cnt][m]);
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int mask = 0; mask < (1 << ov); mask++) {
        cnt[how_many(mask) + i] = add(cnt[how_many(mask) + i], dp[i][mask]);
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    cnt[i] = mul(cnt[i], rem);
    cout << cnt[i] << " ";
  }
  cout << "\n";
}