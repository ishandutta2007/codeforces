#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
#define maxbit 30
int n, m;
int ql[maxn], qr[maxn], qq[maxn];

int it[maxn * 4] = {0};
int lz[maxn * 4] = {0};

void propagate(int i, int l, int r) {
  if (l > r or !lz[i]) return;
  it[i] |= lz[i];
  if (l < r) lz[i << 1] |= lz[i], lz[i << 1 | 1] |= lz[i];
  lz[i] = 0;
}

void upd(int u, int v, int mask, int i = 1, int l = 0, int r = n - 1) {
  propagate(i, l, r);
  // clog << u << ' ' << v << ' ' << bit << ' ' << i << ' ' << l << ' ' << r << endl;
  if (l > r or l > v or u > r) return;
  if (u <= l and r <= v) {
    lz[i] |= mask;
    propagate(i, l, r);
    // clog << it[i] << endl;
    return ;
  }
  int mid = (l + r) / 2;
  upd(u, v, mask, i << 1, l, mid);
  upd(u, v, mask, i << 1 | 1, mid + 1, r);
  it[i] = it[i << 1] & it[i << 1 | 1];
}

int get(int u, int v, int i = 1, int l = 0, int r = n - 1) {
  propagate(i, l, r);
  if (l > r or l > v or u > r) return (1 << maxbit) - 1;
  if (u <= l and r <= v) return it[i];
  int mid = (l + r) / 2;
  return get(u, v, i << 1, l, mid) & get(u, v, i << 1 | 1, mid + 1, r);
}

void print(int i = 1, int l = 0, int r = n - 1) {
  propagate(i, l, r);
  if (l == r) cout << it[i] << ' ';
  if (l >= r) return;
  int mid = (l + r) / 2;
  print(i << 1, l, mid);
  print(i << 1 | 1, mid + 1, r);
}

vector<int> buc[2];
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, m) {
    cin >> ql[i] >> qr[i] >> qq[i], --ql[i], --qr[i];
    upd(ql[i], qr[i], qq[i]);
  }
  
  rep(i, m) {
    if (get(ql[i], qr[i]) != qq[i]) {
      cout << "NO";
      return 0;
    }
  }
  
  cout << "YES" << '\n';
  print();
  return 0;
}