#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long num2[65] = {0};
  vector<long long> v(n);
  vector<long long> power(n);
  long long ma = -1;
  long long index = -1;
  for(long long i = 0; i<n; i++){
    long long a; cin >> a;
    v[i] = a;
    num2[__builtin_ctzll(a)]++;
    power[i] = __builtin_ctzll(a);
  }
  for(long long i = 0; i<65; i++){
    if(num2[i]>ma) index = i;
    ma = max(ma, num2[i]);
  }
  cout << n-ma << endl;
  for(long long i = 0; i<n; i++){
    if(power[i] != index) cout << v[i] << " ";
  }
  cout << endl;
}