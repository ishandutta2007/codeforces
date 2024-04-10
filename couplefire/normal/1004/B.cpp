#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int print = 1;
  for(int i = 0; i<n; i++){
    cout<<print;
    print = 1-print;
  }
  cout << endl;
}