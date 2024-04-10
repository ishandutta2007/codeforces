//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;
const int b = 1 / 2;

int main(){
  string s;
  cin >> s;
  int n = s.size(),sum = 0,ans = 1;
  if(n == 1){
    cout << 0;
    return 0;
  }
  for(int i = 0; i < n; i++){
    sum += (s[i] - '0');
  }
  while(sum > 9){
    ans++;
    int m = sum;
    sum = 0;
    while(m != 0){
      sum += m % 10;
      m /= 10;
    }
  }
  cout << ans;
}