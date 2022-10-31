#include <iostream>

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  int prv,skp;
  for(int i = 0; i < k; ++i) {
    if(i) cout << " ";
    if(i%2==0) {
      prv = n-i/2;
      skp = -1;
    }
    else {
      prv = 1+i/2;
      skp=1;
    }
    cout << prv;
  }
  for(int i = k; i < n; ++i) {
    cout << " ";
    prv+=skp;
    cout << prv;
  }
  cout << "\n";
  return 0;
}