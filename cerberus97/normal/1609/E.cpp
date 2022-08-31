/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct node {
  vector<int> cnt;
  int c01 = 0, c12 = 0, c012 = 0;
  node() {
    cnt.resize(3, 0);
  }
  void set_val(int c) {
    cnt[0] = cnt[1] = cnt[2] = 0;
    cnt[c] = 1;
    c01 = c12 = c012 = 0;
  }
};

node tree[4 * N];

void update(int i, int l, int r, int p, int c);
void merge(node& n, node& l, node& r);

int main() {
  fast_cin();
  int n, q; string s;
  cin >> n >> q >> s;
  for (int i = 0; i < n; ++i) {
    update(1, 0, n - 1, i, (s[i] - 'a'));
  }
  while (q--) {
    int i; char c;
    cin >> i >> c;
    update(1, 0, n - 1, i - 1, (c - 'a'));
    cout << tree[1].c012 << '\n';
  }
}

void update(int i, int l, int r, int p, int c) {
  if (p < l or p > r) {
    return;
  } else if (l == r) {
    tree[i].set_val(c);
  } else {
    int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
    update(lc, l, mid, p, c);
    update(rc, mid + 1, r, p, c);
    merge(tree[i], tree[lc], tree[rc]);
  }
}

void merge(node& n, node& l, node& r) {
  for (int i = 0; i < 3; ++i) {
    n.cnt[i] = l.cnt[i] + r.cnt[i];
  }
  n.c01 = min(l.c01 + r.cnt[1], l.cnt[0] + r.c01);
  n.c12 = min(l.c12 + r.cnt[2], l.cnt[1] + r.c12);
  n.c012 = min({l.c012 + r.cnt[2], l.c01 + r.c12, l.cnt[0] + r.c012});
}