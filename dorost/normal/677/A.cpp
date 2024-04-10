#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,c=0,a;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a > m){
      c+=2;
    }else{
      c++;
    }
  }
  cout << c;
}