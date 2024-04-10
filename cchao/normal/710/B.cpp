#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define F first
#define S second

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  int p = (n - 1) / 2;
  nth_element(a.begin(), a.begin() + p, a.end());
  cout << a[p] << endl;
  return 0;
}