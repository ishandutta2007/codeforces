#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed;
  long long n;
  cin >> n;
  for(long long i = 0; i<n; i++){
    long long t;
    cin >> t;
    vector<long long> vec;
    for(long long k = 0; k<t; k++){
      long long temp;
      cin >> temp;
      vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    long long result = vec.front() * vec.back();
    for(long long k = 0; k<vec.size(); k++){
      long long temp = vec[k] * vec[vec.size()-1-k];
      if(temp != result){
        result = -1;
        break;
      }
    }
    int counter = 0;
    if(result != -1){
      for(int k = 2; k<= sqrt(result); k++){
        if(result % k == 0){
          if(vec[counter] != k){
            result = -1;
            break;
          }
          counter++;
        }
      }
    }
    cout << result << endl;
  }
}