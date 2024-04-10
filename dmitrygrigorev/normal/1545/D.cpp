#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1007;
int matrix[N][N];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int m, n;
  cin >> m >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
    }
  }

  vector<ll> sums;
  for (int i = 0; i < n; ++i) {
    ll tut = 0;
    for (int j = 0; j < m; ++j) tut += matrix[i][j];
    sums.pb(tut);
  }

  map<ll, int> deltas;
  for (int j = 1; j < n; ++j) deltas[sums[j] - sums[j-1]]++;

  ll need;
  for (auto p : deltas) if (p.y > n/2) need = p.x;
  int spec;

  for (int j = 1; j < n-1; ++j) {
    if (sums[j] - sums[j-1] != need && sums[j+1] - sums[j] != need) {
      spec = j;
      break;
    }
  }

  ll real_sum = sums[spec - 1] + need;
  ll fake_sum = 0;

  for (int i = 0; i < m; ++i) fake_sum += matrix[spec][i];

  int start = 0;
  if (spec <= 2) start = 3;

  ll A = 0, B = 0, C = 0;
  for (int i = 0; i < m; ++i) A += (ll) matrix[start][i] * matrix[start][i];
  for (int i = 0; i < m; ++i) B += (ll) matrix[start+1][i] * matrix[start+1][i];
  for (int i = 0; i < m; ++i) C += (ll) matrix[start+2][i] * matrix[start+2][i];


  ll true_a = A;
  ll true_c = ((C-A) - 2LL*(B-A)) / 2;
  ll true_b = (B - true_c - true_a) / 2;

  ll delta = spec - start;
  ll val = true_a + 2LL*delta*true_b + delta*delta*true_c;

  for (int i = 0; i < m; ++i) {
    ll sq = 0;
    ll to_be = matrix[spec][i] + (real_sum - fake_sum);

    for (int j = 0; j < m; ++j) {
      if (j==i) sq += to_be * to_be;
      else sq += (ll) matrix[spec][j] * matrix[spec][j];
    }

    if (sq == val) {
      cout << spec << " " << to_be << endl;
      break; 
    }

  }


}