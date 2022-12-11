#include <iostream>
#include <vector>
using namespace std;
using VS = vector<string>;

void no() {
  cout << "No" << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  VS v(n);
  for (auto& x : v) cin >> x;
  vector<int> nums(m);
  vector<int> taken(n, false);
  for (auto& x : nums) {
    cin >> x;
    --x;
    taken[x] = true;
  }
  string p = v[nums[0]];
  for (int i = 1; i < int(nums.size()); ++i) {
    const string& t = v[nums[i]];
    if (p.size() != t.size()) no();
    for (int j = 0; j < int(p.size()); ++j) {
      if (p[j] != t[j]) p[j] = '?';
    }
  }
  for (int i = 0; i < n; ++i) {
    if (taken[i]) continue;
    const string& t = v[i];
    if (p.size() != t.size()) continue;
    bool same = true;
    for (int j = 0; j < int(p.size()); ++j) {
      if (p[j] != '?' && p[j] != t[j]) same = false;
    }
    if (same) no();
  }
  cout << "Yes" << endl << p << endl;
}