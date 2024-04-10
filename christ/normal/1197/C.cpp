#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5+5, MOD = 1e9+7;
int indexof[MAXN];
int main() {
    int n,k;
    scanf ("%d %d",&n,&k);
    vector<int> arr(n), diff;
    for (int i = 0; i < n; i++) {
      scanf ("%d",&arr[i]);
      if (i) diff.push_back(arr[i]-arr[i-1]);
    }
    sort (diff.begin(),diff.end());
    long long tot = 0;
    for (int i = 0; i < n-k; i++) {
      tot += diff[i];
    }
    printf ("%lld\n",tot);
}