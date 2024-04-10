#include <bits/stdc++.h>

using namespace std;
const int MAX = 5001;
  
vector<map<int, pair<int, int>>> tree; 
vector<int> have;
vector<long long> dp_down, cnt_down;
long long ans = 2e18;

void DFSDown(int node) {
  cnt_down[node] = have[node];
  for (auto p : tree[node]) {
    int cnt, vec; tie(cnt, vec) = p.second;
    DFSDown(vec);
    dp_down[node] += dp_down[vec] + cnt_down[vec] * cnt;
    cnt_down[node] += cnt_down[vec];
  }
}

// vector<string> reps;
// void BuildRep(int node, string rep) {
//   reps[node] = rep;
//   for (auto p : tree[node]) {
//     int cnt, vec; tie(cnt, vec) = p.second;
//     string nrep = rep;
//     for (int i = 0; i < cnt; ++i)
//       nrep += to_string(p.first);
//     BuildRep(vec, nrep);
//   }
// }

void DFSUp(int node, long long cnt_up, long long dp_up) {
  // cerr << "node: " << node << " rep: " << reps[node]
  //  << " dp_down: " << dp_down[node] << 
  //   " dp_up: " << dp_up << 
  //   " cnt_down: " << cnt_down[node] << " cnt_up: " << cnt_up << endl;

  ans = min(ans, dp_up + dp_down[node]);
  
  dp_up += dp_down[node];
  cnt_up += cnt_down[node];

  // cerr << "total: " << dp_up << " " << cnt_up << endl;
  
  for (auto p : tree[node]) {
    int cnt, vec; tie(cnt, vec) = p.second;
    DFSUp(vec, cnt_up - cnt_down[vec], 
      dp_up - dp_down[vec] - cnt_down[vec] * cnt
        + (cnt_up - cnt_down[vec]) * cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  vector<int> cnt(MAX + 1, 0);
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; cnt[x] += 1;
  }
  n = MAX + 1;

  auto is_prime = [&](int x) {
    for (int d = 2; d * d <= x; ++d)
      if (x % d == 0)
        return false;
    return true;
  };
  vector<int> primes;
  for (int x = 2; x < n; ++x)
    if (is_prime(x))
      primes.push_back(x);
  // cerr << primes.size() << " primes" << endl;
  reverse(primes.begin(), primes.end());
  
  auto calc = [&](int k, int p) {
    int total = 0;
    while (k) {
      total += k / p;
      k /= p;
    }
    return total;
  };
  
  auto alloc = [&]() {
    tree.emplace_back();
    have.push_back(0);
    return tree.size() - 1;
  };

  assert(alloc() == 0);
  for (int i = 0; i < n; ++i) {
    int at = 0;
    for (auto p : primes) {
      int exp = calc(i, p);
      while (exp > 0) {
        int son = -1;
        if (!tree[at].count(p)) {
          son = alloc();
          tree[at][p] = make_pair(exp, son);
          exp = 0;
        } else {
          int cnt; tie(cnt, son) = tree[at][p];
          if (cnt > exp) {
            // We split node
            int spl = alloc();
            tree[at][p] = make_pair(exp, spl);
            tree[spl][p] = make_pair(cnt - exp, son);
            son = spl;
            exp = 0;
          } else {
            exp -= cnt;
          }
        }
        at = son;
      }
    }
    have[at] += cnt[i];
  }

  // cerr << tree.size() << " trie nodes" << endl;

  cnt_down.assign(tree.size(), 0);
  dp_down.assign(tree.size(), 0);
  // reps.assign(tree.size(), "");

  // BuildRep(0, "");
  DFSDown(0);
  DFSUp(0, 0LL, 0LL);
  
  // for (auto x : dp_down)
  //   cerr << x << " ";
  // cerr << endl;

  cout << ans << endl;

  return 0;
}