#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 110;

char s[3][MAX];
int bio[3][MAX];

int Moze(int red, int stup)
{
  return red >= 0 && red <= 2 && (s[red][stup] < 'A' || s[red][stup] > 'Z');
}

int main()
{
  int brt;

  scanf("%d", &brt);

  for (; brt; brt--) {
    memset(s, 0, sizeof s);
    memset(bio, 0, sizeof bio);

    int n;

    scanf("%d%*d", &n);
    for (int i=0; i<3; i++) {
      scanf(" %s", s[i]);
      if (s[i][0] == 's')
        bio[i][0] = 1;
    }

    for (int i=0; i<n; i++) {
      for (int j=0; j<3; j++) {
        if (bio[j][i]) {
          for (int k=-1; k<=1; k++) {
            int nr = j + k;
            int ns = i + 3;
            if (Moze(j, i + 1) && Moze(nr, i + 1) && Moze(nr, i + 2) && Moze(nr, i + 3))
              bio[nr][ns] = 1;
          }
        }
      }
    }

    int da=0;
    for (int i=n; i<MAX; i++)
      for (int j=0; j<3; j++)
        if (bio[j][i])
          da = 1;

    printf("%s\n", da ? "YES" : "NO");
  }

  return 0;
}