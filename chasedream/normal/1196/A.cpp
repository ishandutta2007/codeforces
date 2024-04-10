#include <bits/stdc++.h>
using namespace std;
 
long long a, b, c;
int main(){
  int t ; scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", (a + b + c) >> 1);
  }
  return 0;
}