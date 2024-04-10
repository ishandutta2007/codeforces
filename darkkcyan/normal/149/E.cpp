#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 201010
#define maxlg 20
int l2[maxn];

struct sa {
  string s;
  sa() { }
  void build() {
    gensa();
    genlcp();
    buildsp();
    // clog << s << endl;
    // rep(i, len(s)) {
    //   clog << setw(3) << i << setw(3) << suff[i] << setw(3) << setw(3) << lcp[i] << " '" << s.substr(suff[i]) << "'" << endl;
    // }
  }
  int suff[maxn], pos[maxn];
  int temp[maxn], cnt[maxn];
  int d[maxn][2];
  void gensa() {
    int n = len(s);
    rep(i, n) suff[i] = i, pos[i] = s[i];
    for (int i = 1; i <= n; i <<= 1) {
      rep(f, n) {
        d[f][0] = f + i < n ? pos[f + i] + 1 : 0;
        d[f][1] = pos[f];
      }
      // rep(f, n) clog << suff[f] << ' ' << d[suff[f]][1] << ' ' << d[suff[f]][0] << endl;
      // clog << endl;
      rep(t, 2) {
        memset(cnt, 0, sizeof(cnt));
        rep(f, n) cnt[d[temp[f] = suff[f]][t]] ++;
        rep1(f, maxn - 1) cnt[f] += cnt[f - 1];
        for (int f = n; f--; )
          suff[--cnt[d[temp[f]][t]]] = temp[f];
      }
      pos[suff[0]] = 0;
      llong * ld = (llong*) d;
      rep1(f, n - 1) {
        pos[suff[f]] = pos[suff[f - 1]] + (ld[suff[f]] != ld[suff[f - 1]]);
        // clog << f << ' ' << f - 1 << ' ' << ld[f] << ' ' << ld[f - 1] << endl;
      }
    }
  }
  
  int lcp[maxn];
  void genlcp() {
    int x = 0;
    for (int i = -1; ++ i < len(s); x && --x) {
      if (pos[i] == len(s) - 1) { lcp[pos[i]] = x = 0 ; continue; }
      for (int f = suff[pos[i] + 1]; i + x < len(s) and f + x < len(s) and s[i + x] == s[f + x]; ++x);
      lcp[pos[i]] = x;
    }
  }
  
  int sp[maxlg][maxn];
  void buildsp() {
    memcpy(sp[0], lcp, sizeof(lcp));
    for (int i = 1; (1 << i) <= len(s); ++i) {
      for (int f = 0; f + (1 << i) <= len(s); ++f)
        sp[i][f] = min(sp[i - 1][f], sp[i - 1][f + (1 << (i - 1))]);
    }
  }
  
  int getlcp(int u, int v) {
    if (u == v) return len(s) - u;
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);
    --v;
    int lg = l2[v - u + 1];
    return min(sp[lg][u], sp[lg][v - (1 << lg) + 1]);
  }
};

sa tsa;
int n;
string s;
#define maxm 111
#define maxlen 1010
string a[maxm];
int pos[maxm];
int minpos[2][maxm][maxlen];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  l2[1] = 0;
  for (int i = 1; ++i < maxn; ) l2[i] = l2[i >> 1] + 1;
  cin >> s >> n;
  rep(i, n) cin >> a[i];
  rep(t, 2) {
    tsa.s = s + char(' ' + 1);
    reverse(s.begin(), s.end());
    rep(i, n) {
      pos[i] = len(tsa.s);
      tsa.s += a[i] + ' ';
      reverse(a[i].begin(), a[i].end());
      rep(f, maxlen) minpos[t][i][f] = INT_MAX;
    }
    tsa.build();
    // clog << tsa.s << endl;
    rep(i, len(s)) {
      rep(f, n) {
        int ml = tsa.getlcp(i, pos[f]);
        minpos[t][f][ml] = min(minpos[t][f][ml], i);
        // clog << "lcp " << i << ' ' <<f << ' ' << pos[f] << ' ' << ml << endl;
      }
    }
    rep(i, n) {
      for (int f = maxlen - 1; f --; ) {
        minpos[t][i][f] = min(minpos[t][i][f], minpos[t][i][f + 1]);
        // clog << i << ' ' << f << ' ' << minpos[t][i][f] << endl;
      }
    }
  }
  
  int ans = 0;
  rep(i, n) {
    if (len(a[i]) < 2) continue;
    if (minpos[0][i][len(a[i])] != INT_MAX) {
      ++ans;
      // clog << "found all len" << i << endl;
      continue;
    }
    rep1(f, len(a[i]) - 1) {
      int u = minpos[0][i][f];
      int v = minpos[1][i][len(a[i]) - f];
      if (u == INT_MAX or v == INT_MAX) continue;
      v = len(s) - v - 1;
      // clog << i << ' ' << f << ' ' << u << ' ' << v << endl;
      if (v - u + 1 >= len(a[i])) {
        // clog << "found " << i << endl;
        ++ans;
        break;
      }
    }
  }
  cout << ans;
  
  return 0;
}