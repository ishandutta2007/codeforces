#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1005;

char s[MAX][MAX];
int vec[MAX];

int main()
{
  int brred, brstup, rez=0;

  scanf("%d%d", &brred, &brstup);

  for (int i=0; i<brred; i++)
    scanf("%s", s[i]);
  
  for (int j=0; j<brstup; j++) {
    int da=0;
    for (int i=1; i<brred; i++) {
      if (!vec[i] && s[i][j] < s[i-1][j]) {
        rez++;
        da = 1;
        break;
      }
    }
    if (!da)
      for (int i=1; i<brred; i++)
        if (s[i][j] > s[i-1][j])
          vec[i] = 1;
  }

  printf("%d\n", rez);

  return 0;
}