#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

const int N = 1 << 19;

int dsu[N], sz[N];
int find(int i) {
  if(dsu[i] == -1) return i;
  return find(dsu[i]);
}

vector<pair<int, int>> edges[2*N];
int ans[N];

void solve(int i) {
  vector<int> undo;
  for(auto [a, b] : edges[i]) {
    if (a < 0) {
      ans[b] = sz[find(-a)] + 1;
      assert(edges[i].size() == 1);
    } else {
      a = find(a);
      b = find(b);
      if(a == b) continue;
      if(sz[a] > sz[b]) swap(a, b);
      dsu[a] = b;
      sz[b] += sz[a] + 1;
      undo.push_back(a);
    }
  }

  if(i < N) {
    solve(2*i);
    solve(2*i + 1);
  }

  reverse(begin(undo), end(undo));
  for(auto v : undo) {
    sz[dsu[v]] -= sz[v] + 1;
    dsu[v] = -1;
  }
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  memset(dsu, -1, sizeof dsu);

  int n, m, k;
  cin >> n >> m >> k;
  int day = 0;
  int qid = 0;
  vector<int> day_ends;
  vector<tuple<int, int, int, int>> adds;
  for(int i=0; i<m; i++) {
    int t;
    cin >> t;
    if(t == 1) {
      int a, b;
      cin >> a >> b;
      adds.emplace_back(i, day, a, b);
    } else if(t == 2) {
      int v;
      cin >> v;
      edges[i + N].emplace_back(-v, qid++);
    } else {
      day_ends.push_back(i);
      day++;
    }
  }
  day_ends.push_back(m);

  for(auto [i, d, a, b] : adds) {
    int to = day_ends[min(d + k, (int)day_ends.size()) - 1];
    for(int l=i+N, r=to+N+1; l<r; l/=2, r/=2) {
      if(l&1) edges[l++].emplace_back(a, b);
      if(r&1) edges[--r].emplace_back(a, b);
    }
  }

  solve(1);
  for(int i=0; i<qid; i++) {
    cout << ans[i] << nl;
  }

  return 0;
}