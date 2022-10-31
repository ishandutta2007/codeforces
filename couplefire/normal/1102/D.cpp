#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_map<int, int> m;
  int n;
  cin >> n;
  int num0 = -n/3;
  int num1 = -n/3;
  int num2 = -n/3;
  int arr[n];
  string s;
  cin >> s;
  for(int i = 0; i<n; i++){
    int temp = s[i]-'0';
    if(temp == 0) num0++;
    else if(temp == 1) num1++;
    else num2++;
    arr[i] = temp;
  }
  if(num0 < 0){
    for(int i = 0; i<n; i++){
      if(num0 == 0) break;
      if(arr[i] == 1 && num1>0){
        arr[i] = 0;
        num1--;
        num0++;
      }
      else if(arr[i] == 2 && num2>0){
        arr[i] = 0;
        num2--;
        num0++;
      }
      
    }
  }
  if(num2 < 0){
    for(int i = n-1; i>=0; i--){
      if(num2 == 0) break;
      if(arr[i] == 1 && num1>0){
        arr[i] = 2;
        num1--;
        num2++;
      }
      else if(arr[i] == 0 && num0>0){
        arr[i] = 2;
        num0--;
        num2++;
      }
    
    }
  }
  if(num1 < 0){
    for(int i = 0; i<n; i++){
      if(num1 == 0) break;
      if(arr[i] == 2 && num2 > 0){
        arr[i] = 1;
        num2--;
        num1++;
      }
      
    }
    for(int i = n-1; i>=0; i--){
      if(num1 == 0) break;
      if(arr[i] == 0 && num0>0){
        arr[i] = 1;
        num0--;
        num1++;
      }
    }
  }
  for(int i = 0; i<n; i++) cout << arr[i];
  cout << endl;
}