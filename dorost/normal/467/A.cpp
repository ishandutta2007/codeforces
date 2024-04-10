#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  int n, a, b, c = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    if((b - a) > 1){
      c++;
    }
  }
  cout << c; 
}