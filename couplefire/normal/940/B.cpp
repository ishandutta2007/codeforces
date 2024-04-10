#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  long long hi = a*(n-1);
  if(k == 1){
    cout << a*(n-1) << endl;
    return 0;
  }
  long long total = 0;
  while(n > 1){
    if(n % k == 0){
      long long copy = n;
      n /= k;
      if((copy-n)*a > b){
        total += b;
      }
      else{
        total += (copy-n)*a;
      }
    }
    else{
      if(n < k){
        total += a*(n-1);
        n = 1;
        continue;
      }
      long long remainder = n%k;
      n -= remainder;
      total += a*remainder;
    }
  }
  if(hi> total) cout << total << endl;
  else cout << hi << endl;
}