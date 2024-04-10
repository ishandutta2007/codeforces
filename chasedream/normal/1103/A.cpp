%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

string str;

int main() {
  cin >> str;
  int n = str.size(); str = ' ' + str;
  
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') { //  
      printf("1 %d\n", x + 1);
      x++; if (x >= 4) x -= 4;
    } else {
      printf("4 %d\n", y + 1);
      y += 2; if (y >= 4) y -= 4;
    }
  }
  return 0;
}