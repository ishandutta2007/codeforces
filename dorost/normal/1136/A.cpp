//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(s) s.size()
int main(){
  int t;
  cin >> t;
  int a[t],b[t];
  for(int i = 0; i < t;i++){
    cin >> a[i] >> b[i];
  }
  int p;
  cin >> p;
  bool f = false;
  int ans = 1;
  for(int i = 0 ; i < t;i++){
    if(p <= b[i]){
      ans = t - i;
      f = true;
      break;
    }
  }
  cout << ans;
}