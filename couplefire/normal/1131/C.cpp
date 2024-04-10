#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec;
  for(int i = 0; i<n; i++){
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }

  sort(vec.begin(), vec.end());
  vector<int> even;
  vector<int> odd;
  for(int i = 0; i<n; i+=2){
    even.push_back(vec[i]);
  }
  for(int i = 1; i<n; i+=2){
    odd.push_back(vec[i]);
  }
  reverse(odd.begin(), odd.end());
  even.insert(even.end(), odd.begin(), odd.end());

  for(int i = 0; i<n; i++){
    cout << even[i] << " ";
  }
  cout << endl;
}