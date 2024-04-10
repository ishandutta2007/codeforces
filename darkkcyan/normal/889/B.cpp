#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
int n;
string s[maxn];
bool rem[maxn] = {0};

void no() {
  cout << "NO";
  exit(0);
}

set<int> buc[26];

void join(int u, int v, char c) {
  int pu = s[u].find(c), pv = s[v].find(c);
  if (pu < pv) swap(u, v), swap(pu, pv);
  for (int i = pu, f = pv; i >= 0 and f >= 0; --i, --f) 
    if (s[u][i] != s[v][f]) no();
  for (int i = pu, f = pv; i < len(s[u]) and f < len(s[v]); ++i, ++f)
    if (s[u][i] != s[v][f]) no();
  int p = len(s[u]) - pu + pv;
  if (len(s[v]) >= p) s[u] += s[v].substr(p);
  if (len(s[u]) > 26) no();
  rem[v] = 1;
  for (auto c: s[v]) {
    buc[c - 'a'].erase(v);
    buc[c - 'a'].insert(u);
  }
}

int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  rep(i, n) {
    cin >> s[i];
    int cnt[26] = {0};
    for (auto c: s[i]) if (++cnt[c - 'a'] >= 2) no();
    for (auto c: s[i]) buc[c - 'a'].insert(i);
  }
  rep(i, 26) {
    while (len(buc[i]) > 1)
      join(*buc[i].begin(), *buc[i].rbegin(), i + 'a');
  }
  vector<int> t;
  rep(i, n) if (!rem[i]) t.push_back(i);
  sort(t.begin(), t.end(), [](int u, int v) { return s[u] < s[v]; });
  int cnt[26] = {0};
  for (auto i: t) for (auto c: s[i]) if (++cnt[c - 'a'] >= 2) no();
  for (auto i: t) cout << s[i];

  return 0;
}