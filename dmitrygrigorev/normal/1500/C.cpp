#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1507;
int a[N][N];
int b[N][N];

void solve(int n, int m) {

  if (n == 1) {
    cout << "0\n";
    exit(0);
  }

  vector<int> order;
  vector<bool> bad(n-1, true);

  int B = n-1;

  vector<int> rem(m, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n-1; ++j) {
      if (b[j][i] > b[j+1][i]) rem[i]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < m; ++i) if (rem[i] == 0) q.push(i);

  while (q.size() && B) {
    int W = q.front();
    q.pop();

    order.pb(W);

    for (int j = 0; j < n-1; ++j) {
      if (!bad[j]) continue;
      if (b[j][W] < b[j+1][W]) {
        bad[j] = false;
        B--;
        for (int dr = 0; dr < m; ++dr) {
          if (b[j][dr] > b[j+1][dr]) {
            rem[dr]--;
            if (rem[dr] == 0) q.push(dr);
          }
        }
      }
    }

  }

  if (B) {
    cout << -1;
    exit(0);
  }

  if (order.back() == m-1) order.pop_back();
  reverse(all(order));
  cout << order.size() << '\n';
  for (auto x : order) cout << x+1 << " ";

}

int main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("L_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> b[i][j];
  }

  vector<vector<int> > A, B;
  for (int i = 0; i < n; ++i) {
    vector<int> C, D;
    for (int j = 0; j < m; ++j) {
      C.pb(a[i][j]);
      D.pb(b[i][j]);
    }
    C.pb(i);
    D.pb(i);
    A.pb(C);
    B.pb(D);
  }

  sort(all(A));
  sort(all(B));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (A[i][j] != B[i][j]) {
        cout << -1;
        exit(0);
      }
    }

    b[B[i][m]][m] = A[i][m];
  }

  solve(n, m+1);
}