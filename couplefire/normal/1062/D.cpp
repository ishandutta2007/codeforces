#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  long long ans = 0;
  cin >> n;
  for(long long i = 2; i<=n; i++){
    long long t = n/i;
    if(t != 0) t = t*(t+1)/2-1;
    ans += t;
  }
  ans *= 4;
  cout << ans << endl;
}