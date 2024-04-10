#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 507;
const int K = 22;

int a[N][N];
int b[N][N];

int dp[N][N][K];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) for (int j = 0; j < m - 1; ++j) cin >> a[i][j];
  for (int i = 0; i < n-1; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];

  if (k % 2 != 0) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << "-1 ";
      }
      cout << '\n';
    }
    exit(0);
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int t = 0; t < K; ++t) dp[i][j][t] = 1e9;
      dp[i][j][0] = 0;
    }
  }

  for (int t = 2; t <= k; t += 2) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i + 1 < n) {
          dp[i][j][t] = min(dp[i][j][t], dp[i+1][j][t-2] + 2*b[i][j]);
        }

        if (i - 1 >= 0) {
          dp[i][j][t] = min(dp[i][j][t], dp[i-1][j][t-2] + 2*b[i-1][j]);
        }

        if (j + 1 < m) {
          dp[i][j][t] = min(dp[i][j][t], dp[i][j+1][t-2] + 2*a[i][j]);
        }

        if (j - 1 >= 0) {
          dp[i][j][t] = min(dp[i][j][t], dp[i][j-1][t-2] + 2*a[i][j-1]);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << dp[i][j][k] << " ";
    cout << '\n'; 
  }


}