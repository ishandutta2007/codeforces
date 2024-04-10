#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2000 + 5;

int n;
int v[N];
int add[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  for (int i = n; i >= 1; i--) {
    while ((v[i] + add[i]) % n != i - 1) {
      add[i]++;
    }
    for (int j = 1; j <= i; j++) {
      v[j] += add[i];
    }
  }

  cout << n + 1 << "\n";

  for (int i = 1; i <= n; i++) {
    cout << "1 " << i << " " << add[i] << "\n";
  }

  cout << "2 " << n << " " << n << "\n";

  return 0;
}