%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const int N = 200005;
int a[N], b[N];
int p[N];
int n; long long ans = 0LL;
vector <pair <int, int> > m;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    p[b[i]] = i;
  }
  
  for (int i = 1; i <= n; i++) {
    int k;
    for (int j = 1; j <= n; j++) {
      if (b[i] == a[j]) {
        k = j; break;
      }
    }
    int pos = k;
    for (int j = k - 1; j >= i; j--) {
      if (p[a[j]] >= pos) {
        ans += pos - j;
        swap(a[j], a[pos]);
        m.push_back(make_pair(j, pos));
        pos = j;
      }
    }
  }
  
  printf("%lld\n%d\n", ans, m.size());
  for (int i = 0; i < m.size(); i++)
    printf("%d %d\n", m[i].first, m[i].second);  
  return 0;
}