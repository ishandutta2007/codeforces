#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 101010

int n;
llong a[maxn], b[maxn];
llong ans[maxn], addi[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  rep1(i, n) cin >> b[i];
  rep1(i, n) b[i] += b[i - 1];
  rep1(i, n) {
    int l = i, r = n + 1;
    while (l < r) {
      int mid = (l + r) / 2;
      llong s = b[mid] - b[i - 1];
      if (s > a[i]) r = mid;
      else l = mid + 1;
    }
    addi[i]++;
    addi[l]--;
    ans[l] += a[i] - (b[l - 1] - b[i - 1]);
    //clog << i << ' ' << l << ' ' << a[i] - (b[l - 1] - b[i - 1]) << endl;
  }
  rep1(i, n) {
    addi[i] += addi[i - 1];
    cout << ans[i] + addi[i] * (b[i] - b[i - 1]) << ' ';
  }


  return 0;
}