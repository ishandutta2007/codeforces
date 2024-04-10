#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a,b;
  for(int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if(p==1) a=i;
    else if(p==n) b=i;
  }
  if(a > b) swap(a,b);
  cout << max(b-1, n-a) << "\n";
  return 0;
}