#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  int s = accumulate(a.begin(), a.end(), 0);
  int k = *max_element(a.begin(), a.end());
  while (k * n - s <= s)
    k++;
  cout << k << endl;
  return 0;
}