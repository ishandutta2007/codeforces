#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is(int x) {
  if (x <= 1) {
    return 0;
  } else {
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        return 0;
      }
    }
    return 1;
  }
}

vector<int> v;

void print(int n) {
  for (int i = 0; i < (int) v.size(); i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        int a = v[i];
        int b = v[j];
        int c = v[k];
        int d = n - a - b - c;
        if (d >= 1 && d != a && d != b && d != c) {
          cout << "YES\n";
          cout << a << " " << b << " " << c << " " << d << "\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> primes;
  for (int i = 1; i <= 30; i++) {
    if (is(i)) {
      primes.push_back(i);
    }
  }
  for (auto &it : primes) {
    for (auto &it2 : primes) {
      if (it == it2) {
        break;
      }
      v.push_back(it * it2);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    print(n);
  }
  return 0;
}