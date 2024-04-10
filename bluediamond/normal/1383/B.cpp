#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



bool can0[1000][1000][2]; /// can0[one][zero][current]

void build0() {
  can0[0][0][0] = 0;
  can0[0][0][1] = 1;

  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      int sum = (i + j);
      if (sum == 0) {
        continue;
      }
      if (sum % 2 == 0) {
        /// we want odd
        if (i - 1 >= 0) {
          can0[i][j][0] |= can0[i - 1][j][1];
          can0[i][j][1] |= can0[i - 1][j][0];
        }
        if (j - 1 >= 0) {
          can0[i][j][0] |= can0[i][j - 1][0];
          can0[i][j][1] |= can0[i][j - 1][1];
        }
      } else {
        /// we want even
        if (i == 0) {
          can0[i][j][0] = can0[i][j - 1][0];
          can0[i][j][1] = can0[i][j - 1][1];
          continue;
        }
        if (j == 0) {
          can0[i][j][0] = can0[i - 1][j][0];
          can0[i][j][1] = can0[i - 1][j][1];
          continue;
        }
        can0[i][j][0] = can0[i][j][1] = 1;
        if (can0[i - 1][j][0] == 0 || can0[i][j - 1][0] == 0) {
          can0[i][j][0] = 0;
        }
        if (can0[i - 1][j][1] == 0 || can0[i][j - 1][1] == 0) {
          can0[i][j][1] = 0;
        }
      }
    }
  }
}



bool can1[1000][1000][2]; /// can1[one][zero][current]

void build1() {
  can1[0][0][0] = 0;
  can1[0][0][1] = 1;

  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      int sum = (i + j);
      if (sum == 0) {
        continue;
      }
      if (sum % 2 == 1) {
        /// we want odd
        if (i - 1 >= 0) {
          can1[i][j][0] |= can1[i - 1][j][1];
          can1[i][j][1] |= can1[i - 1][j][0];
        }
        if (j - 1 >= 0) {
          can1[i][j][0] |= can1[i][j - 1][0];
          can1[i][j][1] |= can1[i][j - 1][1];
        }
      } else {
        /// we want even
        if (i == 0) {
          can1[i][j][0] = can1[i][j - 1][0];
          can1[i][j][1] = can1[i][j - 1][1];
          continue;
        }
        if (j == 0) {
          can1[i][j][0] = can1[i - 1][j][0];
          can1[i][j][1] = can1[i - 1][j][1];
          continue;
        }
        can1[i][j][0] = can1[i][j][1] = 1;
        if (can1[i - 1][j][0] == 0 || can1[i][j - 1][0] == 0) {
          can1[i][j][0] = 0;
        }
        if (can1[i - 1][j][1] == 0 || can1[i][j - 1][1] == 0) {
          can1[i][j][1] = 0;
        }
      }
    }
  }
}

bool ok(int o, int z) {
  if ((o + z) % 2 == 0) {
    return can0[o][z][0];
  } else {
    return can1[o][z][0];
  }
}

bool ok2(int o, int z) {
  int lg = log2(o);
  if (o % 4 == 0) {
    return 0;
  }
  if (o % 4 == 3) {
    return z % 2;
  }
  return 1;
}

void build() {
  build0();
  build1();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  build();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll t = 0LL;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      t ^= a[i];
    }
    if (t == 0) {
      cout << "DRAW\n";
      continue;
    }
    int bit = log2(t), ones = 0, zeroes = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] & (1LL << bit)) {
        ones++;
      } else {
        zeroes++;
      }
    }
    if (ok2(ones, zeroes)) {
      cout << "WIN\n";
    } else {
      cout << "LOSE\n";
    }
    /// the first player wins if there are an odd number of ones

  }
  return 0;
}