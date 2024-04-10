#include <iostream>

using namespace std;

string a,b;

char ga(int i) {
  if(i < 0 || i >= a.size()) return 0;
  return a[i];
}

int find(int o) {
  int diff = 0;
  for(int i = 0; i < b.size(); ++i) {
    diff += ga(i+o) != b[i];
  }
  return diff;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> a >> b;
  int ans = 0x7fffffff;
  for(int q = -int(b.size()); q <= int(a.size()); ++q) {
    ans = min(ans, find(q));
  }
  cout << ans << "\n";
  return 0;
}