#include <bits/stdc++.h>

using namespace std;

int nx[] = {1, 3, 0, 2};

char s[3][5];
int ans[3];

int main() {
  for(int i = 0; i<2; i++)
  scanf("%s%s", s[i], s[i]+2);
  for(int i = 0; i<2; i++)
    for(int j = 0; j<4; j++) if(s[i][j] == 'X') {
      for(int k = nx[j]; k< 4; k = nx[k]) if(s[i][k] == 'A') {
        k = nx[k];
        if(s[i][k] == 'X')
          k = nx[k];
        ans[i] = s[i][k] - 'A';
        break;
      }
      break;
    }
  if(ans[0] == ans[1])
    puts("YES");
  else
    puts("NO");
  return 0;
}