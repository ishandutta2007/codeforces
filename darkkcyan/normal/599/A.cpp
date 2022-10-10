#include <iostream>
using namespace std;

int main (void) {
  ios_base::sync_with_stdio(0);
  
  int d1, d2, d3;
  
  cin >> d1 >> d2 >> d3;
  
  if (d3 > d1 + d2) {
    d3 = d1 + d2;
  } else if (d1 > d3 + d2) {
    d1 = d3 + d2;
  } else if (d2 > d3 + d1) {
    d2 = d3 + d1;
  }
  
  cout << d1 + d2 + d3;
  
  return 0;
}