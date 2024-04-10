#include <bits/stdc++.h>
using namespace std;

string s, mm;
char tar[100005]; int l;
int tot = 0;

int main() {
  cin >> s;
  int i, len = s.size();
  for (i = 0; i < len; i++) {
    if (s[i] != 'a') tar[l++] = s[i], tot++;
    if (i + tot >= len - 1)
      break;
  }
  tar[l++] = '\0'; mm = tar;

  if (i + tot >= len) return puts(":(") & 0;
  
  for (int j = i + 1; j < len; j++)
    if (s[j] == 'a') return puts(":(") & 0;
  
  if (mm == s.substr(i + 1)) {
    for (int j = 0; j <= i; j++)
      putchar(s[j]);
    puts("");
  }
  else puts(":(");
  return 0;
}