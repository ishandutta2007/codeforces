#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> v(n*k);
  for (auto &x : v) {
    cin >> x;
    x--;
  }

  int can = (n + (k - 2)) / (k - 1);
  vector<pair<int, int> > ans(n, mp(-1, -1));
  int now = 0;

  vector<int> pos(n, -1);
  vector<bool> used(n, false);

  for (int i = 0; i < n*k; ++i) {

    if (used[v[i]]) continue;

    if (pos[v[i]] == -1) pos[v[i]] = i;
    else {
      ans[v[i]] = mp(pos[v[i]], i);
      pos[v[i]] = -1;
      used[v[i]] = true;
      now++;

      if (now % can == 0) pos.assign(n, -1);
    }
  }

  for (int i = 0; i < n; ++i) cout << ans[i].x + 1 << " " << ans[i].y + 1 << '\n'; 
  

}