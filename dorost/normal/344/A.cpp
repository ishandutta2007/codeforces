#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,b=0;
  cin >> n;
  int a[n];
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    if(a[i]==a[i-1]){
    }else{
      b++;
    }
  }
  cout << b;
}