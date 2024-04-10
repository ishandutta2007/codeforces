#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long sumx = 0;
  long long sumy = 0;
  for(int i = 0; i<2*n; i++){
    int x;
    int y;
    cin >> x >> y;
    sumx += x;
    sumy += y;
  }
  sumx /= n;
  sumy /= n;
  cout << sumx << " " << sumy << endl;
}