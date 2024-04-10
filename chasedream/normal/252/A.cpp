#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int a[N], b[N];
int n, ans;

void ckmax(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = b[i - 1] ^ a[i];
  }  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      ckmax(ans, b[j] ^ b[i]);
    }    
  }
  printf("%d\n", ans);
}