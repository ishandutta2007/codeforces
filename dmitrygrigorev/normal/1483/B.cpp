#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int nxt(set<int> &ms, int x) {
  auto it = ms.lower_bound(x);
  if (it == ms.end()) it = ms.begin();
  return (*it);
}

int prev(set<int> &ms, int x) {
  auto it = ms.lower_bound(x);
  if (it == ms.begin()) it = ms.end();
  it--;
  return (*it);
}

void solve() {

  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  set<int> remaining;
  for (int i = 0; i < n; ++i) remaining.insert(i);
  int cur = 1%n;

  set<int> must;
  for (int i = 0; i < n; ++i) {
    if (__gcd(v[i], v[(i-1+n)%n]) == 1) {
      must.insert(i);
    }
  }

  vector<int> ans;
  while (must.size()) {
    int t = nxt(must, cur);
    ans.pb(t);

    must.erase(must.find(t));
    remaining.erase(remaining.find(t));

    if (must.size()) {
      int R = nxt(must, t);
      int E = nxt(remaining, t);
      if (R == E) must.erase(must.find(R));
    }

    if (!remaining.size()) break;
    int W = nxt(remaining, t);

    cur = (W+1)%n;

    int Z = prev(remaining, W);
    if (__gcd(v[Z], v[W]) == 1) {
      must.insert(W);
    }
  }

  cout << ans.size() << " ";
  for (auto x : ans) cout << x+1 << " ";
  cout << '\n';

}


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}