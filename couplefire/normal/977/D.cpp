#include <bits/stdc++.h>
using namespace std;

struct number{
  long long value;
  long long index;
  long long mult3 = 0;
  long long mult2 = 0;
  number(long long n, long long i){
    value = n;
    index = i;
    long long copy1 = value;
    long long copy2 = value;
    while(copy1 % 3 == 0){
      mult3++;
      copy1 /= 3;
    }
    while(copy2 % 2 == 0){
      mult2++;
      copy2 /= 2;
    }
  }
  bool operator<(number o) const{
    if(o.mult3 > mult3){
      return false;
    }
    else if(o.mult3 < mult3){
      return true;
    }
    else{
      if(o.mult2 < mult2){
        return false;
      }
      else if(o.mult2 > mult2){
        return true;
      }
      else{
        return true;
      }
    }
  }
};

int main() {
  long long n;
  cin >> n;
  long long arr[n];
  vector<number> numbers;
  for(long long i = 0; i<n; i++){
    long long temp;
    cin >> temp;
    numbers.push_back(number(temp, 1));
  }
  sort(numbers.begin(), numbers.end());
  for(long long i = 0; i<n; i++){
    cout << numbers[i].value << " ";
  }
  cout << endl;
}