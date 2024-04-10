#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed;
  long long n;
  cin >> n;
  for(long long i = 0; i<n; i++){
    long long k, n, a, b;
    cin >> k >> n >> a >> b;
    if(k <= n*b){
      cout << -1 << endl;
      continue;
    }
    if(k > a*n){
      cout << n << endl;
      continue;
    }
    if((k - b*n) % (a-b) == 0) cout << (long long) (k - b*n)/(a-b)-1 << endl;
    else cout << (long long) floor((k - b*n)/(a-b)) << endl;
  }
}