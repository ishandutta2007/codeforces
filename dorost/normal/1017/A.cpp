#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define sz(s) s.size()

int main(){
  bool f = false;
  int n,a;
  cin >> n;
  int sum[n] = {}, b[n] = {};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++){
      cin >> a;
      sum[i] += a;
      b[i] += a;
    }
    // cout << ' ' << sum[i] << ' ' << b[i] << endl;
  }
  sort(b, b + n);
  for(int j = 0; j < n / 2; j++){
    swap(b[j], b[n - j - 1]);
  }
  for(int j = 0; j < n; j++){
    if(b[j] == sum[0]){
      cout << j + 1;
      f = true;
      return 0;
    }
  }
  if(!f){
    cout << 1;
  }
}