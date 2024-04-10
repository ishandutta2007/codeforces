#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int dep[100005];
set<int> ch[100005];
int fa[100005];

vector<int> opseq;

void chfa(int u, int si) {
  assert(fa[u] == fa[si]);
  assert(u != si);
  ch[fa[u]].erase(u);
  fa[u] = si;
  ch[si].insert(u);
  opseq.push_back(u);
}

void dfs1(int u) {
  dep[u] = 1;
  for (int v : ch[u]) {
    dfs1(v);
    dep[u] = max(dep[u], dep[v] + 1);
  }
}

void merg(int u, int si) {
  // make si become the root of a bamboo
  vector<int> ech(all(ch[si]));
  chfa(u, si);
  int prev = u;
  for (int i : ech) {
    merg(prev, i);
    prev = i;
  }
}

void dfs2(int u) {
  if (ch[u].size() == 0)
    return;
  vector<int> ech(all(ch[u]));
  int prev, targ;
  for (int v : ch[u])
    if (dep[v] + 1 == dep[u]) {
      dfs2(v);
      prev = targ = v;
      break;
    }
  for (int i : ech) {
    if (i == targ)
      continue;
    merg(prev, i);
    prev = i;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  fa[0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> fa[i];
    ch[fa[i]].insert(i);
  }
  dfs1(0);
  dfs2(0);
  cout << 0;
  int cur = 0;
  for (int i = 0; i < n - 1; i++) {
    assert(ch[cur].size() == 1);
    cur = *ch[cur].begin();
    cout << ' ' << cur;
  }
  cout << endl;
  reverse(all(opseq));
  cout << opseq.size() << endl;
  for (int i : opseq)
    cout << i << ' ';
  cout << endl;
}