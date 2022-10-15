#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<int> primes;

bool isprime(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

int n;
string s;

int getnum(int i) {return s[i] - '0';}
int getnum(int i, int j) {return getnum(i) * 10 + getnum(j);}
int getnum(int i, int j, int k) {return getnum(i, j) * 10 + getnum(k);}
int getnum(int i, int j, int k, int l) {return getnum(i, j, k) * 10 + getnum(l);}

void print() {
  for (int i = 0; i < n; i++) if (!primes.count(getnum(i))) {cout << "1\n" << getnum(i) << "\n"; return;}
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (!primes.count(getnum(i, j))) {cout << "2\n" << getnum(i, j) << "\n"; return;}
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) if (!primes.count(getnum(i, j, k))) {cout << "3\n" << getnum(i, j, k) << "\n"; return;}

  assert(0);
}

signed main() {
 /// freopen ("input", "r", stdin);

  for (int i = 1; i <= 10000; i++) {
    if (isprime(i)) primes.insert(i);
  }

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    print();
  }

}