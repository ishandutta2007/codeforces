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
#define bs 320
int n;
llong k;
int t[maxn];
llong a[maxn * 3];

void compress() {
  vector<llong> p(a, a + 1 + 3 * n);
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(), p.end()) - p.begin());
  rep(i, 3 * n + 1) {
    // clog << i << ' ' << a[i] << ' ';
    a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
    // clog << a[i] << endl;
  }
}

int cnt[3 * maxn];
llong anscnt = 0;
void addleft(int id) {
  anscnt += (llong)cnt[a[id + n]];
  cnt[a[id]]++;
}
void remleft(int id) {
  cnt[a[id]] --;
  anscnt -= (llong)cnt[a[id + n]];
}
void addright(int id) {
  anscnt += (llong)cnt[a[id + 2 * n]];
  cnt[a[id]]++;
}
void remright(int id) {
  cnt[a[id]] --;
  anscnt -= (llong)cnt[a[id + 2 * n]];
}

llong ans[maxn];
ii qr[maxn];
int qrp[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep1(i, n) {
    cin >> t[i]; t[i] = t[i] == 1 ? 1 : -1;
  }
  ++n;
  a[0] = 0;
  a[n] = k;
  a[2 * n] = -k;
  rep1(i, n - 1) {
    cin >> a[i];
    a[i] = a[i] * t[i] + a[i - 1];
    a[i + n] = a[i] + k;
    a[i + 2 * n] = a[i] - k;
  }
  compress();
  int q; cin >> q;
  rep(i, q) {
    cin >> qr[i].xx >> qr[i].yy;
    --qr[i].xx;
    qrp[i] = i;
  }
  sort(qrp, qrp + q, [](int u, int v) {
    int bu = qr[u].xx / bs, bv = qr[v].xx / bs;
    if (bu == bv) return qr[u].yy < qr[v].yy;
    return bu < bv;
  });
  
  int l = 0, r = 0; addright(0);
  rep(f, q) {
    int i = qrp[f];
    while (l > qr[i].xx) addleft(--l);
    while (r < qr[i].yy) addright(++r);
    while (l < qr[i].xx) remleft(l++);
    while (r > qr[i].yy) remright(r--);
    // rep(i, 10) clog << i << ':' << cnt[i] << ' ';
    // clog << endl;
    ans[i] = anscnt;
  }
  rep(i, q) cout << ans[i] << '\n';
  
  return 0;
}