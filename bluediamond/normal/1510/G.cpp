#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
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
**/
signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 100 + 7;
const int INF = (int) 1e9;
int n, want, revin[N][N], sub[N], acum[N], pa[N][N], sp[N][N], paps_who[N][N], paps_cnt[N][N], spcnt[N][N]; /// in dinamici tin minte nr de muchii
vector<int> g[N];

void build_sub(int a) {
  sub[a] = 1;
  for (auto &b : g[a]) {
    build_sub(b);
    sub[a] += sub[b];
  }
}

void build_revin(int a) {
  revin[a][1] = 0;
  int cur = 1;
  for (auto &b : g[a]) {
    build_revin(b);
    for (int j = cur; j >= 1; j--) {
      if (revin[a][j] == INF) continue;
      for (int fb = 1; fb <= sub[b]; fb++) {
        int relax = revin[a][j] + revin[b][fb] + 2;
        if (relax < revin[a][j + fb]) {
          revin[a][j + fb] = relax;
        }
      }
    }
    cur += sub[b];
  }
  assert(cur == sub[a]);
}

void build_pa(int a) {
  for (auto &b : g[a]) {
    build_pa(b);
  }
  pa[a][1] = 0;
  for (auto &spec : g[a]) {
    for (int j = 0; j <= sub[a]; j++) {
      acum[j] = INF;
    }
    acum[1] = 0;
    int cur = 1;
    for (auto &b : g[a]) {
      if (b == spec) continue;
      for (int j = cur; j >= 1; j--) {
        if (acum[j] == INF) continue;
        for (int fb = 1; fb <= sub[b]; fb++) {
          int relax = acum[j] + revin[b][fb] + 2;
          if (relax < acum[j + fb]) {
            acum[j + fb] = relax;
          }
        }
      }
      cur += sub[b];
    }
    for (int j = cur; j >= 1; j--) {
      for (int fs = 1; fs <= sub[spec]; fs++) {
        int relax = acum[j] + pa[spec][fs] + 1;
        if (relax < pa[a][j + fs]) {
          pa[a][j + fs] = relax;
          sp[a][j + fs] = spec;
          spcnt[a][j + fs] = fs;
        }
      }
    }
    cur += sub[spec];
    assert(cur == sub[a]);
  }
}

vector<int> ret;

void rec(int a, int k, bool intorc) {
  ret.push_back(a);
  if (k == 1) return;
  if (!intorc) {
    int spec = sp[a][k];
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        paps_cnt[i][j] = paps_who[i][j] = -100;
      }
    }
    for (int j = 0; j <= sub[a]; j++) {
      acum[j] = INF;
    }
    acum[1] = 0;
    int id = 0;
    int cur = 1;
    vector<int> nospec;
    for (auto &b : g[a]) {
      if (b == spec) continue;
      id++;
      nospec.push_back(b);
      for (int j = 1; j <= cur; j++) {
        if (acum[j] == INF) continue;
        paps_who[id][j] = -1;
        paps_cnt[id][j] = -1;
      }
      for (int j = cur; j >= 1; j--) {
        if (acum[j] == INF) continue;
        for (int fb = 1; fb <= sub[b]; fb++) {
          int relax = acum[j] + revin[b][fb] + 2;
          if (relax < acum[j + fb]) {
            acum[j + fb] = relax;
            paps_cnt[id][j + fb] = fb;
            paps_who[id][j + fb] = b;
          }
        }
      }
      cur += sub[b];
    }
    //for (int j = cur; j >= 1; j--) {
     // for (int fs = 1; fs <= sub[spec]; fs++) {
        int fs = spcnt[a][k], j = k - fs;
      ///  cout << "node " << a << ", spec = " << spec << " and " << fs << " with " << j << "\n";
        int relax = acum[j] + pa[spec][fs] + 1;
        if (relax == pa[a][k]) {
          /// pe guy-ul j
          {
            /// id and j
            vector<pair<int, int>> lmao;
            while (j > 1) {
              assert(paps_cnt[id][j] != -100);
              assert(paps_who[id][j] != -100);
              if (paps_cnt[id][j] == -1) {
                id--;
              } else {
                int b = nospec[id - 1], ct = paps_cnt[id][j];
                assert(b == paps_who[id][j]);
                id--;
                j -= ct;
                lmao.push_back({b, ct});

              }
            }
            for (auto &it : lmao) {
              rec(it.first, it.second, 1);
                            ret.push_back(a);
            }
          }
          rec(spec, fs, 0);
          return;
        }
    //  }
    ///}
    cout << "sad\n";
    exit(0);
  } else {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        paps_cnt[i][j] = paps_who[i][j] = -100;
      }
    }
    for (int j = 0; j <= n; j++) {
      revin[a][j] = INF;
    }
    revin[a][1] = 0;
    int cur = 1, id = 0;
    for (auto &b : g[a]) {
      id++;
      for (int j = 1; j <= cur; j++) {
        if (revin[a][j] == INF) continue;
        paps_who[id][j] = -1;
        paps_cnt[id][j] = -1;
      }
      for (int j = cur; j >= 1; j--) {
        if (revin[a][j] == INF) continue;
        for (int fb = 1; fb <= sub[b]; fb++) {
          int relax = revin[a][j] + revin[b][fb] + 2;
          if (relax < revin[a][j + fb]) {
            revin[a][j + fb] = relax;
            paps_who[id][j + fb] = b;
            paps_cnt[id][j + fb] = fb;
          }
        }
      }
      cur += sub[b];
    }
    int j = k;
          /// pe guy-ul j
          {
            /// id and j
            vector<pair<int, int>> lmao;
            while (j > 1) {
              assert(paps_cnt[id][j] != -100);
              assert(paps_who[id][j] != -100);
              if (paps_cnt[id][j] == -1) {
                id--;
              } else {
                int b = g[a][id - 1], ct = paps_cnt[id][j];
                assert(b == paps_who[id][j]);
                id--;
                j -= ct;
                lmao.push_back({b, ct});
              }
            }
            for (auto &it : lmao) {
              rec(it.first, it.second, 1);
              ret.push_back(a);
            }
          }
  }
}

void clr() {
  for (int i = 0; i < N; i++) {
    g[i].clear();
    sub[i] = acum[i] = 0;
    for (int j = 0; j < N; j++) {
      revin[i][j] = pa[i][j] = INF;
      paps_who[i][j] = paps_cnt[i][j] = -100;
    }
  }
}

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> want;
    clr();
    for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      g[p].push_back(i);
      if (home) {
        cout << "edge : ";
        cout << p << " " << i << "\n";
      }
    }
    build_sub(1);
    build_revin(1);
    build_pa(1);
    cout << pa[1][want] << "\n";
    assert(pa[1][want] <= revin[1][want]);
    ret.clear();
    rec(1, want, 0);
    assert((int) ret.size() == pa[1][want] + 1);
    for (auto &x : ret) {
      cout << x << " ";
    }
    cout << "\n";
    if (home) {
      cout << "#############\n";
    }
  }
  return 0;
}