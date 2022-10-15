#include <bits/stdc++.h>

using namespace std;

struct Numar {
  long long x;
  int v2;
  int v3;
};

bool cmp(Numar a, Numar b) {
  if (a.v3 == b.v3) {
    return a.v2 < b.v2;
  } else {
    return a.v3 > b.v3;
  }
}

int n;
Numar a[107];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x, copie, v2 = 0, v3 = 0;
    cin >> x;
    copie = x;
    while (copie % 2 == 0) {
      copie /= 2;
      v2++;
    }
    while (copie % 3 == 0) {
      copie /= 3;
      v3++;
    }
    a[i].x = x;
    a[i].v2 = v2;
    a[i].v3 = v3;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    cout << a[i].x << " ";
  }
  cout << "\n";
}