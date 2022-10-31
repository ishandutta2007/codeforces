#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int product = 0;
  for(int i = 2; i<n; i++){
    product += i*(i+1);
  }
  cout << product << endl;
}