#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;

vector<vector<int> > teeth;

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < m ; ++i)
    teeth.push_back(vector<int>());
  for(int i = 0; i < n; ++i) {
    int r, c;
    cin >> r >> c;
    teeth[r-1].push_back(c);
  }
  int q = 0;
  for(int i = 0; i < m ; ++i) {
    if(teeth[i].empty()) continue;
    q += *min_element(teeth[i].begin(), teeth[i].end());
  }
  cout << min(q, k) << "\n";
  return 0;
}