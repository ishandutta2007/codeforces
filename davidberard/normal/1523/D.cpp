#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200, K = 64;
char grid[N][K];
bool good[K];
bitset<N> who[K];
bitset<N> dp[1<<8], ep[1<<8];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> valids;
  for (int i=1; i<=n; ++i) {
    cin >> grid[i];
  }
  for (int i=0; i<m; ++i) {
    int have = 0;
    for (int j=1; j<=n; ++j) {
      if (grid[j][i] == '1') {
        who[i].set(j);
        ++have;
      }
    }
    if (have*2 >= n) {
      valids.push_back(i);
      good[i] = 1;
    }
  }
  assert(valids.size() <= 30);
  vector<int> members;
  for (int i=1; i<=n; ++i) {
    dp[0].set(i);
    ep[0].set(i);
  }
  pair<int, bitset<64>> best;
  best.first = 0;

  auto start = chrono::high_resolution_clock::now();
  for (int i=0; i<m; ++i) {
    //cerr << i << ": " << who[i].count() << endl;
  }

  // xxxx
  for (int zz=0; zz<200; ++zz) {
    if (chrono::high_resolution_clock::now() - start > 2.3s) {
      break;
    }
    int i = rng()%n + 1;
    members.clear();
    for (int j=0; j<m; ++j) {
      if (!good[j]) {
        continue;
      }
      if (grid[i][j] == '1') {
        members.push_back(j);
      }
    }
    int qa = min(8, (int) members.size());
    int qb = members.size()-qa;
    for (int j=1; j<(1<<qa); ++j) {
      int k = j&-j;
      int w = 31 - __builtin_clz(k);
      dp[j] = dp[j^k] & who[members[w]];
    }
    for (int j=1; j<(1<<qb); ++j) {
      int k = j&-j;
      int w = 31 - __builtin_clz(k);
      ep[j] = ep[j^k] & who[members[w+8]];
    }
    vector<int> avs;
    for (int a=0; a<(1<<qa); ++a) {
      avs.push_back(a);
    }
    shuffle(avs.begin(), avs.end(), rng);
    for (auto& a : avs) {
      for (int b=0; b<(1<<qa); ++b) {
        if (__builtin_popcount(a) + __builtin_popcount(b) <= best.first) {
          continue;
        }
        auto r = dp[a]&ep[b];
        if (r.count()*2 >= n) {
          best.first = __builtin_popcount(a) + __builtin_popcount(b);
          bitset<64> bst;
          for (int q=0; q<qa; ++q) {
            if (a&(1<<q)) {
              bst.set(members[q]);
            }
          }
          for (int q=0; q<qb; ++q) {
            if (b&(1<<q)) {
              bst.set(members[q+8]);
            }
          }
          best.second = bst;
        }
      }
    }
    /*
    for (int j=1; j<(1<<members.size()); ++j) {
      int k = j&-j;
      int w = 31-__builtin_clz(k);
      dp[j] = dp[j^k] & who[members[w]];
      if (dp[j].count()*2 >= n && __builtin_popcount(j) > best.first) {
        best.first = __builtin_popcount(j);
        bitset<64> bst;
        for (int q=0; q<members.size(); ++q) {
          if (j&(1<<q)) {
            bst.set(members[q]);
          }
        }
        best.second = bst;
      }
    }
    */
  }
  //cerr << "!! " << best.first << endl;
  for (int i=0; i<m; ++i) {
    cout << (best.second.test(i) ? 1 : 0);
  }
  cout << '\n';
  return 0;
}