#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> R(n);
  for (int i = 0; i < n; ++i) cin >> R[i];
  vector<int> V = R;
  sort(V.begin(), V.end());
  map<int, int> M;
  for (int i = 0; i < n; ++i) M[V[i]] = (i + 1)%n;
  for (int i = 0; i < n; ++i) {
    if (i) cout << ' ';
    cout << V[M[R[i]]];
  }
  cout << endl;
}