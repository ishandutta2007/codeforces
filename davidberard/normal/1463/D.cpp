#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


// what's the maximum number of maxes we can take?
int get_mins(const int n, const vector<int>& b) {
  set<int> avail;
  {
    int j = 0;
    for (int i=1; i<=n*2; ++i) {
      if (j < b.size() && b[j] == i) {
        ++j;
        continue;
      }
      avail.insert(i);
    }
  }
  for (int i=0; i<n; ++i) {
    auto it = avail.upper_bound(b[i]);
    if (it == avail.end()) {
      return i;
    }
    avail.erase(it);
  }
  return n;
}
int get_maxes(const int n, const vector<int>& b) {
  set<int> avail;
  {
    int j = 0;
    for (int i=1; i<=n*2; ++i) {
      if (j < b.size() && b[j] == i) {
        ++j;
        continue;
      }
      avail.insert(i);
    }
  }
  for (int i=0; i<n; ++i) {
    auto it = avail.lower_bound(b[n-1-i]);
    if (it == avail.begin()) {
      return i;
    }
    avail.erase(--it);
  }
  return n;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto& x : b) {
      cin >> x;
    }
    int maxes = get_maxes(n, b);
    int mins = get_mins(n, b);
    cout << mins - (n - maxes) + 1 << "\n";
  };
  return 0;
}