#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, inf = 1e7;

int n, a[N];

int main() {
  scanf("%d", &n);
  int mi = 1e9 + 5;
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
    mi = min(a[i], mi);
  }
  int add = 0, now = 0;
  for(int i = 0; i<(3*n); i++) {
    now = 0;
    while(a[i % n] > mi)
      now++, i++;
    add = max(add, now);
  }
  cout << 1LL * mi * n + add << endl;  
  return 0;
}