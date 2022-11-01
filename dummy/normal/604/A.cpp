#include <bits/stdc++.h>

using namespace std;

int w[5], m[5], h[2], x[5];

int main() {
  for(int i = 0; i<5; i++)
    x[i] = (i+1)*500;
  for(int i = 0; i<5; i++)
    scanf("%d", m+i);
  for(int i = 0; i<5; i++)
    scanf("%d", w+i);
  scanf("%d%d", h, h+1);
  long long ans = 0;
  for(int i = 0; i<5; i++) {
    ans += max((int)(3*x[i]/10), x[i] - m[i]*x[i]/250 -50*w[i]);
  }
  ans += 100*h[0] - 50*h[1];
  cout << ans << endl;

  return 0;
}