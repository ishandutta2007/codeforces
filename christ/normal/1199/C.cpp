#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<int> freq, psa;
int log2 (int k) {
  return 31 - __builtin_clz(k) + (__builtin_popcount(k) != 1);
}
int main() {
  int n,I,ans = INT_MAX;
  scanf ("%d %d",&n,&I); I *= 8;
  vector<int> arr(n);
  vector<int> a(n);
  for (auto &b : arr) scanf ("%d",&b);
  sort(arr.begin(),arr.end());
  for (int i = 0; i < n; i++) {
    if (i && arr[i] == arr[i-1]) freq.back()++;
    else freq.push_back(1);
  }
  for (int i : freq) {
    if (!psa.empty()) psa.push_back(psa.back());
    else psa.push_back(0);
    psa.back() += i;
  }
  int d = freq.size();
  for (int l = 0,r = 0; l < d; l++) {
      r = max(r,l);
      while (r + 1 < d && log2(r-l+1) * n <= I) ++r;
      if (log2(r-l+1) * n > I) --r;
      ans = min(ans,n-psa[r]+(l ? psa[l-1] : 0));
  }
  printf ("%d\n",ans);
  return 0;
}