//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << fixed << setprecision(6);
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,ans = 1;
    bool f = false;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++){
      if(abs(a[i] - a[i - 1]) == 1){
        f = true;
      }
    }
    if(f){
      cout << 2;
    }else{
      cout << 1;
    }
    cout << endl;
  }
}