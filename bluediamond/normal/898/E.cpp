#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  int x;
  int dsq;
};

int cc(int x) {
  int r = sqrt(x);
  return min(x - r * r, (r + 1) * (r + 1) - x);
}

bool cmp(T a, T b) {
  if (a.dsq != b.dsq) {
    return a.dsq < b.dsq;
  } else {
    return a.x < b.x;
  }
}

const int N = 200000 + 7;
int n;
ll ans;
T a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
    a[i].dsq = cc(a[i].x);
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n / 2; i++) {
    ans += a[i].dsq;
  }
  for (int i = n / 2 + 1; i <= n; i++) {
    if (a[i].x == 0) {
      ans += 2;
    } else {
      ans += (a[i].dsq == 0);
    }
  }
  cout << ans << "\n";
}