#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  long long i;
  bool found = false;
  for(i = 0; i<w; i++){
    if((p-i*d) % w == 0){
      found = true;
      break;
    }
  }
  if(found){
    long long x = (p-i*d)/w;
    if(x >= 0 && x+i<=n){
      cout << x << " " << i << " " << n-x-i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}