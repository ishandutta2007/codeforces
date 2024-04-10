#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int solve(const vector<int>& a, const vector<int>& b) {
  vector<int> sfx(b.size()+1);
  for (int i=0, j=0; i<b.size(); ++i) {
    while (j<a.size() && a[j] < b[i]) {
      ++j;
    }
    if (j < a.size() && a[j] == b[i]) {
      sfx[i] = 1;
    }
  }
  for (int i=(int) b.size()-1; i>=0; --i) {
    sfx[i] += sfx[i+1];
  }
  int x = 0;
  int r = 0;
  int ans = 0;
  for (int i=0; i<b.size(); ++i) {
    int pos = b[i]-1;
    while (x < a.size() && a[x] <= b[i]+x) {
      ++x;
    }
    while (r < b.size() && pos+x >= b[r]) {
      ++r;
    }
    ans = max(ans, r-i + sfx[r]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, m;
    cin >> n >> m;
    vector<int> apos, bpos, aneg, bneg;
    for (int i=0; i<n; ++i) {
      int x;
      cin >> x;
      (x < 0 ? aneg : apos).push_back(x);
    }
    for (int i=0; i<m; ++i) {
      int x;
      cin >> x;
      (x < 0 ? bneg : bpos).push_back(x);
    }
    for (auto& x : aneg) {
      x *= -1;
    }
    for (auto& x : bneg) {
      x *= -1;
    }
    reverse(aneg.begin(), aneg.end());
    reverse(bneg.begin(), bneg.end());
    int ans = solve(apos, bpos);
    //cerr << " ! " << ans << endl;
    ans += solve(aneg, bneg);
    cout << ans << "\n";
  }
  return 0;
}