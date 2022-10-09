
#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )


void flip(vector<string>& a) {
  for (auto& s: a) {
    int i = 0, f = len(s) - 1;
    while (i < f) swap(s[i++], s[f--]);
  }
}

vector<string> rotate(const vector<string>& a) {
  vector<string> ans(len(a), string(len(a[0]), ' '));
  rep(i, len(a)) rep(f, len(a[0])) {
    int u = f, v = len(a) - i - 1;
    ans[u][v] = a[i][f];
  }
  return ans;
}

int n;
vector<string> u, v;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  u.resize(n); v.resize(n);
  rep(i, n) cin >> u[i];
  rep(i, n) cin >> v[i];
  rep(_, 2) {
    rep(i, 4) {
      if (u == v) {
        cout << "Yes";
        return 0;
      }
      v = rotate(v);
    }
    flip(v);
  }

  cout << "No";
  return 0;
}