#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e7, MOD = 1e9+7;
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) {
      int n;
      scanf ("%d",&n);
      vector<int> a(n);
      for (auto &au : a) scanf ("%d",&au);
      sort (a.begin(),a.end(),greater<int>());
      printf ("%d\n",min(a[1]-1,n-2));
    }
    return 0;
}