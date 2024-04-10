#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n;)
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define ii pair<int, int>

#define maxn 101010
int n;
vector<int> gr[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n - 1) {
    int u; cin >> u;
    gr[u].push_back(i + 1);
  }
  bool ok = 1;
  rep1(i, n) {
    if (len(gr[i]) == 0) continue;
    int cnt = 0;
    for (auto v: gr[i]) cnt += len(gr[v]) == 0;
    if (cnt < 3) ok = false;
  }
  cout << (ok ? "YES" : "NO");

  return 0;
}