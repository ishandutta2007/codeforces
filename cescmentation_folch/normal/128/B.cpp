#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef int ttype;
struct TR { // edge
  int t0, t1; // text on the edge: T[t0..t1]
  int node;   // node that the edge is pointing
  TR() {}
  TR(int _t0, int _t1, int _node) : t0(_t0), t1(_t1), node(_node) {}
  ll k;
};
struct ND { // node
  int link;             // suffix link, internally used by suffixtree()
  map<ttype, TR> edges; // edges to the children
  int dollars;          // generalized: unique dollars in that subtree
  ll tius;
};
const int MAXN = 400050; // maximum text length
int N, M;             // text length, number of nodes
ttype T[MAXN + 17];   // text
ND tree[2*MAXN + 17]; // suffix tree

bool test_and_split(int s, int k, int p, ttype t, int& r) {
  r = s;
  if (p < k) return tree[s].edges.count(t) != 0;
  TR tr = tree[s].edges[T[k]];
  int sp = tr.node, kp = tr.t0, pp = tr.t1;
  if (t == T[kp + p - k + 1]) return true;
  r = M++;
  tree[s].edges[T[kp]] = TR(kp, kp + p - k, r);
  tree[r].edges[T[kp + p - k + 1]] = TR(kp + p - k + 1, pp, sp);
  return false;
}

void canonize(int s, int k, int p, int& ss, int& kk){
  if (p < k) { ss = s; kk = k; return; }
  TR tr = tree[s].edges[T[k]];
  int sp = tr.node, kp = tr.t0, pp = tr.t1;
  while (pp - kp <= p - k) {
    k += pp - kp + 1; s = sp;
    if (k <= p) {
      tr = tree[s].edges[T[k]];
      sp = tr.node; kp = tr.t0; pp = tr.t1;
    }
  }
  ss = s; kk = k;
}

void update(int& s, int& k, int i) {
  int oldr = 0, r;
  while (not test_and_split(s, k, i - 1, T[i], r)) {
    tree[r].edges[T[i]] = TR(i, MAXN, M++);
    if (oldr != 0) tree[oldr].link = r;
    oldr = r;
    canonize(tree[s].link, k, i - 1, s, k);
  }
  if (oldr != 0) tree[oldr].link = s;
}

int sts, stk;
void init() {
  for (int i = 0; i < M; ++i) {
    tree[i].link = 0; tree[i].edges.clear(); }
  M = 2; N = 0; tree[0].link = 1; sts = stk = 0;
}
void add(int c) {
  T[N] = c;
  tree[1].edges[T[N]] = TR(N, N, 0);
  update(sts, stk, N);
  canonize(sts, stk, N++, sts, stk);
}

ll dfs(int x) {
  if (tree[x].edges.size() == 0) tree[x].tius = 1;
  else tree[x].tius = 0;
  ll k = 0;
  for (auto& it : tree[x].edges) {
    it.second.k = dfs(it.second.node);
    it.second.k += tree[it.second.node].tius*ll(min(N-2, it.second.t1) - it.second.t0 + 1);
    tree[x].tius += tree[it.second.node].tius;
    k += it.second.k;
  }
  return k;
}

void find(int x, ll k) {
  for (auto& it : tree[x].edges) {
    if (it.second.k >= k) {
      ll tt = (min(N-2, it.second.t1) - it.second.t0 + 1);
      ll ee = tree[it.second.node].tius;
      ll eps = (k + ee -1)/ee;
      for (int i = 0; i < min(tt, eps); ++i) cout << (char)T[it.second.t0 + i];
      if (tt >= eps) return;
      k -= tt*ee;
      find(it.second.node, k);
      return;
    }
    k -= it.second.k;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a;
  int k;
  cin >> a >> k;
  ll tt = a.size();
  if (tt*(tt + 1)/2 < k) {
    cout << "No such line." << endl;
    return 0;
  }
  init();
  for (int i = 0; i < (int)a.size(); ++i) {
    add(a[i]);
  }
  add(-1);
  dfs(0);
  find(0, k);
  cout << endl;
}