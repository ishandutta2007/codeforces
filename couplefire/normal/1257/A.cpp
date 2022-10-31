#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; scanf("%d", &q);
  while(q--){
    int n, x, a, b; scanf("%d %d %d %d", &n, &x, &a, &b);
    if(a > b) swap(a, b);
    int sum = a-1 + n-b;
    printf("%d\n", b-a + min(sum, x));
  }
}