#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  int q , n;
  cin >> q;
  while(q--){
    double a , sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> a;
      sum += a;
    }
    cout << (int)ceil(sum / n) << endl; 
  }
}