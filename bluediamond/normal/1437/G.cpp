#include <bits/stdc++.h>

using namespace std;

struct trie {
  unordered_map<int, trie*> k;
  trie *f;
  trie *f2;
  bool gol;
  int id;
  trie() {
    gol = 1;
    f = 0;
    f2 = 0;
    id = 0;
  }
};

trie *root = new trie;
const int N = (int) 3e5 + 7;
int v[N];
int o[N];
int p[N];
int value[N];
int id;
multiset<int> values[N];
vector<trie*> ord;
trie* w[N];

void ins(string s, int i) {
  trie *cur = root;
  for (auto &c : s) {
    int x = c - 'a';
    if (!cur->k[x]) {
      cur->k[x] = new trie;
    }
    cur = cur->k[x];
  }
  if (cur->id == 0) {
    cur->id = ++id;
  }
  o[i] = cur->id;
  values[cur->id].insert(0);
  cur->gol = 0;
  w[i] = cur;
}


void fo() {
  queue<trie*> q;
  q.push(root);
  while (!q.empty()) {
    trie* cur = q.front();
    ord.push_back(cur);
    q.pop();
    for (int x = 0; x < 26; x++) {
      if (cur->k[x]) {
        q.push(cur->k[x]);
      }
    }
  }
  for (auto &cur : ord) {
    for (int x = 0; x < 26; x++) {
      if (cur->k[x]) {
        trie *now = cur->k[x];
        if (cur == root) {
          now->f = root;
        } else {
          now->f = cur->f;
          while (now->f != root && !now->f->k[x]) {
            now->f = now->f->f;
          }
          if (now->f->k[x]) {
            now->f = now->f->k[x];
          }
        }
      }
    }
    cur->f2 = cur->f;
    if (!cur->f2->id) {
      cur->f2 = cur->f2->f2;
    }
    p[cur->id] = cur->f2->id;
  }
}

vector<int> g[N];
int dim[N];
bool con[N];
int cols;
int col[N];
int posid[N];
int first[N];
int last[N];
int nodes[N];
vector<int> reps[N];

void dfs(int a) {
  dim[a] = 1;
  if (g[a].empty()) {
    return;
  }
  int c = N - 1;
  for (auto &b : g[a]) {
    dfs(b);
    dim[a] += dim[b];
    if (dim[b] > dim[c]) {
      c = b;
    }
  }
  con[c] = 1;
}

void dfs2(int a) {
  if (!con[a]) {
    cols++;
    col[a] = cols;
  } else {
    col[a] = col[p[a]];
  }
  reps[col[a]].push_back(a);
  for (auto &b : g[a]) {
    dfs2(b);
  }
}

int t[4 * N];

void upd(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    t[v] = x;
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, x);
  upd(2 * v + 1, tm + 1, tr, i, x);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return -1;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int n;
int m;

void upd(int i, int x) {
  upd(1, 1, n, i, x);
}

int get(int l, int r) {
  return get(1, 1, n, l, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    ins(s, i);
  }
  root->f = root;
  root->f2 = root;
  fo();
  trie *cur = root;
  for (int i = 1; i <= n; i++) {
    g[p[i]].push_back(i);
  }
  dfs(0);
  dfs2(0);
  int y = 0;
  for (int i = 1; i <= n; i++) {
    for (auto &x : reps[i]) {
      posid[x] = ++y;
      nodes[y] = x;
      last[x] = y;
      if (first[x] == 0) {
        first[x] = y;
      }
    }
  }
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      values[o[i]].erase(values[o[i]].find(-v[i]));
      v[i] = x;
      values[o[i]].insert(-v[i]);
      int nv = -*values[o[i]].begin();
      if (nv != value[o[i]]) {
        value[o[i]] = nv;
        upd(posid[o[i]], nv);
      }
    } else {
      string s;
      cin >> s;
      int sol = -1;
      trie *cur = root;
      for (auto &c : s) {
        int x = c - 'a';
        while (cur != root && !cur->k[x]) {
          cur = cur->f;
        }
        if (cur->k[x]) {
          cur = cur->k[x];
        }
        trie *now = cur;
        if (now->id) {
          sol = max(sol, value[now->id]);
        }
        int node = now->f2->id;
        while (1) {
          int c = col[node];
          sol = max(sol, get(posid[reps[col[node]][0]] + (col[node] == col[0]), posid[node]));
          if (col[node] == col[0]) {
            break;
          }
          node = p[reps[col[node]][0]];
        }
      }
      cout << sol << "\n";
    }
  }
}