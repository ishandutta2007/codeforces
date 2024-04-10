#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    while (s.back() == ')') {
      s.pop_back();
    }
    if (n - (int) s.size() > (int) s.size()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

}