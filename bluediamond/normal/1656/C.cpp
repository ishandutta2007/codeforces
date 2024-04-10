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

bool home = true;

using namespace std;
typedef long long ll;


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

  function<void(vector<int>&)> repair = [&](vector<int>& a) {
    sort(a.begin(), a.end());
    int dimension = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      if (i == 0 || a[i] != a[i - 1]) {
        swap(a[i], a[dimension++]);
      }
    }
    a.resize(dimension);
  };

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    repair(a);
    bool has0 = false, has1 = false;
    for (auto& x : a) has0 |= (x == 0);
    for (auto& x : a) has1 |= (x == 1);
    if (!has1) {
      cout << "YES\n";
      continue;
    }
    if (has0) {
      cout << "NO\n";
      continue;
    }
    bool ok = true;
    for (int i = 1; i < (int)a.size(); i++) ok &= (a[i] - a[i - 1] != 1);
    cout << (ok ? "YES" : "NO") << "\n";
  }
  
}