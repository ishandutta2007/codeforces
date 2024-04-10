#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5+5, MOD = 1e9+7;
int indexof[MAXN];
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> arr(n),srt(n);
    for (int i = 0; i < n; i++) {
      scanf ("%d",&arr[i]);
      srt[i] = arr[i];
      indexof[arr[i]] = i;
    }
    sort(srt.begin(),srt.end(),greater<int>());
    int l = indexof[srt[0]]-1, r = l+2;
    for (int i = 1; i < n; i++) {
      if (indexof[srt[i]] < l || indexof[srt[i]] > r) return !printf ("nO\n");
      l = min(l,indexof[srt[i]]-1);
      r = max(r,indexof[srt[i]]+1);
    }
    return !printf ("YeS\n");
}