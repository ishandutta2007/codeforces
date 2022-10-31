#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

char s[MAX][15], tmp[15];

int Moze(int ind, int poz)
{
  for (int i=poz; i<9; i++) {
    if (s[ind][i] == '?') {
      if (s[ind-1][i] != '9')
        return 1;
    }
    else if (s[ind][i] < s[ind-1][i])
      return 0;
    else if (s[ind][i] > s[ind-1][i])
      return 1;
  }

  return 0;
}

int Rijesi(int ind)
{
  if (!Moze(ind, 0))
    return 0;

  int da=0;
  for (int i=0; i<9; i++) {
    if (s[ind][i] != '?' && s[ind][i] != '0')
      da = 1;
    if (s[ind][i] == '?') {
      if (Moze(ind, i+1) && (da || s[ind-1][i] != '0')) {
        s[ind][i] = s[ind-1][i];
        if (s[ind][i] != '0')
          da = 1;
      }
      else {
        s[ind][i] = s[ind-1][i] + 1;
        for (int j=i+1; j<9; j++)
          if (s[ind][j] == '?')
            s[ind][j] = '0';
        return 1;
      }
    }
    else if (s[ind][i] > s[ind-1][i]) {
      for (int j=i+1; j<9; j++)
        if (s[ind][j] == '?')
          s[ind][j] = '0';
      return 1;
    }
  }

  return 1;
}

int main()
{
  int n;

  scanf("%d", &n);
  
  for (int i=0; i<9; i++)
    s[0][i] = '0';

  for (int i=1; i<=n; i++) {
    scanf("%s", tmp);
    int l = strlen(tmp);
    for (int j=0; j<9-l; j++)
      s[i][j] = '0';
    for (int j=0; j<l; j++)
      s[i][j+9-l] = tmp[j];
  }
  
  int ne=0;
  for (int i=1; i<=n; i++)
    if (!Rijesi(i)) {
      ne = 1;
      break;
    }
  
  if (ne)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i=1; i<=n; i++) {
      int da=0;
      for (int j=0; j<9; j++) {
        if (s[i][j] != '0')
          da = 1;
        if (da)
          printf("%c", s[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}