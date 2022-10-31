#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int n,k;
string s;
int c[26]={0};
vector<pii> v;
set<int> dist;

int main() {
  ios::sync_with_stdio(0);
  cin >> s >> k;
  n = s.size();
  for(int i = 0; i < n; ++i) {
    ++c[s[i]-'a'];
  }
  for(int i = 0; i < 26; ++i) {
    v.push_back(pii(c[i], i));
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < 26; ++i) {
    c[v[i].second] = min(v[i].first, k);
    k -= min(v[i].first, k);
  }
  string ans = "";
  for(int i = 0; i < n; ++i) {
    if(c[s[i]-'a'] > 0) {
      --c[s[i]-'a'];
    } else {
      ans += s[i];
      dist.insert(s[i]);
    }
  }
  cout << dist.size() << "\n";
  cout << ans << "\n";

  return 0;
}