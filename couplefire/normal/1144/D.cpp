#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> count(200001);
  for(int i = 0; i<n; i++){
    int temp;
    cin >> temp;
    arr[i] = temp;
    count[temp]++;
  }

  int theone = max_element(count.begin(), count.end())-count.begin();
  int position = find(arr.begin(), arr.end(), theone) - arr.begin();
  int highest = count[theone];

  cout << n-highest << endl;
  for(int i = position-1; i>=0; --i){
    cout << 1+(arr[i]>arr[i+1]) << " " << i+1 << " " << i+2 << endl;
    arr[i] = arr[i+1];
  }
  for(int i = 0; i<n-1; ++i){
    if(arr[i+1] != theone){
      cout << 1+(arr[i+1]>arr[i]) << " " << i+2 << " " << i+1 << endl;
      arr[i+1] = arr[i];
    }
  }
}