//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  ll a[4];
  short ans = 0;
  for(short i = 0; i < 4; i++){
    cin >> a[i];
    for(short j = 0; j < i; j++){
      if(a[i] == a[j]){
        ans++;
        a[j] = 0;
      }
    }
  }
  cout << ans;
}