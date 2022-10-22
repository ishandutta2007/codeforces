//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  int n;
  cin >> n;
  int a[n], ans = n,d[n] = {};
  for(int i = 0; i < n; i++){
    d[i] = 1;
    cin >> a[i];
    for(int j = 0; j < i; j++){
      if(a[i] == a[j]){
        ans--;
        d[j] = 0;
        a[j] = 0;
      }
    }
  }
  cout << ans << endl;
  for(int i = 0; i < n; i++){
    if(d[i]){
      cout << a[i] << ' ';
    }
  }
}