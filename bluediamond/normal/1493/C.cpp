#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n, k, v[N], f[26], sumcost;
string s;

int getcost(int i) {
  if (f[i] % k == 0) return 0;
  return k - f[i] % k;
}

void print() {
  int total = 0;
  for (int x = 0; x < 26; x++) {
    total += getcost(x);
  }
  for (int pre = n; pre >= 0; pre--) {
    /// I wanna make the common prefix as long as possible
    if (pre == n) {
      bool good = 1;
      for (int x = 0; x < 26; x++) {
        if (f[x] % k != 0) {
          good = 0;
          break;
        }
      }
      if (good) {
        for (int i = 1; i <= n; i++) {
          cout << (char) ('a' + v[i]);
        }
        cout << "\n";
        return;
      }
      total -= getcost(v[pre]);
      f[v[pre]]--;
      total += getcost(v[pre]);
      continue;
    }
    int limit = v[pre + 1];
    for (int x = limit + 1; x < 26; x++) {
      total -= getcost(x);
      f[x]++;
      total += getcost(x);

      if (pre + 1 + total <= n) {
        int cntA = n - (1 + pre + total);
        for (int i = 1; i <= pre; i++) {
          cout << (char) ('a' + v[i]);
        }
        cout << (char) ('a' + x);
        for (int i = 1; i <= cntA; i++) {
          cout << 'a';
        }
        int y = 0;
        for (int x = 0; x < 26; x++) {
          if (f[x] % k != 0) {
            for (int j = 1; j <= k - f[x] % k; j++) {
              cout << (char) ('a' + x);
              y++;
            }
          }
        }
        cout << "\n";
        return;
      }


      total -= getcost(x);
      f[x]--;
      total += getcost(x);
    }
    total -= getcost(v[pre]);
    f[v[pre]]--;
    total += getcost(v[pre]);
  }
  assert(0);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    if (n % k) {
      cout << "-1\n";
      continue;
    }
    for (int x = 0; x < 26; x++) {
      f[x] = 0;
    }
    for (int i = 1; i <= n; i++) {
      v[i] = s[i - 1] - 'a';
      f[v[i]]++;
    }
    print();
  }
}