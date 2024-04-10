#include <bits/stdc++.h>
using namespace std;

int main() {
  long long q; cin >> q;
  while(q--){
    long long a, b, c, d; cin >> a >> b >> c >> d;
    d -= b;
    long long t = ceil((long double)d/c);
    if(t > a){
      cout << "NO" << endl;
      continue;
    }
    if(t*c > d+b){
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
}