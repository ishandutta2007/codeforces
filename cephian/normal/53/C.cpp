#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;

int main() {
  cin >> n;
  int s = 1;
  int sgn = 1;
  for(int i = n-1; i >= 0; --i, sgn*=-1) {
    cout << s;
    s += sgn*i;
    if(i == 0) cout << "\n";
    else cout << " ";
  }
}