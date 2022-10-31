#include <iostream>

using namespace std;

int val(int n) {
  if(n&1)
    return (n*n+1)/2;
  return (((n-1)/2)*((n-1)/2)+1)/2;
}

bool ok(int n, int x) {
  if(n == 1) return x < 2;
  if(n == 2) return x == 0;
  int v = val(n);
  if(~n&1) return v >= x && x%4 == 0;
  int s4 = (((n-1)/2)*((n-1)/2)+1)/2;
  int s2 = v - 4*s4 - 1;
  while(v-4 >= x && s4--)
    v -=4;
  while(v-2 >= x && s2--)
    v -= 2;
  return v == x || v-1 == x;
}

int main() {
  int x;
  cin >> x;
  if(x == 2) cout << "3\n";
  else {
  for(int n = 1; ; ++n) {
    if(ok(n, x)) {
      cout << n << "\n";
      return 0;
    }
  }
}
}