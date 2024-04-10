#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e6;
vector<int> diff(MAX, -1);
vector<int> to(MAX, -1);
int n;

int main() {
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j){return a[i] < a[j];});
  int pos = -1;
  int x = -1, y = -1, xx = -1, yy = -1;
  for(int i : id) {
    for(int j : id) {
      if(i == j) break;
      int d = a[i] - a[j];
      if(diff[d] != -1 && diff[d] != j && to[d] != j && diff[d] != i && to[d] != i) {
        x = i;
        y = diff[d];
        xx = j;
        yy = to[d];
        pos = d;
        break;
      }
      diff[d] = i;
      to[d] = j;
    }
    if(x != -1) break;
  }
  if(pos == -1) {
    cout << "NO";
  } else {
    cout << "YES\n";
    cout << x + 1 << " " << yy + 1 << " " << xx + 1 << " " << y + 1;
  }
  return 0;
}