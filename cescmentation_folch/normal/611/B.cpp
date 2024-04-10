#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll a, b;
  cin >> a >> b;
  
  ll res = 0;
  for(ll i = 1; i <= 61; ++i){
    ll k = (1ll<<i)-1ll;
    for(ll j = 0; j < i - 1; ++j){
      k -= (1ll<<j);
      if(a <= k and k <= b) ++res;
      k += (1ll<<j);
    }
  }
  
  cout << res << endl;
}