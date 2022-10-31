#include <iostream>
#include <map>
#include <set>

using namespace std;


int main() {
  int n,a=0,b=0;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a|=t;
  }
  for(int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    b|=t;
  }

  cout << a+b << "\n";
}