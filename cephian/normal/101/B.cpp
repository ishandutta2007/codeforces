#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n,m;
const int N = 200005;
const ll MOD = 1e9+7;
set<int> loc;
map<int, int> compress;
ll dp[N];
ll dp_sum[N];
int q,r = 0;
vector<pii> go;
int a[N], b[N];

ll rp(int i) {
  if(i < 0) return 0;
  return dp_sum[i];
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  loc.insert(0);
  loc.insert(n);
  for(int i = 0; i < m; ++i) {
    pii p;
    cin >> p.second >> p.first;
    go.push_back(p);
    loc.insert(p.first);
    loc.insert(p.second);
  }
  for(set<int>::iterator i = loc.begin(); i != loc.end(); ++i) {
    compress[*i] = q++;
  }
  for(int i = 0; i < m; ++i) {
    go[i].first = compress[go[i].first];
    go[i].second = compress[go[i].second];
  }
  sort(go.begin(), go.end());
  dp[0] = 1;
  dp_sum[0] = 1;
  for(int i = 1; i < q; ++i) {
    ll &A = dp[i];
    A = 0;
    while(r < m && go[r].first == i) {
      A = (A+rp(i-1) - rp(go[r].second-1) + MOD)%MOD;
      ++r;
    }
    // cout << i  << " -> " << dp[i] << endl;
    dp_sum[i] = (rp(i-1)+A)%MOD;
  }
  cout << dp[q-1] << "\n";
  return 0;
}