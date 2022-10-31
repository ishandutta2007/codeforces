#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int n;
vector<pii> v;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    pii p;
    cin >> p.second >> p.first;
    v.push_back(p);
  }
  sort(v.begin(), v.end());
  int lst = -1, ans = 0;
  for(int i = 0; i < v.size(); ++i) {
    if(v[i].second <= lst) continue;
    ++ans;
    lst = v[i].first;
  }
  cout << ans << "\n";
  return 0;
}