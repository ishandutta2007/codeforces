#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;
const int INF = (int) 1e9 + 8;
int n, s, a[N], indz, dp[N][N][2], idx[N];
vector<int> pos[N];

int dist(int a, int b) {
  return min(abs(a - b), n - abs(a - b));
}


void pdir(int a, int b) {
  int d = dist(a, b);
  if (a <= b) {
    if (abs(a - b) == d) {
      cout << "+" << d << "\n";
    } else {
      cout << "-" << d << "\n";
    }
  } else {
    if (abs(a - b) == d) {
      cout << "-" << d << "\n";
    } else {
      cout << "+" << d << "\n";
    }
  }
}


int getant(int i) {
  int sz = (int) pos[a[i]].size();
  return pos[a[i]][(idx[i] - 1 + sz) % sz];
}

int getnxt(int i) {
  int sz = (int) pos[a[i]].size();
  return pos[a[i]][(idx[i] + 1 + sz) % sz];
}

int get(int l, int r, int type) {
  int &ret = dp[l][r][type];
  if (ret != -1) {
    return ret;
  }
  int p = (type == 0) ? l : r;
  int nxtl = getant(l);
  int nxtr = getnxt(r);
  int sz = (int) pos[a[l]].size(), done;
  if (l <= r) {
    done = idx[r] - idx[l] + 1;
  } else {
    done = sz - (idx[l] - idx[r] - 1);
  }
  if (done == sz) {
    int nxt = a[l] + 1;
    if (pos[nxt].empty()) {
      return ret = 0;
    }
    ret = INF;
    for (auto &i : pos[nxt]) {
      ret = min(ret, dist(p, i) + get(i, i, 0));
    }
    return ret;
  }
  return ret = min(get(nxtl, r, 0) + dist(p, nxtl), get(l, nxtr, 1) + dist(p, nxtr));
}

void print(int l, int r, int type) {
  int &ret = dp[l][r][type];
  assert(ret != -1);
  int p = (type == 0) ? l : r;
  int nxtl = getant(l);
  int nxtr = getnxt(r);
  int sz = (int) pos[a[l]].size(), done;
  if (l <= r) {
    done = idx[r] - idx[l] + 1;
  } else {
    done = sz - (idx[l] - idx[r] - 1);
  }
  if (done == sz) {
    int nxt = a[l] + 1;
    if (pos[nxt].empty()) {
      return;
    }
    for (auto &i : pos[nxt]) {
      if (ret == dist(p, i) + get(i, i, 0)) {
        pdir(p, i);
        print(i, i, 0);
        return;
      }
    }
    assert(0);
  }
  if (ret == get(nxtl, r, 0) + dist(p, nxtl)) {
    pdir(p, nxtl);
    print(nxtl, r, 0);
  } else {
    pdir(p, nxtr);
    print(l, nxtr, 1);
  }
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j][0] = dp[i][j][1] = -1;
    }
  }

  cin >> n >> s;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]] = 0;
  }
  for (auto &it : mp) {
    it.second = ++indz;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
    idx[i] = (int) pos[a[i]].size();
    pos[a[i]].push_back(i);
  }
  int sol = INF;
  for (auto &p : pos[1]) {
    sol = min(sol, get(p, p, 0) + dist(s, p));
  }
  cout << sol << "\n";
  for (auto &p : pos[1]) {
    if (get(p, p, 0) + dist(s, p) == sol) {
      pdir(s, p);
      print(p, p, 0);
      return 0;
    }
  }
  return 0;
}