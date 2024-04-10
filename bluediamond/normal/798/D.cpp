#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

const int N = (int) 1e5 + 7;
int n, a[N], b[N], ord[N];
bool take[N];

bool A(int i, int j) {
  return a[i] > a[j];
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;

  cout << n / 2 + 1 << "\n";

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ord[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  sort(ord + 1, ord + n + 1, A);

  if (!(n & 1)) {
    take[ord[n--]] = 1;
  }

  take[ord[1]] = 1;

  for (int i = 2; i <= n; i += 2) {
    if (b[ord[i]] > b[ord[i + 1]]) {
      take[ord[i]] = 1;
    } else {
      take[ord[i + 1]] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    if (take[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";


  return 0;
}