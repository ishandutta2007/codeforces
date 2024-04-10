#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> s;
  for (int i = 1; i <= 4; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << 4 - (int) s.size() << "\n";

}