#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

struct Node {
  Node* c[2];
  int full;
  Node() {
    c[0] = c[1] = NULL;
    full = 0;
  }
};

Node *root;
const int h = 524288;

void add(int x) {
  Node *cur = root;
  for (int i = h; i; i >>= 1) {
    int d = (x & i) ? 1 : 0;
    if (cur->c[d] == NULL)
      cur->c[d] = new Node();
    cur = cur->c[d];
  }
}

int dfs(Node *r, int i) {
  if (r == NULL) return 0;
  if (i == 0) return r->full = 1;
  return r->full = dfs(r->c[0], i>>1) + dfs(r->c[1], i>>1);
}

void query(int x) {
  Node *cur = root;
  int ans = 0;
  for (int i = h; i; i >>= 1) {
    if (cur == NULL) break;
    int d = (x & i) ? 1 : 0;
    if (cur->c[d] == NULL) break;
    else if (cur->c[d]->full < i) {
      cur = cur->c[d];
    }
    else {
      cur = cur->c[d^1];
      ans ^= i;
    }
  }
  printf("%d\n", ans);
}

int n, m;
int main() {
  root = new Node();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    add(x);
  }
  dfs(root, h);
  int s = 0;
  while (m--) {
    int x;
    scanf("%d", &x);
    s ^= x;
    query(s);
  }
  return 0;
}