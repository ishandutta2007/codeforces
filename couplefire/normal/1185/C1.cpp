#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  vector<int> subarr[n];
  vector<int> prev;
  int sum = 0;
  int prefix[n];
  for(int i = 0; i<n; i++){
    subarr[i] = prev;
    int temp;
    cin >> temp;
    sum += temp;
    prefix[i] = sum;
    arr[i] = temp;
    subarr[i].push_back(temp);
    prev = subarr[i];
    sort(subarr[i].begin(), subarr[i].end());
  }

  cout << 0 << " ";
  for(int i = 1; i<n; i++){
    int sum = prefix[i];
    if(sum <= m){
      cout << 0 << " ";
    }
    else{
      int count = 0;
      while(sum > m && !subarr[i-1].empty()){
        count++;
        sum -= subarr[i-1].back();
        subarr[i-1].erase(subarr[i-1].end()-1);
      }
      cout << count << " ";
    }
  }
  cout << endl;
}