#include <bits/stdc++.h>

using namespace std;

const int A = 100 + 7;
const int N = 200000 + 7;
int n, sol[N];

struct node {
  node* l;
  node* r;
  node() {
    l = r = 0;
  }
};

node* root[A];

void ins(node*& a, int l, int r, int i) {
  if (i < l || i > r) return;
  if (!a) a = new node;
  if (l == r) return;
  int m = (l + r) / 2;
  ins(a->l, l, m, i);
  ins(a->r, m + 1, r, i);
}

void put(node*& a, int l, int r, int val) {
  if (!a) return;
  if (l == r) {
    sol[l] = val;
    return;
  }
  int m = (l + r) / 2;
  put(a->l, l, m, val);
  put(a->r, m + 1, r, val);
}



void change(node*& a, node*& b, int l, int r, int f, int s) {
  if (!a) return;
  if (s < l || r < f) return;
  if (f <= l && r <= s) {
    if (!b) {
      swap(a, b);
      return;
    }
    int m = (l + r) / 2;
    change(a->l, b->l, l, m, f, s);
    change(a->r, b->r, m + 1, r, f, s);
    delete a;
    a = 0;
    return;
  }
  int m = (l + r) / 2;
  node* bl = b ? b->l : 0;
  node* br = b ? b->r : 0;
  change(a->l, bl, l, m, f, s);
  change(a->r, br, m + 1, r, f, s);
  if (!a->l && !a->r) {
    delete a;
    a = 0;
  }
  if ((bl || br) && !b) {
    b = new node;
  }
  if (b) {
    b->l = bl;
    b->r = br;
  }
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ins(root[x], 1, n, i);
  }
  int q;
  cin >> q;
  while (q--) {
    int f, s, x, y;
    cin >> f >> s >> x >> y;
    if (x == y) continue;
    change(root[x], root[y], 1, n, f, s);
  }
  for (int x = 1; x < A; x++) {
    put(root[x], 1, n, x);
  }
  for (int i = 1; i <= n; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
}