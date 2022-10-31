#include <bits/stdc++.h>
using namespace std;
double n, k;
vector<int> arr(7, 0);
double ans = 0;
int q = 0;

void recur(int cnt){
  if(cnt == k){
    q++;
    double temp = 0;
    for(int i = 0; i<n; i++){
      for(int j = i+1; j<n; j++){
        if(arr[i] > arr[j]) temp++;
      }
    }
    ans += temp;
  }
  else{
    vector<int> tarr = arr;
    for(int i = 0; i<n; i++){
      for(int j = i; j<n; j++){
        arr = tarr;
        for(int b = i; b<=j; b++){
          arr[b] = tarr[i+j-b];
        }
        recur(cnt+1);
      }
    }
  }
}

int main() {
  cout << setprecision(12);
  cout << fixed;
  cin >> n >> k;
  for(int i = 0; i<n; i++){
    int a;
    cin >> a;
    --a;
    arr[i] = a;
  }
  recur(0);
  cout << (double)ans/q << endl;
}