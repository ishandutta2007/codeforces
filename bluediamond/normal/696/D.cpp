#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = (ll) 1e18;

#define matrix vector<vector<ll>>

matrix gol(int n, int m) {
  matrix a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m, -INF);
  }
  return a;
}

matrix mult1(matrix a, matrix b) {
  int n = (int) b.size();
  matrix c = gol(1, n);
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < n; k++) {
      c[0][j] = max(c[0][j], a[0][k] + b[k][j]);
    }
  }
  return c;
}

matrix mult2(matrix a, matrix b) {
  int n = (int) b.size();
  matrix c = gol(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return c;
}

matrix pw(matrix a, ll k) {
  matrix sol = a;
  k--;
  while (k) {
    if (k & 1) {
      sol = mult2(sol, a);
    }
    a = mult2(a, a);
    k /= 2;
  }
  return sol;
}

struct trie {
  int id;
  int len;
  trie *kids[26];
  trie *go;
  ll profit;
  trie() {
    id = 0;
    len = 0;
    profit = 0;
    for (int x = 0; x < 26; x++) {
      kids[x] = 0;
    }
  }
};

trie *root = new trie;

const int N = 200 + 7;
vector<int> g[N];
int cnt;
int n;
ll k, profit[N];

void ins(string s, ll profit) {
  trie *cur = root;
  for (auto &c : s) {
    int x = c - 'a';
    if (!cur->kids[x]) {
      cur->kids[x] = new trie;
      cur->kids[x]->len = cur->len + 1;
      cur->kids[x]->id = ++n;
    }
    cur = cur->kids[x];
  }
  cur->profit += profit;
}

void build() {
  queue<trie*> q;
  q.push(root);
  root->go = root;
  while (!q.empty()) {
    trie *cur = q.front();
    int i = cur->id;
    cur->profit += cur->go->profit;
    profit[i] = cur->profit;
    for (int x = 0; x < 26; x++) {
      trie *aux = cur;
      while (aux != root && !aux->kids[x]) {
        aux = aux->go;
      }
      if (aux->kids[x]) {
        aux = aux->kids[x];
      }
      int j = aux->id;
      g[i].push_back(j);
    }
    q.pop();
    for (int x = 0; x < 26; x++) {
      if (!cur->kids[x]) {
        continue;
      }
      trie *now = cur->go;
      while (now != root && !now->kids[x]) {
        now = now->go;
      }
      if (cur->len == 0 || !now->kids[x]) {
        cur->kids[x]->go = root;
      } else {
        cur->kids[x]->go = now->kids[x];
      }
      q.push(cur->kids[x]);
    }
  }
  n++;
  matrix a = gol(1, n);
  a[0][0] = 0;
  matrix b = gol(n, n);
  for (int i = 0; i < n; i++) {
    for (auto &j : g[i]) {
      b[i][j] = profit[j];
    }
  }
  b = pw(b, k);
  a = mult1(a, b);
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[0][i]);
  }
  cout << mx << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> cnt >> k;
  for (int i = 1; i <= cnt; i++) {
    cin >> profit[i];
  }
  for (int i = 1; i <= cnt; i++) {
    string s;
    cin >> s;
    ins(s, profit[i]);
  }

  build();
}