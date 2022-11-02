#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int l, r, p, cnt[N], all[N];

int main() {
  long double a;
  a = 0;
  scanf("%d%d", &n, &p);
  for(int i = 0; i<n; i++) {
    scanf("%d%d", &l, &r);
    cnt[i] = r/p - (l-1)/p, all[i] = r-l + 1;
    a += (long double)4000*cnt[i]/all[i];
  }
  for(int i = 0; i<n; i++) {
    a -= (long double)2000*((long double)cnt[i]/all[i])*((long double)cnt[(i+1) % n]/all[(i+1) % n]);
  }
  cout << fixed << setprecision(13) << a  << endl;
  return 0;
}