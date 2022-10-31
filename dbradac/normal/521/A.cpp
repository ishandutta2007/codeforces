#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<17, MOD = 1000000007;

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

int Pot(int x, int eksp)
{
  int ret=1;

  for (; eksp; eksp>>=1, x = Mul(x, x))
    if (eksp & 1)
      ret = Mul(ret, x);

  return ret;
}

char s[MAX];
int kolko[4];

int main()
{
  int n;
  char slova[10] = "ACGT";

  scanf("%d%s", &n, s);

  for (int i=0; i<4; i++) {
    int tmp=0;
    for (int j=0; j<n; j++)
      if (s[j] == slova[i])
        tmp++;

    kolko[i] = tmp;
  }

  sort(kolko, kolko+4);
  
  int maxx = kolko[3], br=0;

  for (int i=3; i>=0; i--) {
    if (kolko[i] < maxx)
      break;
    else
      br++;
  }

  printf("%d\n", Pot(br, n));

  return 0;
}