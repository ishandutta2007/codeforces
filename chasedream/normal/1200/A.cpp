%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 500005;
int a[N];
int n;
char c[N];
int L, R;
 
int main() {
  scanf("%d\n", &n);
  scanf("%s", c + 1);
  L = 0, R = 9;
  for (int i = 1; i <= n; i++) {
    if (c[i] == 'L') {
      for (int j = 0; j <= 9; j++)
        if (!a[j]) {
          a[j] = 1; break;
        } 
    }
    else if (c[i] == 'R') {
      for (int j = 9; j >= 0; j--) 
        if (!a[j]) {
          a[j] = 1; break;
        }
    }
    else {
      a[c[i] - '0'] = 0;
    }
  } 
  for (int i = 0; i <= 9; i++)
    cout << a[i];
}