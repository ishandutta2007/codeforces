#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define all(x) (x).begin(),(x).end()
void solve () {
  int n,k;
  scanf ("%d %d",&n,&k);
  for (int i = 0; i < n; i++) putchar('a'+i%k);
  putchar(10);
}
int main () {
  int t;
  scanf ("%d",&t);
  while (t--) solve();
  return 0;
}