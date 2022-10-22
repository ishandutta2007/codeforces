#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k,b=0;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  // sort(a, a+n);
  for(int i = 0; i < n; i++){
    if((a[i] >= a[k - 1]) && (a[i])){
      b++;
    }
  }
  cout << b;
}