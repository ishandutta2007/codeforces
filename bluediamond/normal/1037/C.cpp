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

int n, ans = 0;
string s, t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> s >> t;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] != t[i] && s[i + 1] != t[i + 1] && s[i] != s[i + 1]) {
      s[i] = t[i];
      s[i + 1] = t[i + 1];
      ans++;
    }
  }

  for (int i = 0; i < n; i++) {
    ans += (s[i] != t[i]);
  }
  cout << ans << "\n";

  return 0;
}