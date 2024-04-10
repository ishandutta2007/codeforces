#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed;
  long long n;
  cin >> n;
  long long arr[n];
  long long dif[n-1];
  cin >> arr[0];
  for(long long i = 1; i<n; i++){
    cin >> arr[i];
    dif[i-1] = arr[i] - arr[i-1];
    dif[i-1] %= n;
  }
  cout << n+1 << endl;
  arr[n-1] %= n;
  cout << 1 << " " << n << " " << n-1 - arr[n-1] << endl; 
  for(long long i = n-2; i>=0; i--){
    cout << 1 << " " << i+1 << " " << dif[i]+n-1 << endl;
  }
  cout << 2 << " " << n << " " << n << endl;
}