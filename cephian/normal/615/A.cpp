#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int n,m;
set<int> a;

int main() {
	ios::sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while(k--) {
      int t;
      cin >> t;
      a.insert(t);
    }
  }
  if(a.size() == m)
    cout << "YES\n";
  else cout << "NO\n";
	return 0;
}