#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

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

int TWO = bp(2, mod - 2);
int SIX = bp(6, mod - 2);
int THREE = bp(3, mod - 2);

const int N = 1000007;
int ways[N][4];

int ga(int i, int j) {
  int A = ways[i][j];
  add(A, -ways[i-1][j]);
  return A;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  ways[0][0] = 1;
  for (int i = 1; i < N; ++i) {


    add(ways[i][0], ways[i-1][0]);
    add(ways[i][1], ways[i-1][0]);
    add(ways[i][1], ways[i-1][1]);
    add(ways[i][1], ways[i-1][2]);

    for (int d1 = 0; d1 <= 2; ++d1) {
      for (int d2 = 0; d2 <= 2; ++d2) {
        if (d1 != d2) {
          add(ways[i][2], mult(TWO, mult(ways[i-1][d1], ways[i-1][d2])));
        }
        else {
          add(ways[i][2], mult(TWO, mult(ways[i-1][d1], (ways[i-1][d2] + 1))));
        }
      } 
    }
  }

  for (int i = 1; i < N; ++i) {
    for (int d1 = 0; d1 <= 2; ++d1) {
      for (int d2 = 0; d2 <= 2; ++d2) {
        for (int d3 = 0; d3 <= 2; ++d3) {

          if (d1 > d2 || d2 > d3 || d1 > d3) continue;

          int W;

          if (d1 == d2 && d1 == d3) {
            int d = ways[i-1][d1];
            W = mult(SIX, mult(d, mult(d + 1, d + 2)));
          }
          else if (d1 == d2) {
            int d = ways[i-1][d1];
            d = mult(d, d + 1);
            W = mult(TWO, mult(d, ways[i-1][d3]));
          }
          else if (d2 == d3) {
            int d = ways[i-1][d3];
            d = mult(d, d + 1);
            W = mult(TWO, mult(d, ways[i-1][d1]));
          }
          else {
            W = mult(ways[i-1][d1], mult(ways[i-1][d2], ways[i-1][d3]));
          }

          add(ways[i][3], W);
        }
      } 
    }
  }

  int n;
  cin >> n;

  int ans = ga(n, 1);
  add(ans, ga(n, 2));
  add(ans, ga(n, 3));

  ans = mult(2, ans);
  add(ans, -1);

  for (int take = 1; take + 1 < n; ++take) {
    int L = ga(n - 1 - take, 1);
    add(L, ga(n - 1 - take, 2));
    add(L, -1);

    int R = ga(take, 2);
    add(ans, mult(L, R));

    //cout << take << " " << L << " " << R << endl;

  }

  cout << ans;



}