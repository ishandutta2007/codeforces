#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long sumf = 0;
  double arr[n];
  for(int i = 0; i<n; i++){
    double temp;
    cin >> temp;
    arr[i] = temp;
    sumf += floor(temp);
  }
  sumf = 0 - sumf;
  for(int i = 0; i<n; i++){
    if(floor(arr[i]) != ceil(arr[i]) && sumf > 0){
      if((ceil(arr[i]) + 0) == 0) cout << 0 << endl;
      else cout << ceil(arr[i]) << endl;
      sumf -= 1;
      continue;
    }
    cout << floor(arr[i]) << endl;
  }
}