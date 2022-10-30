#include <bits/stdc++.h>
using namespace std;

int main() {
  int k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  int n = k1+k2+k3;
  int num[n+1];
  int arr[n+1];
  for(int i = 0; i<k1; i++){
    int a; cin >> a;
    arr[a] = 1;
  }
  for(int i = 0; i<k2; i++){
    int a; cin >> a;
    arr[a] = 2;
  }
  for(int i = 0; i<k3; i++){
    int a; cin >> a;
    arr[a] = 3;
  }
  int add = 0;
  multiset<int> mst;
  mst.insert(n-k3);
  num[0] = n-k3;
  for(int i = 1; i<=n; i++){
    if(arr[i] == 1){
      num[i] = num[i-1];
    }
    else if(arr[i] == 2){
      num[i] = num[i-1]-1;
    }
    else{
      num[i] = num[i-1]+1;
    }
    mst.insert(num[i]);
  }
  int ans = *mst.begin();
  for(int i = 1; i<=n; i++){
    mst.erase(mst.find(num[i-1]));
    if(arr[i] == 1){
      add -= 1;
    }
    else if(arr[i] == 2){
      add += 1;
    }
    //cout << *mst.begin()+add << endl;
    ans = min(ans, *mst.begin()+add);
  }
  cout << ans << endl;
}