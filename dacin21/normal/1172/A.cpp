#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(int x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


bool is_possible(vector<int> const& a, vector<int> const& b, int k) {
  unordered_set<int, custom_hash > have(a.begin(), a.end());
  have.insert(b.begin(), b.begin()+k);
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    if (!have.count(i+1))
      return false;
    // play i
    // draw top card
    if (k+i < n)
      have.insert(b[k+i]);
  }
  return true;
}

bool can_append_one(vector<int> const& a, vector<int> const& b) {
  auto one = find(b.begin(), b.end(), 1);
  if (one == b.end()) return false;
  if (!is_sorted(one, b.end())) return false;
  int n = a.size();

  auto into = b.begin();
  unordered_set<int, custom_hash > have(a.begin(), a.end());
  int cnt = b.end() - one;
  while (cnt < n) {
    if (!have.count(++cnt))
      return false;
    // play cnt+1
    // draw top card
    have.insert(*into++);
  }
  assert(into == one);
  return true;
}

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int n; cin >> n;
  vector<int> a, b;
  copy_n(istream_iterator<int>(cin), n, back_inserter(a));
  copy_n(istream_iterator<int>(cin), n, back_inserter(b));
  if (is_sorted(b.begin(), b.end()) && b[0] == 1) {
    cout << 0 << '\n';
    return 0;
  }

  if (can_append_one(a, b)) {
    cout << find(b.begin(), b.end(), 1) - b.begin() << '\n';
    return 0;
  }
  if (is_possible(a, b, 0)) {
    cout << n << '\n';
    return 0;
  }
  
  int l=0, r=n;
  // invariant: l impossible, r possible
  while (r-l > 1) {
    int m = (l+r)/2;
    if (is_possible(a, b, m))
      r = m;
    else
      l = m;
  }
  cout << n+r << '\n';
}