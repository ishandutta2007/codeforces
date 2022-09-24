#include<iostream>
#include<algorithm>
using namespace std;

int a[10000000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cout << a[(n - 1) / 2];
  return 0;
}