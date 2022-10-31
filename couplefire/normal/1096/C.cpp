#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for(int j = 0; j<t; j++){
    int ang;
    cin >> ang;
    for(int i = 3; i<=360; i++){
      int temp = ang*i/180;
      if(temp*180 == ang*i && temp < i-1){
        cout << i << endl;
        break;
      }
    }
  }
}