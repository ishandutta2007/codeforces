#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

template <class T>
struct RMQ {
  const T kInf = numeric_limits<T>::max();
  vector<vector<T>> rmq;
  
  void Build(const vector<T>& V) {
    int n = V.size(), on = 1, depth = 1;
    while (on < n) on *= 2, ++depth;
    rmq.assign(depth, V);
    
    for (int i = 0; i < depth - 1; ++i)
      for (int j = 0; j < n; ++j) {
        rmq[i + 1][j] = max(rmq[i][j],
            rmq[i][min(n - 1, j + (1 << i))]);
      }
  }
  
  T Query(int a, int b) {
    if (b <= a) return -kInf;
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return max(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  
  auto solve = [&]() {
    vector<int> stk;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
      while (stk.size() && v[stk.back()] <= v[i]) {
        stk.pop_back();
      }
      if (stk.size()) {
        l[i] = stk.back();
      } else l[i] = -1;
      stk.push_back(i);
    }

    vector<long long> suff(v.begin(), v.end());
    for (int i = n - 2; i >= 0; --i)
      suff[i] += suff[i + 1];
    RMQ<long long> rmq;
    rmq.Build(suff);
    
    vector<long long> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = rmq.Query(l[i] + 1, i + 1) - suff[i];
    }
    return ans;
  };

  auto a1 = solve();
  reverse(v.begin(), v.end());
  auto a2 = solve();
  reverse(a2.begin(), a2.end());
  long long best = -2e18;
  for (int i = 0; i < n; ++i) {
    best = max(best, a1[i] + a2[i]);
  }
  cout << best << endl;

  return 0;
}