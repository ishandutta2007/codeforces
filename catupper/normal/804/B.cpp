#include<string>
#include<iostream>

using namespace std;
#define MOD 1000000007
typedef long long Int;

int main(){
  Int res = 0;
  Int addval = 1;
  string str;
  cin >> str;
  for(int i = 0;i < str.size();i++){
    if(str[i] == 'a'){
      addval = (addval * 2) % MOD;
    }
    else res = (res + addval - 1) % MOD;    
  }
  cout << res << endl;
  return 0;
}