#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> f;
int n, m;
int arr[100005];

vector<int> consider;
vector<vector<int> > partial;

int range(int i, int l, int r) {
  return partial[i][r] - ((l == 0)?0:partial[i][l-1]);
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
      cin >> arr[i];
      if(arr[i] <= n) ++f[arr[i]];
  }
  for(map<int, int>::iterator i = f.begin(); i != f.end(); ++i)
    if(i->second >= i-> first) consider.push_back(i->first);
  for(int i = 0; i < consider.size(); ++i) {
    partial.push_back(vector<int>());
    for(int j = 0; j < n; ++j)
      partial[i].push_back(arr[j] == consider[i]);
    for(int j = 1; j < n; ++j)
      partial[i][j] += partial[i][j-1];
  }

  for(int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for(int j = 0; j < consider.size(); ++j)
      if(range(j, l-1, r-1) == consider[j]) ++ans;
    cout << ans << "\n";
  }

  return 0;
}