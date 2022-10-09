#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 1010
int n, m;
int a[maxn];
vector<int> b;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  b.resize(m + 1);
  rep(i, n) cin >> a[i];
  rep1(i, m) cin >> b[i];
  rep(l, n) {
    vector<int> cnt(m + 1, 0);
    for (int r = l; r < n; ++r) {
      cnt[a[r]]++;
      if (cnt == b) {
        cout << "YES";
        return 0;
      }
    }
  }
  
  cout << "NO";

  return 0;
}