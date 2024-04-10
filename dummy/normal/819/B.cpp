#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;

long long a[N], b[N];

int n, p[N];

int main() {
  scanf("%d",&n);
  for (int i = 1; i <= n; i++)
    scanf("%d", p+i);
  for (int i = 1; i <= n; i++) {
    if (p[i] < i) {
      b[0] += 1;
      b[n-i] -= 1;
      b[n-i] += (p[i]-1) - (n-p[i]);
      b[p[i]+n-i] += 2;
      b[n-i+1] += -1 + (n-p[i]) - (p[i]-1);
    }
    else {
      b[0] += -1;
      b[p[i]-i] += 2;
      b[n-i] -= 1;
      b[n-i] += (p[i]-1) - (n-p[i]);
      b[n-i+1] += -1 + (n-p[i]) - (p[i]-1);
    }
  }
  long long cur = 0, add = 0;
  for (int i = 1; i <= n; i++)
    cur += abs(p[i]-i);
  long long ans = cur, id = 0;
  for (int i = 0; i < n-1; i++) {
    add += b[i];
    cur += add;
    if (cur < ans) {
      ans = cur;
      id = i+1;
    }
  }
  cout << ans << " " << id << endl;
  return 0;
}