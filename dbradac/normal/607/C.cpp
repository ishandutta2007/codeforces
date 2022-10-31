#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<21;

char slova[5] = "NESW";
char s[MAX];
char a[MAX], b[MAX];
int z[MAX];
int n;
int dulj;

void CalculateZ()
{
  int ll=0, rr=0;
  z[0] = dulj;

  for (int i=1; i<dulj; i++) {
    if (i > rr) {
      ll = rr = i;
      for (; rr < dulj && s[rr-ll] == s[rr]; rr++);
      z[i] = rr-ll;
      rr--;
    }
    else {
      int raz = i-ll;
      if (z[raz] < rr-i+1)
        z[i] = z[raz];
      else {
        ll = i;
        while (rr < dulj && s[rr-ll] == s[rr]) rr++;
        z[i] = rr-ll;
        rr--;
      }
    }
  }
}

int main()
{
  scanf("%d", &n); n--;
  scanf("%s%s", a, b);

  for (int i=0; i<n; i++)
    for (int j=0; j<4; j++)
      if (a[i] == slova[j])
        s[n-i-1] = slova[(j + 2) % 4];

  for (int i=0; i<n; i++)
    s[n+i] = b[i];

  dulj = 2 * n;
  CalculateZ();

  int ne = 0;
  for (int i=n; i<2*n; i++)
    if (i + z[i] == 2 * n)
      ne = 1;

  printf("%s\n", ne ? "NO" : "YES");

  return 0;
}