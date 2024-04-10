#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;
const int ans[17] = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", ans[n]);
  return 0;
}