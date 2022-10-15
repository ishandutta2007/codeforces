#include <bits/stdc++.h>

using namespace std;

#define int long long

int e2(int x) {return x * x;}
int e3(int x) {return x * x * x;}
int e6(int x) {return x * x * x * x * x * x;}

int getSmaller(int (*func)(int), int x) {
  int cur = 0;
  while (func(cur + 1) <= x) {
    cur++;
  }
  return cur;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);



  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << getSmaller(&e2, x) + getSmaller(&e3, x) - getSmaller(&e6, x) << "\n";
  }
}