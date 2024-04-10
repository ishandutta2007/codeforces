#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

struct Q {
  int pref;
  int val;
  int ind;
};

bool operator < (Q a, Q b) {
  return a.pref < b.pref;
}

const int N = (int) 1e5 + 7;
const int B = 20;
int n, a[N], q, sol[N], h[B];
Q b[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) {
    sol[i] = -1;
    cin >> b[i].pref >> b[i].val;
    b[i].ind = i;
  }
  sort(b + 1, b + q + 1);
  int kek = 1;
  int pos = 1, cnt = 0;
  for (int add = 1; add <= n; add++) {
    {
      int cur = a[add];
      for (int b = B - 1; b >= 0; b--) {
        if (cur & (1 << b)) {
          cur ^= h[b];
        }
      }
      if (cur) {
        bool done = 0;
        for (int b = B - 1; b >= 0; b--) {
          if (!h[b]) {
            if (cur & (1 << b)) {
              done = 1;
              h[b] = cur;
              break;
            }
          }
        }
        assert(done);
      } else {
        kek = mul(kek, 2);
      }
      cnt++;
    }
    while (pos <= q && b[pos].pref == add) {
      int value = b[pos].val;
      int ind = b[pos].ind;

      for (int b = B - 1; b >= 0; b--) {
        if (value & (1 << b)) {
          value ^= h[b];
        }
      }

      if (value) {
        sol[ind] = 0;
      } else {
        sol[ind] = kek;
      }


      pos++;
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << sol[i] << "\n";
  }

  return 0;
}