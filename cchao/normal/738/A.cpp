#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; int n; cin >> n >> s;
  for (int i = 0; i < s.size(); ) {
    if (i + 2 < s.size() && s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
      i += 3;
      while (i + 1 < s.size() && s[i] == 'g' && s[i + 1] == 'o') i += 2;
      printf("***");
    } else putchar(s[i++]);
  }
  puts("");
  return 0;
}