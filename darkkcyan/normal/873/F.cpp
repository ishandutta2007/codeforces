#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int n;
string s, b;

#define maxn 201010
#define maxlg 19
int suff[maxn], pos[maxn];
int temp[maxn], cnt[maxn];
int d[maxn][2];
void gensa() {
  rep(i, n) suff[i] = i, pos[i] = s[i];
  for (int i = 1; i <= n; i <<= 1) {
    rep(f, n) {
      d[f][1] = pos[f];
      d[f][0] = i + f < n ? pos[f + i] + 1 : 0;
    }
    rep(t, 2) {
      memset(cnt, 0, sizeof(cnt));
      rep(f, n) cnt[d[temp[f] = suff[f]][t]]++;
      rep1(f, maxn - 1) cnt[f] += cnt[f - 1];
      for (int f = n; f--; )
        suff[--cnt[d[temp[f]][t]]] = temp[f];
    }
    llong* ld = (llong*) d;
    pos[suff[0]] = 0;
    rep1(f, n - 1)
      pos[suff[f]] = pos[suff[f - 1]] + (ld[suff[f]] != ld[suff[f - 1]]);
  }
}

int lcp[maxn];
void genlcp() {
  int x = 0;
  for (int i = 0; i < n; ++i, x && --x) {
    if (pos[i] == n - 1) {x = 0; continue; }
    for (int f = suff[pos[i] + 1]; i + x < n and f + x < n and s[i + x] == s[f + x]; ++x);
    lcp[pos[i]] = x;
  }
}

int l2[maxn];
int sp[maxlg][maxn];
void buildsp() {
  l2[1] = 0;
  for (int i = 1; ++i < maxn; ) l2[i] = l2[i / 2] + 1;
  rep(i, n) sp[0][i] = i;
  for (int i = 1; (1 << i) <= n; ++i) {
    for (int f = 0; f + (1 << i) <= n; ++f) {
      int u = sp[i - 1][f], v = sp[i - 1][f + (1 << (i - 1))];
      if (lcp[u] > lcp[v]) sp[i][f] = v;
      else sp[i][f] = u;
    }
  }
}

int qr(int l, int r) {
  int lg = l2[r - l + 1];
  int u = sp[lg][l], v = sp[lg][r - (1 << lg) + 1];
  return lcp[u] > lcp[v] ? v : u;
}

llong ans = 0;
int sum[maxn];
llong gets(int l, int r) { return sum[r] - (l ? sum[l - 1] : 0); }
void process(int l, int r) {
  if (l == r) ans = max(ans, gets(l, r) * (n - suff[l]));
  if (l >= r) return;
  int mp = qr(l, r - 1);
  // clog << l << ' '  << r << ' ' << mp << ' ' << lcp[mp] * gets(l, r) << endl;
  ans = max(ans, (llong) lcp[mp] * gets(l, r));
  process(l, mp);
  process(mp + 1, r);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> s >> b;
  reverse(s.begin(), s.end());
  reverse(b.begin(), b.end());
  gensa();
  genlcp();
  buildsp();
  rep(i, n) sum[i] = (b[suff[i]] == '0') + (i ? sum[i - 1] : 0);

  // clog << s << endl;
  // rep(i, n)
  //   clog << setw(3) << i << setw(3) << suff[i] << setw(3) <<  lcp[i] << ' ' << b[suff[i]] << ' ' << s.substr(suff[i]) << endl;

  process(0, n - 1);
  cout << ans;
  
  return 0;
}