#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 8000
string s;
int ec[maxn], temp[maxn], cnt[maxn];
int suff[maxn], pos[maxn];
int d[maxn][2];
void gensa() {
  int n = len(s);
  rep(i, n) pos[i] = s[i], ec[i] = i;
  for (int i = 1; i < n; i <<= 1) {
    rep(f, n) {
      d[f][0] = i + f < n ? pos[i + f] + 1 : 0;
      d[f][1] = pos[f];
    }
    rep(t, 2) {
      memset(cnt, 0, sizeof(cnt));
      rep(f, n) cnt[d[temp[f] = ec[f]][t]]++;
      rep1(f, maxn - 1) cnt[f] += cnt[f - 1];
      for (int f = n; f--; )
        ec[--cnt[d[temp[f]][t]]] = temp[f];
    }
    pos[ec[0]] = 0;
    llong* ld = (llong*) d;
    rep1(f, n - 1)
      pos[ec[f]] = pos[ec[f - 1]] + (ld[ec[f]] != ld[ec[f - 1]]);
  }
  rep(i, n) suff[pos[i]] = i;
}

int lcp[maxn];
void genlcp() {
  int n = len(s), x = 0;
  for (int i = -1; ++ i < n; x && --x) {
    if (pos[i] == n - 1) { x= 0; continue; }
    for (int f = suff[pos[i] + 1]; i + x < n and f + x < n and s[i + x] == s[f + x]; ++x);
    lcp[pos[i]] = x;
  }
}

string a, b;
vector<ii> ans;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b;
  s = b + ' ' + a + char(' ' + 1);
  reverse(a.begin(), a.end());
  s += a + char(' ' + 2);
  gensa();
  genlcp();
  
  // clog << s << endl;
  // rep(i, len(s)) clog << setw(3) << suff[i] << "  '" << s.substr(suff[i]) << "'"<< endl;
  
  int i = 0;
  while (i < len(b)) {
    int u = pos[i];
    ii t(0, -1);
    int mlcp = lcp[u - 1];
    for (int f = u - 1; f >= 0; --f) {
      mlcp = min(mlcp, lcp[f]);
      if (suff[f] < len(b) || !isalpha(s[suff[f]])) continue;
      t = max(t, ii(mlcp, suff[f]));
      break;
    }
    mlcp = lcp[u];
    for (int f = u + 1; f < len(s); ++f) {
      mlcp = min(mlcp, lcp[f - 1]);
      if (suff[f] < len(b) || !isalpha(s[suff[f]])) continue;
      t = max(t, ii(mlcp, suff[f]));
      break;
    }
    // clog << i << ' ' << t.yy << ' ' << t.xx << endl;
    if (t.xx == 0) {
      cout << "-1";
      return 0;
    }
    if (t.yy < len(a) + len(b) + 2) {
      int p = t.yy - len(b);
      ans.push_back(ii(p, p + t.xx - 1));
    } else {
      int p = t.yy - len(a) - len(b) - 1;
      p = len(a) - p + 1;
      ans.push_back(ii(p, p - t.xx + 1));
    }
    i += t.xx;
  }
  
  cout << len(ans) << '\n';
  for (ii u: ans) cout << u.xx << ' ' << u.yy << '\n';
  
  return 0;
}