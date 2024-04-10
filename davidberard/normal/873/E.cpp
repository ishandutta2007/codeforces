#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 3030, LG = 12;

pii a[N];
int b[N];
int d[N];
int n;
int ans[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  for (int i=1; i<n; ++i) {
    b[i] = a[i].first;
  }
  b[n] = d[n] = a[n].first;
  for (int i=1; i<n; ++i) {
    d[i] = b[i]-b[i+1];
  }

  tuple<int, int, int, int, int, int> best(-1, -1, -1, -1, -1, -1);
  for (int i=1; i<n; ++i) {
    int diff1 = d[i];
    if (get<0>(best) > diff1) continue;
    for (int j=i+1; j<n; ++j) {
      if (j-i > 2*i) continue;
      if ((j-i)*2 < i) continue;
      int diff2 = d[j];
      //if (get<0>(best) == diff1 && get<1>(best) > diff2) continue;

      int mx = max(i, j-i);
      int mn = min(i, j-i);

      int lb = (mx+1)/2+j;
      int rb = min(mn*2+j+1, n+1);
      if (lb > n) continue;

      pair<int, int> bb(-1, -1);
      for (int k=lb; k<rb; ++k) {
        bb = max(bb, {d[k], k});
      }
      best = max(best, {diff1, diff2, bb.first, i, j, bb.second});
    }
  }

  for (int i=1; i<=get<3>(best); ++i) {
    ans[a[i].second] = 1;
  }
  for (int i=get<3>(best)+1; i<=get<4>(best); ++i) {
    ans[a[i].second] = 2;
  }
  for (int i=get<4>(best)+1; i<=get<5>(best); ++i) {
    ans[a[i].second] = 3;
  }
  for (int i=get<5>(best)+1; i<=n; ++i) {
    ans[a[i].second] = -1;
  }

  for (int i=1; i<=n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}