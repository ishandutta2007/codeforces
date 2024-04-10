#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int k = 0;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    if(i > 1 && a[i] == 1 && a[i-1] == 0 && a[i-2] == 1) {
      ++k;
      a[i] = 0;
    }
  }
  cout << k << "\n";  
}