#include<bits/stdc++.h>

using namespace std;

const int maxn = 300005;

int n;
int a[maxn], b[maxn], pos[maxn];

#define mid ((l + r) >> 1)
#define lc (x << 1)
#define rc (x << 1 | 1)

int tree[maxn << 2];
int lazy[maxn << 3];

void rebuild(int x, int l, int r) {
  tree[x] = lazy[x] = 0;
  if(l == r) return;
  rebuild(lc, l, mid);
  rebuild(rc, mid + 1, r);
}

void push(int x) {
  tree[x] += lazy[x];
  lazy[lc] += lazy[x];
  lazy[rc] += lazy[x];
  lazy[x] = 0;
}

void update(int x, int l, int r, int u, int v, int val) {
  push(x);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    lazy[x] += val;
    return push(x);
  }
  update(lc, l, mid, u, v, val);
  update(rc, mid + 1, r, u, v, val);
  tree[x] = max(tree[lc], tree[rc]);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[--a[i]] = i;
  }

  for(int i = 0; i < n; ++i) {
    cin >> b[i]; --b[i];
  }

  int curans = n - 1;
  update(1, 0, n - 1, 0, pos[n - 1], 1);

  for(int i = 0; i < n; ++i) {
    while(tree[1] == 0) {
      update(1, 0, n - 1, 0, pos[--curans], 1);
    }
    cout << curans + 1 << " ";
    update(1, 0, n - 1, 0, b[i], -1);
  }

  return 0;
}