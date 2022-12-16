#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 110;

struct Res : vector<int> {
  size_t get_hash() const {
    size_t ans = 0;
    for (auto& x : *this) {
      ans = ans*31+x;
    }
    return ans;
  }
};
namespace std{
  template<>
  struct hash<Res> {
    size_t operator() (const Res& r) const {
      return r.get_hash();
    }
  };
}

unordered_map<Res, int> mp;
int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  int lowmask = (1<<15)-1;
  Res cur;
  for (int i=0; i<(1<<15); ++i) {
    cur.clear();
    for (int j=1; j<=n; ++j) {
      cur.push_back(__builtin_popcount((a[j]^i)&lowmask));
    }
    for (int j=n-1; j>=0; --j) {
      cur[j] -= cur[0];
    }
    mp[cur] = i;
  }
  int himask = lowmask*(1<<15);
  for (int _i=0; _i<(1<<15); ++_i) {
    int i = _i*(1<<15);
    cur.clear();
    for (int j=1; j<=n; ++j) {
      cur.push_back(__builtin_popcount((a[j]^i)&himask));
    }
    for (int j=n-1; j>=0; --j) {
      cur[j] -= cur[0];
      cur[j] *= -1;
    }
    if (mp.count(cur)) {
      //cerr << " I " << i << endl;
      cout << (mp[cur]^i) << "\n";
      return 0;
    }
    //cerr <<  "FAIL " << i << endl;
  }
  cout << -1 << "\n";
  return 0;
}