#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> pci;
vector<pci> ar,br;
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; string a,b;
  cin >> n;
  while (n--) {
    ar.clear(), br.clear();
    cin >> a >> b;
    for (int x = 0; x < a.length(); x++) {
      if (x == 0 || a[x] != a[x-1]) ar.push_back({a[x],1});
      else ar[ar.size()-1].second++;
    }
    for (int x = 0; x < b.length(); x++) {
      if (x == 0 || b[x] != b[x-1]) br.push_back({b[x],1});
      else br[br.size()-1].second++;
    }
    if (ar.size() != br.size()) {cout << "NO\n"; goto done;}
    for (int x= 0 ; x < ar.size(); x++) {
      if (ar[x].first != br[x].first || br[x].second < ar[x].second) {cout << "NO\n"; goto done;}
    }
    cout << "YES\n";
    done:;
  }
  return 0;
}