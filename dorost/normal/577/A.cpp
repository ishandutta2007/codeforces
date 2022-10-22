#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define sz(s) s.size()

int main(){
  ll n,ans = 0;
  ll m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    if(m % i == 0 && m <= n * i){
      ans++;
    }
  }
  cout << ans;
}