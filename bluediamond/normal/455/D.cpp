#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

///#pragma GCC target("avx2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


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

const int N = (int) 1e5 + 7;
const int K = 333;
int n, init[N], q, ret, sq, f[K][N];
vector<int> bucket[N];

int cnt(int pre, int k) {
  int cur = 0, ret = 0, ind = 1;
  while (cur < pre) {
    if (cur + (int) bucket[ind].size() <= pre) {
      ret += f[ind][k];
      cur += (int) bucket[ind].size();
      ind++;
      continue;
    }
    for (auto &x : bucket[ind]) {
      if (cur == pre) break;
      ret += (x == k);
      cur++;
    }
    ind++;
  }
  return ret;
}

void reconst() {
  int cur = 0;
  for (int b = 1; b <= (n - 1) / sq + 1; b++) {
    for (auto &x : bucket[b]) {
      f[b][x] = 0;
      init[++cur] = x;
    }
    bucket[b].clear();
  }
  for (int i = 1; i <= n; i++) {
    int k = (i - 1) / sq + 1;
    f[k][init[i]]++;
    bucket[k].push_back(init[i]);
  }
}

signed realMain() {
  cin >> n;
  sq = sqrt(n);
  for (int i = 1; i <= n; i++) {
    cin >> init[i];
    int k = (i - 1) / sq + 1;
    f[k][init[i]]++;
    bucket[k].push_back(init[i]);
  }
  cin >> q;
  for (int step = 1; step <= q; step++) {
    if (step % sq == 0) {
      reconst();
    }
    int type, l, r, askval;
    cin >> type >> l >> r;
    l = (l + ret - 1) % n + 1;
    r = (r + ret - 1) % n + 1;
    if (l > r) swap(l, r);
    if (type == 2) {
      cin >> askval;
      askval = (askval + ret - 1) % n + 1;
    }

    if (type == 1) {
      if (l == r) {
        continue;
      }
      int ind = 1, cur = 0;
      while (1) {
        cur += (int) bucket[ind].size();
        if (cur < r) {
          ind++;
        } else {
          break;
        }
      }
      cur -= (int) bucket[ind].size();
      cur = r - cur;
      vector<int> nw;
      int deleted;
      for (int j = 0; j < (int) bucket[ind].size(); j++) {
        if (j != cur - 1) {
          nw.push_back(bucket[ind][j]);
        } else {
          deleted = bucket[ind][j];
        }
      }
      f[ind][deleted]--;
      bucket[ind] = nw;
      ind = 1, cur = 0;
      while (1) {
        cur += (int) bucket[ind].size();
        if (cur < l) {
          ind++;
        } else {
          break;
        }
      }
      cur -= (int) bucket[ind].size();
      cur = l - cur;
      nw.clear();
      for (int j = 0; j < (int) bucket[ind].size(); j++) {
        if (j == cur - 1) {
          nw.push_back(deleted);
        }
        nw.push_back(bucket[ind][j]);
      }
      f[ind][deleted]++;
      bucket[ind] = nw;
    } else {
      ret = cnt(r, askval) - cnt(l - 1, askval);
      cout << ret << "\n";
    }
  }
  return 0;
}