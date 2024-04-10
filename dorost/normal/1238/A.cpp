#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  ll a,b,t;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> a >> b;
    if((a - b) > 1){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}