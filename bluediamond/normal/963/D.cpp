#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
//#define int ll
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

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

string s;

struct node {
  node* k[26];
  node* to;
  node* pasa;
  int ind;
  int cnt;
  node() {
    ind = 0;
    for (int j = 0; j < 26; j++) {
      k[j] = 0;
    }
    cnt = 0;
    to = 0;
    pasa = 0;
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

vector<int> ap[N];

void build(vector<string> v) {
  int y = (int) v.size();
  int pz = 0;
  for (auto &s : v) {
    node* now = root;
    for (auto &ch : s) {
      int x = ch - 'a';
      if (!now->k[x]) {
        now->k[x] = new node;
      }
      now = now->k[x];
    }
    now->ind = ++pz;
  }
  bfs();
  root->to = root;
  root->pasa = root;
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
        if (now->k[j]->to->ind) {
          now->k[j]->pasa = now->k[j]->to;
        } else {
          now->k[j]->pasa = now->k[j]->to->pasa;
        }
      }
    }
  }
  node* state = root;
  int ki = 0;
  for (auto &ch : s) {
    ki++;
    int x = ch - 'a';
    while (state != root && !state->k[x]) {
      state = state->to;
    }
    if (state->k[x]) {
      state = state->k[x];
    }
    node* now = state;
    while (now != root) {
      if (now->ind) {
        ap[now->ind].push_back(ki);
      }
      now = now->pasa;
    }
  }
}

signed realMain() {
  cin >> s;
  int q;
  cin >> q;
  vector<pair<int, string>> que(q);
  vector<string> v;
  for (auto &x : que) {
    cin >> x.first >> x.second;
    v.push_back(x.second);
  }
  build(v);
  for (int i = 1; i <= q; i++) {
    int need = que[i - 1].first;
    auto p = ap[i];
    if (need > (int) p.size()) {
      cout << "-1\n";
      continue;
    }
    int best = (int) 1e9;
    for (int j = 0; j + need - 1 < (int) p.size(); j++) {
      best = min(best, p[j + need - 1] - p[j]);
    }
    best += (int) que[i - 1].second.size();
    cout << best << "\n";
  }
  return 0;
}