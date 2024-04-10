#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int uns = 0;
  int dos = 0;
  for (int  i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 1) ++uns;
    else ++dos;
  }
  if (dos) {
    cout << 2 << ' ';
    --dos;
  } else {
    while (uns--) {
      cout << 1 << ' ';
    }
    cout << endl;
    return 0;
  }
  if (uns) {
    cout << 1 << ' ';
    --uns;
  } else {
    while (dos--) {
      cout << 2 << ' ';
    }
    cout << endl;
    return 0;
  }
  while (dos--) cout << 2 << ' ';
  while (uns--) cout << 1 << ' ';
  cout << endl;
}