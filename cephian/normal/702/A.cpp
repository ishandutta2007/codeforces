#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n;

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  int str = 0;
  int prv = -1;
  int mx = 0;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if(a > prv) {
      ++str;
      mx = max(mx,str);
    } else {
      str = 1;
    }
    prv = a;
  }
  cout << mx << "\n";
}