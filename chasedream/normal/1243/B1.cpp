#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

string a, b;
int n;

void work() {
  string aa = "", bb = "";
  cin >> n;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      aa += a[i];
      bb += b[i];
    }
  }
  if (aa.length() != 2 || bb.length() != 2) {
    puts("No"); return ;
  } 
  if (aa[0] == aa[1] && bb[0] == bb[1]) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() {
  ios :: sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) work();
  return 0;
}