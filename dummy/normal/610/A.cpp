#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;

int main() {
  cin >> n;
  if(n & 1)
    puts("0");
  else {
    n /= 2;
    n = (n+1)/2 - 1;
    printf("%d\n", n);
  }
  return 0;
}