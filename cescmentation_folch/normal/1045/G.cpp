#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
      rb_tree_tag,tree_order_statistics_node_update>;
// Use like a map: put something instead of null_type


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;


struct cosa {
  int x,r, q;
  int ind;
};

bool comp(cosa a, cosa b) {
  return a.r < b.r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin >> n >> k;
  vector<cosa> V(n);
  vi S(n);
  for (int i = 0; i < n; ++i) {
    cin >> V[i].x >> V[i].r >> V[i].q;
    V[i].ind = i;
    S[i] = V[i].q;
  }
  sort(S.begin(), S.end());
  int sz = unique(S.begin(), S.end()) - S.begin();
  map<int,int> M;
  for (int i = 0; i < sz; ++i) M[S[i]] = i;
  vector<ordered_set<pi> > H(sz);
  for (int i = 0; i < n; ++i) {
    H[M[V[i].q]].insert(pi(V[i].x, V[i].ind));
  }
  sort(V.begin(), V.end(), comp);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    H[M[V[i].q]].erase(pi(V[i].x, V[i].ind));
    for (int j = max(0, M[V[i].q]-k); j < min(sz,M[V[i].q]+k+1); ++j) {
      if (abs(S[j] - V[i].q) > k) continue;
      res += H[j].order_of_key(pi(V[i].x + V[i].r + 1, -1)) - H[j].order_of_key(pi(V[i].x - V[i].r, -1));
    }
  }
  cout << res << '\n';
}