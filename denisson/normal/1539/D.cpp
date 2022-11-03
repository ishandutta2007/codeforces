#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
ll a[100007];
ll b[100007];


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  vector<int> t; for (int i = 0; i < n; ++i) t.pb(i);

  sort(all(t), [](int w1, int w2) {
    return b[w1] < b[w2];
  });

  ll res = 0;

  int uk = n - 1;
  ll bo = 0;


  for (int i = 0; i < t.size(); ++i) {
    int v = t[i];
    ll need = b[v] - bo;
    while (need > 0) {
      int to = t[uk];
      ll can = min(need, a[to]);
      res += can * 2;
      bo += can;
      a[to] -= can;
      need -= can;
      if (a[to] == 0) uk--;
      if (uk < 0) break;
    }
    if (uk < 0) break;
    bo += a[v];
    res += a[v];
    a[v] = 0;
  }

  cout << res;
}