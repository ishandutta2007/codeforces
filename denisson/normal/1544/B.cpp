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

int a[22][22];

void solve() {
  int n, m;
  cin >> n >> m;
//  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0;

  if (n % 2 == 1 && m % 2 == 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == 0 || i == n - 1) {
          cout << (j + 1) % 2;
        } else if (j == 0 || j == m - 1) {
          cout << (i + 1) % 2;
        } else cout << 0;

      }
      cout << '\n';
    }
    return;
  }

  if (n % 2 == 0 && m % 2 == 1) {

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == 0 || i == n - 1) {
          cout << (j + 1) % 2;
        } else if (i != n - 2 && (j == 0 || j == m - 1)) {
          cout << (i + 1) % 2;
        } else cout << 0;

      }
      cout << '\n';
    }


    return;
  }

  if (n % 2 == 1 && m % 2 == 0) {

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
       

        if (j == 0 || j == m - 1) {
          cout << (i + 1) % 2;
        } else if (j != m - 2 && (i == 0 || i == n - 1)) {
          cout << (j + 1) % 2;
        } else cout << 0;


      }
      cout << '\n';
    }


    return;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
     
      if (i == 0 && j == 0 || i == 0 && j == m - 1 || i == n - 1 && j == 0 || i == n - 1 && j == m - 1) {
        cout << 1;
      } else 

      if (i != n - 2 && (j == 0 || j == m - 1)) {
        cout << (i + 1) % 2;
      } else if (j != m - 2 && (i == 0 || i == n - 1)) {
        cout << (j + 1) % 2;
      } else cout << 0;


    }
    cout << '\n';
  }



}


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt; cin >> tt;
  while (tt--) {
    solve();
  cout << "\n";
  }

}