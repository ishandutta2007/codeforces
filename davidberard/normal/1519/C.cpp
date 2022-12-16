#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
const int RT = 420;
vector<ll> strengths[N];
vector<ll> pre[N];
int u[N];
ll s[N];
ll ans[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    for (int i=0; i<=n+1; ++i) {
      strengths[i].clear();
      pre[i].clear();
      ans[i] = 0;
    }
    for (int i=1; i<=n; ++i) {
      cin >> u[i];
    }
    for (int i=1; i<=n; ++i) {
      cin >> s[i];
      strengths[u[i]].push_back(s[i]);
    }
    for (int i=1; i<=n; ++i) {
      sort(strengths[i].rbegin(), strengths[i].rend());
      pre[i].resize(strengths[i].size()+1);
      pre[i][0] = 0;
      for (int j=0; j<strengths[i].size(); ++j) {
        pre[i][j+1] = pre[i][j] + strengths[i][j];
      }
    }

    for (int i=1; i<=n; ++i) {
      int z = strengths[i].size();
      for (int k=1; k<=strengths[i].size(); ++k) {
        ans[k] += pre[i][(z/k)*k];
      }
    }
    for (int k=1; k<=n; ++k) {
      cout << ans[k] << " ";
    }
    cout << "\n";


  }
  return 0;
}