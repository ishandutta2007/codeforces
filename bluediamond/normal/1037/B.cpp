#include <iostream>

using namespace std;

typedef long long ll;
const int ORDLIM = (int) 1e6;
int auxord[ORDLIM];
void ord(int a[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    ord(a, l, m);
    ord(a, m + 1, r);
    int p1 = l, p2 = m + 1;
    for (int j = l; j <= r; j++) {
      int t = 0;
      if (p1 == m + 1) {
        t = 2;
      }
      if (p2 == r + 1) {
        t = 1;
      }
      if (t == 0) {
        if (a[p1] < a[p2]) {
          t = 1;
        } else {
          t = 2;
        }
      }
      if (t == 1) {
        auxord[j] = a[p1++];
      } else {
        auxord[j] = a[p2++];
      }
    }
    for (int j = l; j <= r; j++) {
      a[j] = auxord[j];
    }
  }
}
#define name(a) #a

void printvec(int a[], int l, int r) {
  cout << name(a) << " = {";
  for (int j = l; j <= r; j++) {
    cout << a[j];
    if (j != r) {
      cout << ", ";
    }
  }
  cout << "}\n";
}

void readvec(int a[], int n) {
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
}

///############################################################################################################################################################

const int N = (int) 2e5 + 7;
int n, s;
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> s;
  readvec(a, n);
  ord(a, 1, n);
  ll ans = 0;
  ans += abs(a[n / 2 + 1] - s);

  for (int i = 1; i < n / 2 + 1; i++) {
    if (a[i] > s) {
      ans += a[i] - s;
    }
  }

  for (int i = n / 2 + 2; i <= n; i++) {
    if (a[i] < s) {
      ans += s - a[i];
    }
  }

  cout << ans << "\n";

  return 0;
}