#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b = 0,c = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a % 2){
      b++;
    }else{
      c++;
    }
  }
  cout << min(b , c);
}