#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
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

const int N = (int) 2e5 + 7;
int n, ex[N], ey[N], ret[N];
vector<int> g[2 * N];
set<int> odd;
bool used[N];
int s[2 * N];
int top;

void dfs(int a) {
  while (!g[a].empty()) {
    int ind = g[a].back();
    g[a].pop_back();
    if (used[ind]) continue;
    used[ind] = 1;
    dfs(ex[ind] + ey[ind] - a);
    top ^= 1;
    if (top) s[a]++;
    else s[a]--;
    if (top) s[ex[ind] + ey[ind] - a]++;
    else s[ex[ind] + ey[ind] - a]--;
    ret[ind] = top;
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ex[i] >> ey[i];
    ey[i] += N;
    g[ex[i]].push_back(i);
    g[ey[i]].push_back(i);
    ret[i] = -1;
  }
  for (int i = 1; i < 2 * N; i++) {
    if ((int) g[i].size() & 1) {
      odd.insert(i);
    }
  }
  vector<int> edges;
  while (!(int) odd.empty()) {
    auto x = *odd.begin();
    odd.erase(x);
    while (used[g[x].back()]) {
      g[x].pop_back();
    }
    int ind = g[x].back();
    used[ind] = 1;
    g[x].pop_back();
    int y = ex[ind] + ey[ind] - x;
    edges.push_back(ind);
    if (odd.count(y)) odd.erase(y);
    else odd.insert(y);
  }
  reverse(edges.begin(), edges.end());
  /**
  /// reconst graful doar din comodidate, nu e necesar ca pot face algoritm care merge si fara
  for (int i = 1; i < 2 * N; i++) {
    vector<int> nw;
    for (auto &ind : g[i]) {
      if (!used[ind]) nw.push_back(ind);
    }
    g[i] = ind;
  }**/
  /// am decis sa nu mai sterg lol:)

  { /// ciclu euler
    for (int i = 1; i < 2 * N; i++) {
      dfs(i);
    }
  }

  for (auto &i : edges) {
    int a = ex[i], b = ey[i];
    bool found = 0;
    for (int d = -1; d <= +1; d += 2) {
      int ns1 = s[a] + d, ns2 = s[b] + d;
      if (abs(ns1) <= 1 && abs(ns2) <= 1) {
        found = 1;
        s[a] = ns1;
        s[b] = ns2;
        if (d == +1) ret[i] = 1;
        else ret[i] = 0;
        break;
      }
    }
    assert(found);
  }


  for (int i = 1; i < 2 * N; i++) {
    assert(abs(s[i]) <= 1);
  }
  for (int i = 1; i <= n; i++) {
    if (ret[i] == 0) {
      cout << "b";
    } else {
      assert(ret[i] == 1);
      cout << "r";
    }
  }
  cout << "\n";
  /**
  deci:
  e clar ca pentru nodurile cu grad par trebuie sa avem egalitate si pt cele de grad impar un delta de +- 1

  daca un nod are grad par il lasam asa adica...nu ne deranjeaza
  si daca toate au grad par => doar bagam euler

  daca exista noduri care au grad impar, gasim orice muchie y
  si stergem x-y
  indiferent ce e y... lol:) adica nu prea conteaza ce grad are y

  si acum stergem muchia si o sa avem ca x o sa fie fully echilibrat si y poate fully echilibrat / poate delta
  de 1
  coloram muchia in asa fel incat sa il rezolvam pe y in cazul in care nu e fully echilibrat

  **/

  return 0;
}