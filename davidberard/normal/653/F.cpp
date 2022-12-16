#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct suff_array {
  const int L; string s; int i, skip, lvl;
  vector<vi> P; vector<pair<pii,int>> M;
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

const int N = 500500;
int pmatch[N];
int ord[N];

vector<int> ind[N*2];
int v[N];

int calc(int here, int lo, int hi) {
  lo = min(lo, hi);
  auto it = lower_bound(ind[v[here]].begin(), ind[v[here]].end(), lo);
  auto jt = lower_bound(ind[v[here]].begin(), ind[v[here]].end(), hi);
  return jt-it;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s, t;
  cin >> n;
  cin >> s;

  for (int i=0; i<s.size(); ++i) {
    t += (s[i] == '(' ? 'a' : 'b');
  }
  suff_array sa(s);
  vector<int> sarr = sa.get_sarray();
  for (int i=0; i<s.size(); ++i) {
    ord[sarr[i]] = i;
  }
  for (int i=0; i<s.size()-1; ++i) {
    pmatch[ord[i+1]] = sa.lcp(ord[i], ord[i+1]);
  }
  int sum = N;
  ind[N].push_back(0);
  v[0] = N;
  for (int i=0; i<s.size(); ++i) {
    sum += (s[i] == '(' ? 1 : -1);
    ind[sum].push_back(i+1);
    v[i+1] = sum;
  }

  ll ans = 0;
  for (int i=0; i<s.size(); ++i) {
    int bck = v[i]-1;
    //cerr << " : BCK " << bck << endl;
    auto it = lower_bound(ind[bck].begin(), ind[bck].end(), i+1);
    int last_ind = 0;
    if (it == ind[bck].end()) {
      last_ind = s.size()+1;
    } else {
      last_ind = *it;
    }

    int add = calc(i, i+pmatch[i]+1, last_ind);
    //cerr << " " << i << ": +" << add << " [" << i+pmatch[i] << ", " << last_ind << ")" << endl;
    ans += add;
  }
  cout << ans << "\n";
  return 0;
}