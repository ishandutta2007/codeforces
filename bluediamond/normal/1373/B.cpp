#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int so = 0;
    vector<int> a;
    for (auto &ch : s) {
      int x = ch - '0';
      if (!a.empty() && a.back() != x) {
        a.pop_back();
        so++;
      } else {
        a.push_back(x);
      }
    }
    if (so % 2) {
      cout << "DA\n";
    } else {
      cout << "NET\n";
    }
  }
  return 0;
}