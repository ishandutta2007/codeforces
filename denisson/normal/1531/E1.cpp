#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

string s;
int v = 0;

int n = 16;
vector<int> g[100007];
int a[100007];
int b[100007];

void mergesort(int l, int r) {
  if (r - l <= 1) return;
  int m = (l + r) >> 1;
  mergesort(l, m);
  mergesort(m, r);
  int i = l;
  int j = m;
  int k = l;
  while (i < m && j < r) {
    if (s[v++] == '0') {
      g[a[i]].pb(a[j]);
      b[k] = a[i];
      i++;
    } else {
      g[a[j]].pb(a[i]);
      b[k] = a[j];
      j++;
    }
    k++;
  }
  while (i < m) {
    b[k] = a[i];
    i++;
    k++;
  }
  while (j < r) {
    b[k] = a[j];
    j++;
    k++;
  }
  for (int i = l; i < r; ++i) a[i] = b[i];
}

int ans[100007];
int was[100007];
vector<int> ord;

void dfs(int v) {
  was[v] = 1; 
  for (int to : g[v]) if (!was[to]) dfs(to);
  ord.pb(v);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> s;
  for (int i = 0; i < s.size(); ++i) a[i] = i;

  mergesort(0, n);

  // for (int i = 0; i < n; ++i) for (int j : g[i]) cout << i << ' ' << j << endl;
  for (int i = 0; i < n; ++i) if (!was[i]) dfs(i);
  reverse(all(ord));
  for (int i = 0; i < n; ++i) ans[ord[i]] = i;
  cout << n << endl;
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << ' ';
}