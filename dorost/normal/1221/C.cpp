//***In the name of GOD***\\

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(s) s.size()
// for(int i = 0;i < n; i++)

int main(){
  int t;
  cin >> t;
  while(t--){
    int a,b,c;
    cin >> a >> b >> c;
    cout << min({a , b ,(a + b + c) / 3}) << endl;
  }
}