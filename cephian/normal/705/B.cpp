#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int p = 0;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    p ^= (a-1)&1;
    if(p) cout << "1\n";
    else cout << "2\n";
  }
  return 0;
}