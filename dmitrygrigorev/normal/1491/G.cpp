#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
    x--;
  }

  vector<vector<int> > cycles;
  vector<bool> used(n, false);

  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    vector<int> cycle;

    int T = i;
    while (true) {
      cycle.pb(T);
      used[T] = true;
      T = v[T];
      if (used[T]) break;
    }
    if (cycle.size() > 1) cycles.pb(cycle);
  }

  vector<pair<int, int> > ans;

  while (cycles.size() >= 2) {
    auto A = cycles.back();
    cycles.pop_back();

    auto B = cycles.back();
    cycles.pop_back();

    if (A.size() > B.size()) swap(A, B);

    for (int i = 0; i < A.size(); ++i) {
      ans.pb(mp(A[i], B[A.size() - i - 1]));
    }

    for (int i = A.size(); i < B.size(); ++i) {
      ans.pb(mp(A[0], B[i]));
    }

    ans.pb(mp(A[0], B[0]));

    for (int i = 1; i < A.size(); ++i) {
      ans.pb(mp(A[i], B[A.size() - i]));
    }

  }

  if (cycles.size() && cycles[0].size() == 2) {
    auto A = cycles[0];

    vector<bool> used(n, false);
    for (auto x : A) used[x] = true;
    int W = -1;

    for (int i = 0; i < n; ++i) if (!used[i]) W = i;

    ans.pb(mp(W, A.back()));
    for (int i = 0; i+1 < A.size(); ++i) {
      ans.pb(mp(A[i], W));
    }
    ans.pb(mp(W, A.back()));

  }

  else if (cycles.size()) {
    auto A = cycles[0];
    ans.pb(mp(A[0], A.back()));
    for (int i = 0; i < A.size()-3; ++i) {
      ans.pb(mp(A[i+1], A.back()));
    }
    ans.pb(mp(A[0], A[A.size() - 2]));
    ans.pb(mp(A[A.size() - 1], A[A.size() - 2]));
    ans.pb(mp(A[A.size() - 1], A[0]));
  }

  cout << ans.size() << '\n';
  for (auto x : ans) {
    int a = x.x, b = x.y;
    if (a > b) swap(a, b);
    cout << a+1 << " " << b+1 << endl;
  }

}