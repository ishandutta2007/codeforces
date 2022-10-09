#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 1111
int n;
int cnt[maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep(i, n - 1) {
    int u, v; 
    cin >> u >> v;
    if (v != n) {
      cout << "NO";
      return 0;
    }
    cnt[u]++;
  }

  vector<int> left;
  vector<ii> edges;
  rep1(i, n) {
    if (cnt[i] - len(left) > 1) {
      cout << "NO";
      return 0;
    }
    if (cnt[i] == 0) {
      left.push_back(i);
      continue;
    }
    int last = n;
    rep(f, cnt[i] - 1) {
      edges.push_back({last, left.back()});
      last = left.back();
      left.pop_back();
    }
    edges.push_back({last, i});
  }
  assert(len(edges) == n - 1);
  cout << "YES\n";
  for (auto i: edges) {
    cout << i.xx << ' ' << i.yy << '\n';
  }


  return 0;
}