#include <bits/stdc++.h>
using namespace std;

#define maxn 1010100
#define rep1(i,n) for (int i = 0; i ++ < n; )

int n;
vector<int> gr[maxn];
char lab[maxn];
int defval[maxn];
int ans[maxn];

void dfs1(int u) {
  if (lab[u] == 'I') return;
  for (auto v: gr[u]) {
    dfs1(v);
  }
  if (lab[u] == 'N') {
    defval[u] = !defval[gr[u][0]];
    return ;
  }
  int x = defval[gr[u][0]], y = defval[gr[u][1]];
  if (lab[u] == 'A') defval[u] = x and y;
  if (lab[u] == 'O') defval[u] = x or y;
  if (lab[u] == 'X') defval[u] = x ^ y;
}

void dfs2(int u, int val) {
  ans[u] = val;
  for (auto v: gr[u]) dfs2(v, val);
}

void dfs3(int u, int inv) {
  //clog << u << ' ' << inv << endl;
  if (lab[u] == 'I') {
    ans[u] = !defval[u] ^ inv;
    return;
  }
  if (lab[u] == 'N') {
    dfs3(gr[u][0], !inv);
    return;
  }
  int x = gr[u][0], y = gr[u][1];
  rep1(i, 2) {
    swap(x, y);
    if (lab[u] == 'A') {
      if (defval[y] == 0) dfs2(x, inv);
      else dfs3(x, inv);
    }
    if (lab[u] == 'O') {
      if (defval[y] == 1) dfs2(x, !inv);
      else dfs3(x, inv);
    }
    if (lab[u] == 'X') dfs3(x, inv ^ defval[y]);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) {
    string s; cin >> ws >> s;
    lab[i] = s[0];
    if (lab[i] == 'I') cin >> defval[i];
    else if (lab[i] == 'N') gr[i].resize(1);
    else gr[i].resize(2);
    for (auto& f: gr[i]) {
      cin >> f;
    }
  }

  dfs1(1);
  dfs3(1, 0);
  rep1(i, n) if (lab[i] == 'I') cout << ans[i];

  return 0;
}