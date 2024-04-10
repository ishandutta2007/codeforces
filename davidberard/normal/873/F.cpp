#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef pair<int, int> pii;

struct suff_array {
  int L; string s; int i, skip, lvl;
  vector<vi> P; vector<pair<pii,int>> M;
  suff_array() {}
  suff_array(const string &s) : L(s.size()), s(s), P(1, vi(L, 0)), M(L) {
    for (i = 0; i < L-(L==1); i++) P[0][i] = int(s[i]);
    for (skip = 1, lvl = 1; skip < L; skip *= 2, lvl++) {
      P.push_back(vi(L, 0));
      for (int i = 0; i < L; i++)
        M[i] = {{P[lvl-1][i], i+skip<L ? P[lvl-1][i + skip] : -1000}, i};
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++)
        P[lvl][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ?
            P[lvl][M[i-1].second] : i; } }
  const vi& get_sarray() { return P.back(); }
  //returns len of longest common prefix of s[i...L-1] and s[j...L-1], O(lg L)
  int lcp(int i, int j) {
    int len = 0; if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--)
      if (P[k][i] == P[k][j]) { i += 1 << k; j += 1 << k; len += 1 << k; }
    return len; } }; //! code adapted from the Stanford Team Notebook

const int N = 200200, LG = 18;
struct RMQ {
  int a[LG][N];
  RMQ() {}
  int& operator[] (const int& i) {
    return a[0][i];
  }
  void build() {
    for (int l=0; l<LG-1; ++l) {
      for (int i=0; i+(1<<l)<N; ++i) {
        a[l+1][i] = min(a[l][i], a[l][i+(1<<l)]);
      }
    }
  }
  int query(int l, int r) {
    --r;
    if (r-l == 0) {
      return 1e9;
    }
    int h = 31 - __builtin_clz(r-l);
    return min(a[h][l], a[h][r-(1<<h)]);
  }
};

RMQ rmq;
int ind_of[N]; // maps sorted index to original index
int len[N];
char allowed[N];
int n, m;

ll ans=0;

void dfs(int l, int r, int plen) {
  if (r-l == 0) {
    return;
  }
  if (r-l == 1) {
    ans = max(ans, (ll) len[l]);
    return;
  }
  ans = max(ans, plen*((ll) r - l));
  int lo = l+1, hi = r;
  while (lo<hi) {
    int mid = (lo+hi+1)/2;
    if (rmq.query(l, mid) > plen) {
      lo = mid;
    } else {
      hi = mid-1;
    }
  }
  dfs(l, lo, rmq.query(l, lo));
  dfs(lo, r, plen);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  string s;
  cin >> s;
  cin >> allowed;
  reverse(s.begin(), s.end());
  reverse(allowed, allowed+n);

  {
    suff_array sa = suff_array(s);
    const vi& sar = sa.get_sarray();
    for (int i=0; i<sar.size(); ++i) {
      ind_of[sar[i]] = i;
    }
    int skip = 0;
    for (int i=0; i<n-skip; ++i) {
      while(i+skip<n && allowed[ind_of[i+skip]] == '1') {
        ++skip;
      }
      if (i+skip<n) {
        ind_of[i] = ind_of[i+skip];
      }
    }
    m = n-skip;

    for (int i=0; i<m-1; ++i) {
      rmq[i] = sa.lcp(ind_of[i], ind_of[i+1]);
      len[i] = n-ind_of[i];
    }
    len[m-1] = n-ind_of[m-1];
    rmq.build();
  }

  dfs(0, m, 0);
  cout << ans << "\n";

  return 0;
}