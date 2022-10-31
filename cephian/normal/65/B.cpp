#include <iostream>
#include <vector>

using namespace std;

bool chk(int a, int b) {
  int d = 0;
  for(int i = 0; i < 4; ++i) {
    d += a%10 != b%10;
    a/=10;
    b/=10;
  }
  return d <= 1;
}
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    for(int j = 1000; j <= 2011; ++j) {
      if(!chk(t,j)) continue;
      if(i == 0 || j >= v.back()) {
        v.push_back(j);
        goto skp;
      }
    }
    cout << "No solution\n";
    return 0;
    skp:;
  }
  for(int i = 0; i < n; ++i)
    cout << v[i] << "\n";
  return 0;
}