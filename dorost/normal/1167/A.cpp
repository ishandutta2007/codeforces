#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,a=0;
    bool ans = false;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
      if(s[i] == '8'){
        ans = true;
        a = i;
        break;
      }
    }
    if(ans){
      if(n - a > 10){
        cout << "YES";
      }else{
        cout << "NO";
      }
    }else{
      cout << "NO";
    }
    cout << endl;
  }
}