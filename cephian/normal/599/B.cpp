#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<int,int> a;
map<int,int> r;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;

  for(int i = 0; i < n; ++i) {
    int f;
    cin >> f;
    ++a[f];
    r[f]=i+1;
  }
  bool amb = 0;
  for(int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    if(a[b]==1) {
      v.push_back(r[b]);
      continue;
    }
    if(a[b]==0) {
      cout << "Impossible\n";
      return 0;
    }
    amb = 1;
  }
  if(amb) {
    cout << "Ambiguity\n";
    return 0;
  }
  cout << "Possible\n";
  for(int i = 0; i < v.size(); ++i) {
    if(i) cout << " ";
    cout << v[i];
  }
  cout << "\n";
  return 0;
}