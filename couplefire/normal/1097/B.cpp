#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i<n; i++){
    int temp;
    cin >> temp;
    arr[i] = temp;
  }
  int total = 1 << n;

  bool work = false;

  for(int i = 0; i<total; i++){
    int sum = 0;
    for(int k = 0; k<n; k++){
      if(i & (1 << k)) sum += arr[k];
      else sum -= arr[k];
    }
    if(sum % 360 == 0){
      work = true;
      break;
    }
  }
  if(work) cout << "YES" << endl;
  else cout << "NO" << endl;
}