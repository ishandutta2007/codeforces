#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll Mod = 1000000007;

int main(){
  int n;
  cin >> n;
  if(n == 1){
    cout << "YES";
    return 0;
  }
  for(int i = 1; i < n; i++){
    if(n == (i * (i + 1)) / 2){
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}