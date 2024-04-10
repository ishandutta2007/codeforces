#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 201010
int n, q;
llong a[maxn] = {0};

llong gets(int l, int r) { return a[r] - a[l - 1]; }
int getpos(int lastpos, llong arr, llong& arrhit) {
  if (lastpos == n + 1) return n + 1;
  int l = lastpos, r = n + 1;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (gets(lastpos, mid) - arrhit > arr) r = mid;
    else l = mid + 1;
  }
  arrhit = arr - (gets(lastpos, l - 1) - arrhit);
  return l;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  rep1(i, n) cin >> a[i], a[i] += a[i - 1];
  llong arrhit = 0;
  int pos = 1;
  while (q--) {
    llong arr; cin >> arr;
    pos = getpos(pos, arr, arrhit);
    if (pos == n + 1) pos = 1, arrhit = 0;
    cout << n - pos + 1 << '\n';
    //clog << pos << ' ' << arrhit << endl;
  }

  return 0;
}