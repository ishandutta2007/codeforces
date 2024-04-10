#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100100;

typedef long long ll;

struct str {
  int x, y, ind;
};

bool ManjiX(str a, str b)
{
  return a.x < b.x;
}

bool ManjiY(str a, str b)
{
  return a.y < b.y;
}
bool VeciX(str a, str b)
{
  return a.x > b.x;
}

bool VeciY(str a, str b)
{
  return a.y > b.y;
}

str p[4][MAX];
int maknut[MAX];

int Makni(str polje[MAX], int kol)
{
  int ret = 0;

  for (int i=0; i<kol; i++) {
    if (!maknut[polje[i].ind])
      ret++;

    maknut[polje[i].ind]++;
  }

  return ret;
}

int Vrati(str polje[MAX], int kol)
{
  int ret = 0;

  for (int i=0; i<kol; i++) {
    maknut[polje[i].ind]--;
    if (!maknut[polje[i].ind])
      ret--;
  }

  return ret;
}

int main()
{
  int n, mak;

  scanf("%d%d", &n, &mak);

  for (int i=0; i<n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    p[0][i].x = x1 + x2;
    p[0][i].y = y1 + y2;
    p[0][i].ind = i;
    for (int j=1; j<4; j++)
      p[j][i] = p[0][i];
  }

  sort(p[0], p[0] + n, ManjiX);
  sort(p[1], p[1] + n, ManjiY);
  sort(p[2], p[2] + n, VeciX);
  sort(p[3], p[3] + n, VeciY);

  ll rje = 1e18;
  int treb=0;

  for (int i=0; i<=mak; i++) {
    treb += Makni(p[0], i);
    for (int j=0; j<=mak; j++) {
      treb += Makni(p[1], j);      
      for (int k=0; k<=mak; k++) {
        treb += Makni(p[2], k);
        for (int l=0; l<=mak; l++) {
          treb += Makni(p[3], l);

          if (treb <= mak) {
            int razx = p[2][k].x - p[0][i].x;
            int razy = p[3][l].y - p[1][j].y;
            razx = (razx + 1) / 2;
            razy = (razy + 1) / 2;
            razx = max(1, razx);
            razy = max(1, razy);
            rje = min(rje, (ll) razx * razy);
          }

          treb += Vrati(p[3], l);
        }
        treb += Vrati(p[2], k);
      }
      treb += Vrati(p[1], j);
    }
    treb += Vrati(p[0], i);
  }

  cout << rje << endl;

  return 0;
}