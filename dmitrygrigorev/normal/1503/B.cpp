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

int matrix[107][107];

int main(){
#ifdef LOCAL
	//freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<pair<int, int> > fa, fb;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i+j)%2 == 0) fa.pb(mp(i, j));
      else fb.pb(mp(i, j));
    }
  }

  while (fa.size() && fb.size()) {
    int x;
    cin >> x;

    if (x == 1) {
      auto p = fb.back();
      fb.pop_back();
      cout << 2 << " " << p.x+1 << " " << p.y+1 << endl;
    }
    else {
      auto p = fa.back();
      fa.pop_back();
      cout << 1 << " " << p.x+1 << " " << p.y+1 << endl;
    }
  }

  while (fa.size()) {
    int x;
    cin >> x;

    int S = 1;
    if (x == 1) S = 3;

    auto p = fa.back();
    fa.pop_back();
    cout << S << " " << p.x+1 << " " << p.y+1 << endl;
  }

  while (fb.size()) {
    int x;
    cin >> x;

    int S = 2;
    if (x == 2) S = 3;

    auto p = fb.back();
    fb.pop_back();
    cout << S << " " << p.x+1 << " " << p.y+1 << endl;
  }



}