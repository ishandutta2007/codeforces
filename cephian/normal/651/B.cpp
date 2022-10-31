#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    ++m[t];
  }
  int q = 1;
  for(map<int,int>::iterator i = m.begin(); i != m.end(); ++i) {
    q = max(q,i->second);
  }
  cout << n-q << "\n";
  return 0;
}