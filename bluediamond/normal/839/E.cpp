#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 


bool home = true;
using namespace std;
typedef long long ll;
typedef long double ld;
#define int long long

const int N = 40;
int n;
ll vecs[N], k;
int best[1 << (N / 2)];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int is;
      cin >> is;
      vecs[i] += (1LL << j) * is;
    }
    vecs[i] |= (1LL << i);
  }
  int dim = n / 2;
  assert(dim <= N / 2);

  int sol = 0;

  for (int mask = 1; mask < (1 << dim); mask++) {
    bool is = true;
    int cnt = 0;
    for (int i = 0; i < dim; i++) {
      if (mask & (1 << i)) {
        cnt++;
        is &= ((vecs[i] & mask) == mask);
        best[mask] = max(best[mask], best[mask ^ (1 << i)]);
      }
    }
    best[mask] = (1 - is) * best[mask] + is * cnt;
    sol = max(sol, best[mask]);
  }
  
  vector<int> bits;
  for (int i = dim; i < n; i++) {
    bits.push_back(i);
  }
  for (int mask = 0; mask < (1 << (int)bits.size()); mask++) {
    ll rl_mask = 0;
    int cur = 0;
    for (int i = 0; i < (int)bits.size(); i++) {
      if (mask & (1 << i)) {
        rl_mask += (1LL << bits[i]);
        cur++;
      }
    }
    //  assert(rl_mask == mask * (1LL << ceva));
    bool is = true;
    for (int i = 0; i < n; i++) {
      if (rl_mask & (1LL << i)) {
        is &= ((vecs[i] & rl_mask) == rl_mask);
      }
    }
    if (is) {
      set<int> gud;
      for (int i = 0; i < dim; i++) gud.insert(i);
      for (int i = 0; i < n; i++) {
        if (rl_mask & (1LL << i)) {
          for (int j = 0; j < n; j++) {
            if (!(vecs[i] & (1LL << j))) gud.erase(j);
          }
        }
      }
      int re = 0;
      for (auto& x : gud) re += (1 << x);
      assert(re < (1 << dim));
      sol = max(sol, cur + best[re]);
     
    }
  }
  ld all = (ld)k / (ld)sol;
  cout << fixed << setprecision(6) << all * all / 2 * sol * (sol - 1) << "\n";
}