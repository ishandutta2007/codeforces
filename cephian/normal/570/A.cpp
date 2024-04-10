#include <iostream>
#include <algorithm>

using namespace std;

int vote[105];
int fin[105];
int main() {
  ios::sync_with_stdio(0);
  int n,m;
  cin>>n>>m;
  fill(fin, fin + 105, 0);
  for(int i = 0; i < m; ++i) {
    int mx = 0;
    for(int j = 0; j < n; ++j) {
      cin >> vote[j];
      if(vote[mx] < vote[j])
        mx = j;
    }
    ++fin[mx];
  }
  int ans = 0;
  for(int i = 1; i < n; ++i) {
    if(fin[i] > fin[ans])
      ans = i;
  }
  cout << ans+1 << "\n";
  return 0;
}