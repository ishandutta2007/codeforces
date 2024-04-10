#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();


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

const int N = (int) 4e5 + 7;

struct node {
  node* k[26];
  node* tol[26];
  node* to;
  int cnt;
  int id;
  node() {
    id = 0;
    for (int j = 0; j < 26; j++) {
      k[j] = 0;
      tol[j] = 0;
    }
    cnt = 0;
    to = 0;
  }
};

node* root = new node;
vector<node*> ord;

void bfs() {
  queue<node*> q;
  q.push(root);
  while (!q.empty()) {
    node *now = q.front();
    ord.push_back(now);
    q.pop();
    for (int j = 0; j < 26; j++) {
      if (now->k[j]) {
        q.push(now->k[j]);
      }
    }
  }
}

int l[N], r[N], t, aib[N];
vector<int> g2[N];

void add_aib(int i, int x) {
  while (i < N) aib[i] += x, i += i & (-i);
}

int get_aib(int i) {
  int ret = 0;
  while (i) {
    ret += aib[i], i -= i & (-i);
  }
  return ret;
}

void add(int node, int val) {
  add_aib(l[node], val);
}

int get(int node) {
  return get_aib(r[node]) - get_aib(l[node] - 1);
}

void rec(node* now) {

  if (now != root) {
    g2[now->to->id].push_back(now->id);
  }
  for (int j = 0; j < 26; j++) {
    if (now->k[j]) {
      rec(now->k[j]);
    }
  }
}

void dfs(int a) {
  t++;
  l[a] = t;
  for (auto &b : g2[a]) {
    dfs(b);
  }
  r[a] = t;
}

void build(vector<string> v) {
  int y = (int) v.size();
  int pz = 0;
  int kek = 0;
  for (auto &s : v) {
    node* now = root;
    for (auto &ch : s) {
      int x = ch - 'a';
      if (!now->k[x]) {
        now->k[x] = new node;
        now->k[x]->id = ++kek;
      }
      now = now->k[x];
    }
  }
  bfs();
  root->to = root;
  for (auto &now : ord) {
    for (int j = 0; j < 26; j++) {
      if (now->k[j]) {
        node* sol = now->to;
        while (sol != root && !sol->k[j]) {
          sol = sol->to;
        }
        if (now != root && sol->k[j]) {
          sol = sol->k[j];
        }
        now->k[j]->to = sol;
      }
    }
  }
  rec(root);
  dfs(0);
  for (auto &now : ord) {
    for (int j = 0; j < 26; j++) {
      node* state = now;
      if (state != root && !state->k[j]) {
        state = state->to;
      }
      if (state->k[j]) {
        state = state->k[j];
      } else {
        if (state != root) {
          state = state->tol[j];
        }
      }
      now->tol[j] = state;
    }
  }
}

int n, q;
char to_end[N];
int id[N], sol[N];
vector<int> g[N];
bool vis[N];
vector<pair<int, int>> asking[N];

vector<node*> states;

void solve(int i, node* state) {
  vis[i] = 1;
  states.push_back(state);
  node* before = state;
  for (auto &j : g[i]) {
    state = before->tol[to_end[j] - 'a'];
    int node = state->id;
    add(node, +1);
    solve(j, state);
    add(node, -1);
  }
  states.pop_back();
  for (auto &it : asking[i]) {
    sol[it.second] = get(it.first);
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int type;
    cin >> type;
    if (type == 2) cin >> id[i];
    string s;
    cin >> s;
    to_end[i] = s[0];
    g[id[i]].push_back(i);
  }
  cin >> q;
  vector<int> ask(q);
  vector<string> v(q);
  for (int i = 0; i < q; i++) {
    cin >> ask[i] >> v[i];
    sol[i] = -1;
  }
  build(v);
  for (int i = 0; i < q; i++) {
    node* now = root;
    for (auto &ch : v[i]) {
      int x = ch - 'a';
      assert(now->k[x]);
      now = now->k[x];
    }
    asking[ask[i]].push_back({now->id, i});
  }
  solve(0, root);
  for (int i = 0; i < q; i++) {
    cout << sol[i] << "\n";
  }
  return 0;
}