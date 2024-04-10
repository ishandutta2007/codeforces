#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    int b=0;
    int c=a[n-1];
    for(int i= n - 2; i >= 0; i--){
      if(a[i] > c){
        b++;
      }else{
        c=a[i];
      }
    }
    cout << b << endl;
  }
}