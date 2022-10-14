#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(all(a));
  int lo = a[n - 1] - (n - 1);
  vector<int> v(2 * n);
  int cnt = 0;
  for (int i = 0; i < 2 * n; i++) {
    while (cnt != n && a[cnt] <= lo + i)
      cnt++;
    v[i] = ((lo + i - cnt) % p + p) % p;
  }
  vector<int> ans;
  vector<int> con(p);
  for (int x = lo; x < lo + n - 1; x++)
    con[v[x - lo]]++;
  for (int x = lo; x < lo + n; x++) {
    con[v[x + n - 1 - lo]]++;
    if (!con[((x % p) + p) % p])
      ans.pb(x);
    con[v[x - lo]]--;
  }
  cout << ans.size() << endl;
  for (int i : ans)
    cout << i << ' ';
  return 0;
}