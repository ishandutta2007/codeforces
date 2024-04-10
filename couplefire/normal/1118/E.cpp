#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  if(m*(m-1) < n){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  long long total = 0;
  for(long long i = 1; i<=m; i++){
    for(long long k = i+1; k<=m; k++){
      cout << i << " " << k << endl;
      if(++total >= n) return 0;
      cout << k << " " << i << endl;
      if(++total >= n) return 0;
    }
  }
}