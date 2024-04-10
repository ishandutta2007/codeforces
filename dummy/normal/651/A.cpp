#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for(int i = 0; i<= a+b; i++) {
    int j = (i+a)/2;
    if(j > 2*i - b + 1) {
      ans = max(ans, i+j);
    } 
  }
  for(int i = 0; i<= a+b; i++) {
    int j = (i+b)/2;
    if(j > 2*i - a + 1) {
      ans = max(ans, i+j);
    } 
  }
  cout << ans << endl;
  return 0;
}