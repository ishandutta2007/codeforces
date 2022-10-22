#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main(){
  string e[10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
  string s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
  string t[8] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
  string d;
  cin >> d;
  if(d.size() == 1){
    cout << s[d[0] - '0'];
  }else if(d[0] == '1'){
      cout << e[d[1] - '0'];
  }else{
    cout << t[d[0] - '2'];
    if(d[1] - '0'){
      cout << '-' << s[d[1] - '0'];
    }
  }
}