#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,sa=0,sb=0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    if(a > b){
      sa++;
    }
    if(a < b){
    sb++;
    }
  }
  if(sa > sb){
    cout << "Mishka";
  }else if(sa < sb){
    cout << "Chris";
  }else{
    cout << "Friendship is magic!^^";
  }
}