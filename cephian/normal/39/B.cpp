#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
  int n;
  cin >> n;
  int cur = 1;
  for(int i = 2001; i <= 2000+n; ++i) {
    int a;
    cin >> a;
    if(a == cur) {
      v.push_back(i);
      ++cur;
    }
  }
  cout << v.size() << "\n";
  for(int i = 0; i < v.size(); ++i) {
    cout << v[i];
    if(i != v.size()-1) cout << " ";
    else cout << "\n";
  }
  return 0;
}