#include <bits/stdc++.h>

using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i =-1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )
#define sgn(x) ((x) < 0 ? -1 : (x) > 0)

#define maxn 101010
int n;
int a[maxn];

int minit[maxn * 4], mit[maxn * 4], fp[maxn * 4];

void comb(int i) {
  int l = i << 1, r = l | 1;
  mit[i] = mit[l] + mit[r];
  minit[i] = min(minit[l], minit[r]);
  fp[i] = 1e9;
  if (minit[i] == minit[l]) fp[i] = fp[l];
  if (minit[i] == minit[r]) fp[i] = min(fp[i], fp[r]);
}

void build(int i, int l, int r) {
  if (l == r) {
    mit[i] = 1;
    minit[i] = a[l];
    fp[i] = l;
  }
  if (l >= r) return;
  int mid = (l + r) / 2;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  comb(i);
}

void unmark(int i, int l, int r, int p) {
  if (l > r or l > p or r < p) return;
  if (l == r) {
    minit[i] = 2e9;
    mit[i] = 0;
    return;
  }
  int mid = (l + r) / 2;
  unmark(i << 1, l, mid, p);
  unmark(i << 1 | 1, mid + 1, r, p);
  comb(i);
}

ii getmin(int i, int l, int r, int u, int v) {
  if (l > r or l > v or u > r) return ii(1e9, 0);
  if (u <= l and r <= v) return ii(minit[i], fp[i]);
  int mid = (l + r) / 2;
  ii x = getmin(i << 1, l, mid, u, v);
  ii y = getmin(i << 1 | 1, mid + 1, r, u, v);
  if (x.xx > y.xx) return y;
  return x;
}

int getcnt(int i, int l, int r, int u, int v) {
  if (l > r or l > v or u > r) return 0;
  if (u <= l and r <= v) return mit[i];
  int mid = (l + r) / 2;
  return getcnt(i << 1, l, mid, u, v) + getcnt(i << 1 | 1, mid + 1, r, u, v);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n) cin >> a[i];
  build(1, 0, n - 1);

  int curpos = -1;
  llong ans = 0;
  rep(i, n) {
    ii u = getmin(1, 0, n - 1, curpos + 1, n - 1);
    ii v = getmin(1, 0, n - 1, 0, curpos - 1);

    if (u.xx > v.xx) u = v;
    int plus;
    if (u.yy > curpos) {
      plus = getcnt(1, 0, n - 1, curpos + 1, u.yy);
    } else {
      plus = getcnt(1, 0, n - 1, curpos + 1, n - 1);
      plus += getcnt(1, 0, n- 1, 0, u.yy);
    }

    unmark(1, 0, n - 1, u.yy);
    curpos = u.yy;
    
    ans += plus;
    //clog << i << ' ' << u.xx << ' ' << u.yy << ' ' << plus << endl;
  }
  cout << ans;

  return 0;
}