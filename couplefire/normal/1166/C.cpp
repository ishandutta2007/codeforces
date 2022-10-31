#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed;
  int n;
  cin >> n;
  int arr[n];
  int half[n];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    arr[i] = abs(arr[i]);
    half[i] = (arr[i]+1)/2;
  }
  sort(half, half+n);
  sort(arr, arr+n);
  map<int, int> num;
  int numm[n];
  int k = n-1;
  for(int i = n-1; i>=0; i--){
    numm[i] = n-i;
    while(arr[i] < half[k]){
      k--;
    }
    if(num.count(half[k]) == 0){
      num.insert(pair<int, int> (half[k], 1));
    }
    else{
      num[half[k]]++;
    }
    
  }
  for(int i = n-2; i>=0; i--){
    if(half[i] != half[i+1]){
      num[half[i]] += num[half[i+1]];
    }
  }
  long long re = 0;
  for(int i = n-1; i>=0; i--){
    re += num[half[i]] - numm[i];
  }
  cout << re << endl;
}

/*
3
0 7 7

*/