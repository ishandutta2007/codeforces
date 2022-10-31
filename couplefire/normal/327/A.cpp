#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  int num = 0;
  for(int i = 0; i<n; i++){
    int temp;
    cin >> temp;
    arr[i] = temp;
    if(temp == 1) num++;
  }
  int prefix[n];
  if(arr[0] == 0) prefix[0] = 1;
  else prefix[0] = -1;
  for(int i = 1; i<n; i++){
    prefix[i] = prefix[i-1];
    if(arr[i] == 0) prefix[i] += 1;
    else prefix[i] -= 1;
  }
  int highest = INT_MIN;
  for(int i = 0; i<n; i++){
    if(prefix[i] > highest) highest = prefix[i];
  }
  for(int i = 0; i<n; i++){
    for(int k = i+1; k<n; k++){
      if(prefix[k] - prefix[i] > highest) highest = prefix[k] - prefix[i];
    }
  }

  cout<<highest+num<<endl;
}