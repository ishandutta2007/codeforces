#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

template<class container>
vector<int> cal_lsp(const container& s) {
  vector<int> ans;
  ans.push_back(0);
  int cur_len = 0;
  while (len(ans) < len(s)) {
    if (s[len(ans)] == s[cur_len]) {
      ans.push_back(++cur_len);
    } else if (cur_len) {
      cur_len = ans[cur_len - 1];
    } else {
      ans.push_back(0);
    }
  }
  return ans;
}

#define maxn 201010
int n, m;
vector<int> lengths[maxn];
// int is_end[maxn] = {0};
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, m) {
      int u, v; cin >> u >> v; --u, --v;
      if (u > v) swap(u, v);
      int cur_len = v - u;
      lengths[u].push_back(cur_len);
      lengths[v].push_back(n - cur_len);
    }
    vector<int> s;
    rep(i, n) {
      s.push_back(0);
      sort(lengths[i].begin(), lengths[i].end());
      for (auto x: lengths[i]) s.push_back(x);
    }
    // for (auto i: s) clog << i << endl;

    int old_length_s = len(s);
    rep(i, old_length_s) s.push_back(s[i]);
    auto lsp = cal_lsp(s);
    // clog << endl;
    // for (auto i: lsp) clog << i << endl;
    for (int i = old_length_s; i < len(lsp) - 1; ++i) if (lsp[i] == old_length_s) {
      cout << "YES";
      return 0;
    }
    cout << "NO";

    return 0;
}