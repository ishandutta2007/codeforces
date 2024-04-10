#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5010;
int A[MAXN];
int B[MAXN];
int R[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = 0; i < n; ++i) {
    int m = 0;
    int c = 0;
    memset(B, 0, sizeof B);
    for (int j = i; j < n; ++j) {
      ++B[A[j]];
      if (B[A[j]] > m or (B[A[j]] == m and A[j] < c)) {
	c = A[j];
	m = B[A[j]];
      }
      ++R[c];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i > 1) cout << ' ';
    cout << R[i];
  }
  cout << endl;
}