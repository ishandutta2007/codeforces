#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> Set, Left, Right;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (i >= 2) {
      auto it = Set.lower_bound(x);
      if (it != Set.end() && !Left.count(*it)) {
        Left.insert(*it);
        cout << *it << " ";
      } else {
        it--;
        Right.insert(*it);
        cout << *it << " ";
      }
    }
    Set.insert(x);
  }
  cout << "\n";
}