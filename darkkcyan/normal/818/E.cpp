#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n;)
#define sz(v) ((int)v.size())

#define maxn 101010
#define maxnln 40

vector<ii> fac(llong num) {
  map<int, int> ans;
  llong t = num;
  for (llong i = 2; i * i <= t; ++i) {
    int cnt = 0;
    while (num % i == 0) {
      ++cnt;
      num /= i;
    }
    if (cnt) ans[i] = cnt;
  }
  if (num > 1) ans[num]++;
  return vector<ii>(ans.begin(), ans.end());
}

int n;
llong k;
vector<ii> fk;
int cnt[maxn][maxnln] = {0};

bool divable(int l, int r) {
  if (l > r) return 0;
  rep(i, sz(fk)) {
    int c = cnt[r][i] - (l > 0 ? cnt[l - 1][i] : 0);
    //clog << l << ' ' << r << ' ' << i << ' ' << c << endl;
    if (c < fk[i].yy) return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  fk = fac(k);
  rep(i, n) {
    llong x; cin >> x;
    rep(f, sz(fk)) {
      if (i > 0) cnt[i][f] = cnt[i - 1][f];
      while (x % fk[f].xx == 0) {
        ++cnt[i][f];
        x /= fk[f].xx;
      }
    }
  }

  llong ans = 0;
  rep(i, n + 1) {
    int l = 0, r = n - i;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (divable(i, n - 1 - mid)) l = mid;
      else r = mid - 1;
    }
    if (divable(i, n - 1 - l)) ans += l + 1;
  }
  cout << ans;
  return 0;
}