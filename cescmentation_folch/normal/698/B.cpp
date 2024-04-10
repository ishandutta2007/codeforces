#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int K[n + 1];
  int root = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> K[i];
    if (i == K[i]) root = i;
  }
  int P[n + 1];
  memset(P, -1, sizeof P);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (P[i] == -1) {
      int x = i;
       while (P[x] == -1) {
	 P[x] = i;
	 if (x == K[x] and root != x) {
	   ++res;
	   K[x] = root;
	}
	 x = K[x];
      }
      if (P[x] == i and x != K[x]) {
	++res;
	if (root == -1) root = x;
	K[x] = root;
      }
    }
  }
  cout << res << endl;
  for (int i = 1; i <= n; ++i) {
    if (i > 1) cout << ' ';
    cout << K[i];
  }
  cout << endl;
}