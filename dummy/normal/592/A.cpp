#include <bits/stdc++.h>

using namespace std;

char s[10][10];

int main() {
  for(int i =0; i<8; i++) {
    scanf("%s", s[i]);
  }
  int w = 10, b = 10;
  for(int i = 0; i<8; i++) {
    for(int j = 0; j<8; j++) {
      if(s[i][j] == 'W') {
        bool ok = true;
        for(int k = i-1; k>=0; k--) {
          ok &= (s[k][j] == '.');
        }
        if(ok)
          w = min(w, i);
      }
      if(s[i][j] == 'B') {
        bool ok = true;
        for(int k = i+1; k<8; k++) {
          ok &= (s[k][j] == '.');
        }
        if(ok)
          b = min(b, 7-i);
      }
    }
  }
  puts((b >= w) ? "A" : "B");
  return 0;
}