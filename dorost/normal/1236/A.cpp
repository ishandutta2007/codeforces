//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  ll t;
  cin >> t;
  while(t--){
    ll a,b,c;
    cin >> a >> b >> c;
    ll ans1 = 0,ans2 = 0;
    ll x = b;
      ans1 += (min(a , b / 2) * 3);
      b = b - min(a,b/2) * 2;
      ans1 += (min(b, c / 2) * 3);
      ans2 += (min(x , c / 2) * 3);
      x = x - min(x,c/2);
      ans2 += min({a ,x / 2}) * 3;
    cout << max(ans1,ans2) << endl;
  }
}