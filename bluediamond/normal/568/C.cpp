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

const int N = 400 + 7;
const int A = 26;
int n, m, top, o[N], tip[N], cur;
bool one[N], vis[N];
vector<int> g[N], ginv[N];

void dfs1(int a) {
  vis[a] = 1;
  for (auto &b : g[a]) {
    if (!vis[b]) {
      dfs1(b);
    }
  }
  o[++top] = a;
}

void dfs2(int a) {
  vis[a] = 1;
  tip[a] = cur;
  for (auto &b : ginv[a]) {
    if (!vis[b]) {
      dfs2(b);
    }
  }
}

int inv(int x) {
  if (x > n) return x - n;
  return x + n;
}

bool stuff() {
  for (int i = 1; i <= 2 * n; i++) {
    for (auto &j : g[i]) {
      ginv[j].push_back(i);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (!vis[i]) {
      dfs1(i);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    vis[i] = 0;
  }
  for (int i = 2 * n; i >= 1; i--) {
    int node = o[i];
    if (!vis[node]) {
      cur++;
      dfs2(node);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    g[i].clear();
    ginv[i].clear();
    vis[i] = 0;
  }
  cur = 0;
  top = 0;
  for (int i = 1; i <= n; i++) {
    if (tip[i] == tip[inv(i)]) {
      return 0;
    }
  }
  return 1;
}

int rules;
string s;
bool vov[A], cons[A];
int type[N];
vector<int> i1, vov1, i2, vov2;

void implica(int i, int j) {
  g[i].push_back(j);
  g[inv(j)].push_back(inv(i));
}

void fa(int i, int x) {
  if (x == 0) {
    g[i].push_back(inv(i));
  } else {
    g[inv(i)].push_back(i);
  }
}

bool kek() {
  for (int i = 1; i <= n; i++) {
    if (type[i] == 1) {
      fa(i, 0);
    }
    if (type[i] == 10) {
      fa(i, 1);
    }
  }
  for (int j = 0; j < rules; j++ ){
    int p1 = i1[j], p2 = i2[j];
    int k1, k2;
    if (!vov1[j]) k1 = p1; else k1 = inv(p1);
    if (!vov2[j]) k2 = p2; else k2 = inv(p2);
    implica(k1, k2);
  }
  return stuff();
}



signed realMain() {
  cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == 'V') vov[i] = 1;
    else cons[i] = 1;
  }
  cin >> n >> rules;
  i1.resize(rules);
  vov1.resize(rules);
  i2.resize(rules);
  vov2.resize(rules);
  for (int i = 0; i < rules; i++) {
    string s1, s2;
    cin >> i1[i] >> s1 >> i2[i] >> s2;
    vov1[i] = (s1[0] == 'V');
    vov2[i] = (s2[0] == 'V');
    if (vov2[i]) {
      bool found = 0;
      for (auto &ch : s) {
        found |= (ch == 'V');
      }
      if (!found && vov1[i] != vov2[i]) {
        cout << "-1\n";
        return 0;
      }
    } else {
      bool found = 0;
      for (auto &ch : s) {
        found |= (ch == 'C');
      }
      if (!found && vov1[i] != vov2[i]) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  string t;
  cin >> t;
  for (int i = 1; i <= n; i++) {
    int x = t[i - 1] - 'a';
    if (vov[x]) type[i] = 1;
    else type[i] = 10;
  }
  if (kek()) {
    cout << t << "\n";
    return 0;
  }
  int pre = n;
  while (pre >= 1) {
    pre--;
    vector<int> vs, cs;
    for (int j = t[pre] - 'a' + 1; j < (int) s.size(); j++) {
      if (vov[j]) vs.push_back(j);
      else cs.push_back(j);
    }
    if (!vs.empty()) vs.resize(1);
    if (!cs.empty()) cs.resize(1);
    if (cs.empty() && vs.empty()) {
      type[pre + 1] = 100;
      continue;
    }
    if (!cs.empty() && !vs.empty()) {
      type[pre + 1] = 100;
      if (!kek()) {
        type[pre + 1] = 100;
        continue;
      }
    }
    if (vs.empty()) {
      type[pre + 1] = 10;
      if (!kek()) {
        type[pre + 1] = 100;
        continue;
      }
    }
    if (cs.empty()) {
      type[pre + 1] = 1;
      if (!kek()) {
        type[pre + 1] = 100;
        continue;
      }
    }
    vector<int> kol;
    for (auto &it : vs) kol.push_back(it);
    for (auto &it : cs) kol.push_back(it);
    sort(kol.begin(), kol.end());
    for (auto &it : kol) {
      if (vov[it]) {
        type[pre + 1] = 1;
      } else {
        type[pre + 1] = 10;
      }
      if (kek()) {
        for (int j = 1; j <= pre; j++) {
          cout << t[j - 1];
        }
        cout << (char) (it + 'a');
        int len = pre + 1;
        while (len < n) {
          len++;
          vs.clear();
          cs.clear();
          for (int j = 0; j < (int) s.size(); j++) {
            if (vov[j]) vs.push_back(j);
            else cs.push_back(j);
          }
          if (!vs.empty()) vs.resize(1);
          if (!cs.empty()) cs.resize(1);
          vector<int> kol;
          for (auto &it : vs) kol.push_back(it);
          for (auto &it : cs) kol.push_back(it);
          sort(kol.begin(), kol.end());
          bool found = 0;
          int step = 0;
          for (auto &it : kol) {
            step++;
            if (vov[it]) {
              type[len] = 1;
            } else {
              type[len] = 10;
            }
            if (step == 2) {
              cout << (char) (it + 'a');
              found = 1;
              break;
            }
            if (kek()) {
              cout << (char) (it + 'a');
              found = 1;
              break;
            }
          }
        }
        cout << "\n";
        exit(0);
      }
    }
    type[pre + 1] = 100;
  }
  cout << "-1\n";
  return 0;
}