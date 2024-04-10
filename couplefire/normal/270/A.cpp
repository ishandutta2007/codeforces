#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i<n; i++){
    int a;
    cin >> a;
    if(360 % (180-a) == 0 && 360 / (180-a) >= 3) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}