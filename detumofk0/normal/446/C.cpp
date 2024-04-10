#include<bits/stdc++.h>

using namespace std;

const int N = 2;
const int mod = (int)1e9 + 9;

int mul(int x, int y) {
  return 1LL * x * y % mod;
}

void add(int &x, int y) {
  x += y;
  if(x >= mod) x -= mod;
}

struct Matrix{
  int a[N][N];

  Matrix(){
    memset(a, 0, sizeof a);
  };

  Matrix operator *(const Matrix &rhs) const{
    Matrix ans;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        for(int k = 0; k < N; ++k) {
          add(ans.a[i][j], mul(a[i][k], rhs.a[k][j]));
        }
      }
    }
    return ans;
  }

  Matrix operator +(const Matrix &rhs) const{
    Matrix ans;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        ans.a[i][j] = rhs.a[i][j];
        add(ans.a[i][j], a[i][j]);
      }
    }
    return ans;
  }

  void set(int i, int j, int v) {
    a[i][j] = v;
  }
}base, test;



const int MAXN = 300010;

Matrix basepow[MAXN];

struct TNode{
  int ans;
  Matrix first;
  int calc(int len) {
    int all = (first * basepow[len + 2]).a[0][0] - first.a[0][0] - first.a[0][1];
    all = (1LL * all + mod + mod) % mod;
    return all;
  }
};

Matrix cur[MAXN];
TNode tree[MAXN << 2];

void recalc(int x, int len) {
  tree[x].ans = tree[x].calc(len);
  if(len) {
    add(tree[x].ans, tree[x << 1].ans);
    add(tree[x].ans, tree[x << 1 | 1].ans);
  }
}
void push(int x, int l, int r) {
  int mid = (l + r) >> 1;
  tree[x << 1].first = tree[x << 1].first + tree[x].first;
  tree[x << 1 | 1].first = tree[x << 1 | 1].first + tree[x].first * basepow[mid - l];
  tree[x].first = Matrix();
}

void upd(int x, int l, int r, int u, int v) {
  recalc(x, r - l);
  if(l > v || r < u) return;
  if(l >= u && r <= v) {
  //  cout << l << " " << r << " " << tree[x].first.a[0][0] << " " << tree[x].first.a[0][1] << endl;
    tree[x].first = tree[x].first + cur[l - u];
//    cout << l << " " << r << " " << cur[l - u].a[0][0] << " " << cur[l - u].a[0][1] << endl;
    recalc(x, r - l);
    return;
  }
  int mid = (l + r) >> 1;
  push(x, l, r);
  upd(x << 1, l, mid, u, v);
  upd(x << 1 | 1, mid + 1, r, u, v);
  recalc(x, r - l);

  //cout << l << " " << r << " " << tree[x].
}

int get(int x, int l, int r, int u, int v) {
  recalc(x, r - l);
  if(l >= u && r <= v) {
    return tree[x].ans;
  }
  if(l > v || r < u) return 0;
  push(x, l, r);
  int ans = 0, mid = (l + r) >> 1;

  add(ans, get(x << 1, l, mid, u, v));
  add(ans, get(x << 1 | 1, mid + 1, r, u, v));
  return ans;
}

int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  base.set(0, 1, 1);
  base.set(1, 1, 1);
  base.set(1, 0, 1);

  basepow[0] = base;
  for(int i = 1; i < MAXN; ++i) basepow[i] = basepow[i - 1] * base;

  cur[0].set(0, 1, 1);
  for(int i = 1; i < MAXN; ++i) cur[i] = cur[i - 1] * base;

  int n, q;
  cin >> n >> q;

  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(i) add(a[i], a[i - 1]);
  }


  while(q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l; --r;
    if(t == 1) {
      upd(1, 0, n - 1, l, r);
    }
    else {
      int ans = get(1, 0, n - 1, l, r);
      add(ans, a[r]);
      if(l > 0) ans = (ans - a[l - 1] + mod) % mod;
      cout << ans << "\n";
    }

  //  cout << "bug: " << tree[1].ans << endl;
  }



  return 0;
}