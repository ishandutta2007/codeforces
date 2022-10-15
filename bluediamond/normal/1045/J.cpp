#include <bits/stdc++.h>

using namespace std;

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rng(228);

typedef unsigned long long ll;
const int N = (int) 1e5 + 7;
int n;
int temp;
int ff[N];
int ss[N];
ll pw[N];
ll tr[26];
int up[N];
ll hup[N][101];
vector<pair<int, int>> g[N];
vector<int> squid[N];
int sub[N];
int par[N];
int dep[N];
int group[N];
int groups;
bool connected[N];

const int K = 18;
int ancestor[N][K];
int euler_tour[2 * N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
pair<int, int> tab_lca[2 * N][K];
int xx[N], yy[N];
string qq[N];

void dfsLca(int a) {
  euler_tour[++tour_sz] = a;
  first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
  for (auto &it : g[a]) {
    int b = it.first;
    if (b == par[a]) continue;
    dfsLca(b);
    euler_tour[++tour_sz] = a;
    last_time_on_tour[a] = tour_sz;
  }
}

void lcaTM() {
  dfsLca(1);
  for (int i = 2; i <= tour_sz; i++) {
    lg2[i] = 1 + lg2[i / 2];
  }
  for (int i = 1; i <= tour_sz; i++) {
    tab_lca[i][0] = {dep[euler_tour[i]], euler_tour[i]};
  }
  for (int k = 1; (1 << k) <= tour_sz; k++) {
    for (int i = 1; i + (1 << k) - 1 <= tour_sz; i++) {
      tab_lca[i][k] = min(tab_lca[i][k - 1], tab_lca[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int lca(int a, int b) {
  if (first_time_on_tour[a] > last_time_on_tour[b]) {
    swap(a, b);
  }
  a = first_time_on_tour[a];
  b = last_time_on_tour[b];
  int k = lg2[b - a + 1];
  return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}


ll getR() {
  return (ll) rng() * rng() + rng();
}



void dfs1(int a, int p = 0) {
  ff[a] = ++temp;
  sub[a] = 1;
  par[a] = p;

  for (int j = 1; j <= min(100, dep[a]); j++) {
    hup[a][j] = tr[up[a]] + hup[p][j - 1] * pw[1];
  }

  for (auto &it : g[a]) {
    int b = it.first;
    if (b == p) continue;
    dep[b] = 1 + dep[a];
    up[b] = it.second;
    dfs1(b, a);
    sub[a] += sub[b];
  }
  ss[a] = temp;

}

void dfs2(int a) {
  squid[group[a]].push_back(a);
  int c = 0;
  for (auto &it : g[a]) {
    int b = it.first;
    if (b == par[a]) continue;
    if (sub[b] > sub[c]) {
      c = b;
    }
  }
  if (!c) return;
  {
    connected[c] = 1;
    group[c] = group[a];
    dfs2(c);
  }
  for (auto &it : g[a]) {
    int b = it.first;
    if (b == par[a]) continue;
    if (b != c) {
      group[b] = ++groups;
      dfs2(b);
    }
  }
}

string getstr(int a, int b) {
  string sol;
  while (!(ff[a] <= ff[b] && ff[b] <= ss[a])) {
    sol += (char) ('a' + up[a]);
    a = par[a];
  }
  string t;
  while (a != b) {
    t += (char) ('a' + up[b]);
    b = par[b];
  }
  reverse(t.begin(), t.end());
  sol += t;
  return sol;
}


int cobor(int x, int cnt) {
  for (int b = 0; (1 << b) <= cnt; b++) {
    if (cnt & (1 << b)) {
      x = ancestor[x][b];
    }
  }
  return x;
}

map<ll, int> code;
int codes;
vector<int> unde[2 * N];
int pos[N];
//int og[N];

int gihun(int x, int pos) {
  int l = 0, r = (int) unde[x].size() - 1, sol = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (unde[x][m] <= pos) {
      sol = m + 1;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return sol;
}

int get(int l, int r, int x) {
  return gihun(x, r) - gihun(x, l - 1);
}

int saeByeok(int a, int c, int sz, ll h) {
  assert(code.count(h));
  int cod = code[h];
  int sol = 0;

  while (group[a] != group[c]) {
    sol += get(pos[squid[group[a]][0]], pos[a], cod);
    a = par[squid[group[a]][0]];
  }

  sol += get(pos[c], pos[a], cod);

  return sol;
  exit(0);

  /**

  int sol = 0;
  while (a != c) {
    sol += (hup[a][sz] == h);
    a = par[a];
  }
  return sol += (hup[a][sz] == h);**/
}

void placeCode(string s) {
  ll h = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    h += tr[s[i] - 'a'] * pw[i];
  }
  if (!code.count(h)) {
    code[h] = ++codes;
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);


  pw[0] = 1;
  pw[1] = 1e9 + 7;
  for (int i = 2; i < N; i++) {
    pw[i] = pw[i - 1] * pw[1];
  }

  while (1) {
    for (int i = 0; i < 26; i++) {
      tr[i] = getR();
    }
    set<ll> st;
    for (int i = 0; i < 26; i++) {
      st.insert(tr[i]);
    }
    if ((int) st.size() == 26) {
      break;
    }
  }

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    g[x].push_back({y, s[0] - 'a'});
    g[y].push_back({x, s[0] - 'a'});
  }


  dfs1(1);
  group[1] = ++groups;
  dfs2(1);
  lcaTM();


  for (int i = 1; i <= n; i++) {
    ancestor[i][0] = par[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      ancestor[i][k] = ancestor[ancestor[i][k - 1]][k - 1];
    }
  }

  int q;
  cin >> q;

  for (int i = 1; i <= q; i++) {
    cin >> xx[i] >> yy[i] >> qq[i];
    placeCode(qq[i]);
    reverse(qq[i].begin(), qq[i].end());
    placeCode(qq[i]);
    reverse(qq[i].begin(), qq[i].end());
  }


  int respect = 0;

  for (int it = 1; it <= groups; it++) {
    for (auto &x : squid[it]) {
      pos[x] = ++respect;
      for (int lv = 1; lv <= min(dep[x], 100); lv++) {
        if (code.count(hup[x][lv])) {
          int vl = code[hup[x][lv]];
          unde[vl].push_back(pos[x]);
        }
      }
    }
  }

  for (int itr = 1; itr <= q; itr++) {
    int x, y, sol = 0;
    string pat, s;
    ll path = 0, invpath = 0;
    x = xx[itr];
    y = yy[itr];
    pat = qq[itr];
    for (int i = 0; i < (int) pat.size(); i++) {
      path += tr[pat[i] - 'a'] * pw[i];
      invpath += tr[pat[(int) pat.size() - 1 - i] - 'a'] * pw[i];
    }

    int z = lca(x, y);
    int cnt = (dep[x] - dep[z]) + (dep[y] - dep[z]);

    if ((int) pat.size() > cnt) {
      cout << "0\n";
      continue;
    }



    int wx = min(dep[x], dep[z] + (int) pat.size());
    int wy = min(dep[y], dep[z] + (int) pat.size());

    if (wx < dep[x]) {
      int aux = cobor(x, dep[x] - wx - 1);
      sol += saeByeok(x, aux, (int) pat.size(), path);
      x = par[aux];
    }

    if (wy < dep[y]) {
      int aux = cobor(y, dep[y] - wy - 1);
      sol += saeByeok(y, aux, (int) pat.size(), invpath);
      y = par[aux];
    }



    s = getstr(x, y);

    if ((int) pat.size() <= (int) s.size()) {
      ll h = 0;
      for (int j = 0; j < (int) pat.size(); j++) {
        h += tr[s[(int) s.size() - (int) pat.size() + j] - 'a'] * pw[j];
      }
      sol += (h == path);

      for (int i = (int) s.size() - (int) pat.size() - 1; i >= 0; i--) {
        h -= tr[s[i + (int) pat.size()] - 'a'] * pw[(int) pat.size() - 1];
        h *= pw[1];
        h += tr[s[i] - 'a'];
        sol += (h == path);
      }
    }
    cout << sol << "\n";
  }


  return 0;
}