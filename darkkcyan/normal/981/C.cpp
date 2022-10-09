#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define xx first
#define yy second

#define maxn 101010
int n;
int cnt[maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> c0, cn;
  cin >> n;
  rep(i, n - 1) {
    int u, v; cin >> u >> v;
    ++cnt[u];
    ++cnt[v];
  }

  rep1(i, n) {
    if (cnt[i] == 1) c0.push_back(i);
    if (cnt[i] > 2) cn.push_back(i);
  }
  if (len(cn) > 1) {
    cout << "No";
    return 0;
  }

  cout << "Yes\n";
  if (len(cn) == 1) {
    cout << len(c0) << '\n';
    for (auto i: c0) cout << i << ' ' << cn[0] << '\n';
    return 0;
  }

  cout << "1\n";
  cout << c0[0] << ' ' << c0[1];

  return 0;
}