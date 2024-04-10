#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

struct T {
  int x, y, z;
};

const int N = (int) 1e5 + 7;
int n, a[N];

map<int, int> dist;
map<int, T> papa;
///int mn[1 << 20];

void prep() {
  assert(n <= 30);
  dist.clear();
  papa.clear();
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int mask = q.front();
    q.pop();
    for (int d = 1; d <= n; d++) {
      for (int i = 0; i + 2 * d < n; i++) {
        int mask2 = mask ^ (1 << i) ^ (1 << (i + d)) ^ (1 << (i + 2 * d));
        if (!dist.count(mask2)) {
          papa[mask2] = {i, i + d, i + 2 * d};
          dist[mask2] = dist[mask] + 1;
          q.push(mask2);
        }
      }
    }
  }
}

vector<T> ret;

void op(int x, int y, int z) {
  ret.push_back({x, y, z});
  a[x] ^= 1;
  a[y] ^= 1;
  a[z] ^= 1;
}

int prag = 6;

signed realMain() {
  /**for (n = 1; n <= 30; n++) {
    for (int j = 0; j < (1 << prag); j++) {
      mn[j] = (int) 1e9;
    }
    prep();

    if (n >= prag && n >= 8) {
      int ultimate = 0;
      for (int i = 0; i < (1 << n); i++) {
        int j = i >> (n - prag);
        mn[j] = min(mn[j], dist[i]);
      }
      for (int j = 0; j < (1 << prag); j++) {
        if (mn[j] == (int) 1e9) {
          cout << "error\n";
          return 0;
        }
        ultimate = max(ultimate, mn[j]);
      }
      cout << n << " = " << ultimate << "\n";
    }

    continue;
    bool bad = 0;
    for (int i = 0; i < (1 << n); i++) {
      if (!dist.count(i)) bad = 1;
    }
    cout << n << " : " << bad << "\n";
    ///return 0;
  }**/
  int initial;
  n = 11;
  prep();
  int len;
  cin >> len;
  initial = len;
  for (int i = 1; i <= len; i++) cin >> a[i];
  while (len - 6 >= 8) {
    int mask = 0;
    for (int i = 0; i < 6; i++) {
      mask += (1 << i) * a[len - 5 + i];
    }
    ///mask <<= (n - prag);
    for (int i = 0; i < (1 << n); i++) {
      int j = i >> (n - prag);
      if (j == mask && dist[i] <= 2) {
        mask <<= (n - prag);
        int now = i;
        for (int it = 1; it <= dist[i]; it++) {
          int x = papa[now].x, y = papa[now].y, z = papa[now].z;
          op(len - 10 + x, len - 10 + y, len - 10 + z);
          now ^= (1 << x);
          now ^= (1 << y);
          now ^= (1 << z);
        }
        break;
      }
    }
    for (int j = 0; j < 6; j++) {
      assert(a[len - j] == 0);
    }
    len -= 6;
  }
  n = len;
  prep();
  int mask = 0;
  for (int i = 0; i < n; i++) {
    if (a[i + 1]) mask += (1 << i);
  }
  if (!dist.count(mask)) {
    cout << "NO\n";
    return 0;
  }
  while (mask) {
    int x = papa[mask].x, y = papa[mask].y, z = papa[mask].z;
    op(x + 1, y + 1, z + 1);
    mask ^= (1 << x);
    mask ^= (1 << y);
    mask ^= (1 << z);
  }
  for (int i = 1; i <= initial; i++) {
    assert(a[i] == 0);
  }
  cout << "YES\n";
  cout << (int) ret.size() << "\n";
  for (auto &it : ret) {
    cout << it.x << " " << it.y << " " << it.z << "\n";
  }
  return 0;
}