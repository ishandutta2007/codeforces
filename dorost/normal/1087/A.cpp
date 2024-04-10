//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(s) s.size()
int main(){
  string s;
  cin >> s;
  int n = sz(s);
  if(n % 2){
    cout << s[n / 2];
  }
  for(int i = 0;i < n / 2;i++){
    if(n % 2){
      cout << s[n / 2 + i + 1] << s[n / 2 - i - 1];
    }else{
      cout << s[n / 2 - i - 1] << s[n / 2 + i];
    }
  }
}
// int n;
// cin >> n;
// int a[n];
// for(int i = 0;i < n;i++){
//   cin >> a[i];
// }
// sort(a , a + n);
// int sum = 0;
// for(int i = 0;i < n - 1;i++){
//   sum += ((n - i - 1)*a[i]);
// }
// cout << sum;