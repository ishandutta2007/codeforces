#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 201010
#define maxlg 20
int n, m, q;
int a[maxn];
int p[maxn], permu_pos[maxn];
int nxt[maxlg][maxn];
int last[maxn];

int findnext(int pos, int length) {
  for (int i = 0; length > 0; ++i, length >>= 1) {
    if (length & 1) pos = nxt[i][pos];
  }
  return pos;
}

int min_cycle_length[maxn];
int sparse_tab[maxlg][maxn];
int l2[maxn];
void build_sparse_tab() {
  memcpy(sparse_tab[0], min_cycle_length, sizeof(min_cycle_length));
  l2[1] = 0;
  for (int i = 2; i < maxn; ++i) l2[i] = l2[i / 2] + 1;
  rep(i, maxlg - 1) {
    rep(f, m) 
      sparse_tab[i + 1][f] = min(sparse_tab[i][f], sparse_tab[i][f + (1 << i)]);
  }
}

int get_min(int l, int r) {
  int len2 = l2[r - l + 1];
  return min(sparse_tab[len2][l], sparse_tab[len2][r - (1 << len2) + 1]);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    rep(i, n) {
      cin >> p[i];
      permu_pos[p[i]] = i;
    }
    rep(i, m) cin >> a[i];

    rep1(i, n) last[i] = m;
    nxt[0][m] = m;
    for (int i = m; i--; ) {
      int next_elm = p[(permu_pos[a[i]] + 1) % n];
      nxt[0][i] = last[next_elm];
      last[a[i]] = i;
      // clog << i << ' ' << nxt[0][i] << endl;
    }

    rep(i, maxlg - 1) {
      rep(f, m + 1) nxt[i + 1][f] = nxt[i][nxt[i][f]];
    }
    // clog <<  endl << nxt[1][0] << ' ' << nxt[2][0] << endl << endl;

    rep(i, m) {
      min_cycle_length[i] = findnext(i, n - 1);
      // clog << i << ' ' << min_cycle_length[i] << endl;
    }

    build_sparse_tab();
    rep(i, q) {
      int l, r; cin >> l >> r;
      --l, --r;
      cout << (int)(get_min(l, r) <= r);
    }

    return 0;
}