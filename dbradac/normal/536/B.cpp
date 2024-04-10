#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
const int MAX = 1000100, MOD = 1e9 + 7;

int Mul(int a, int b)
{
  return (int) (((ll) a * b) % MOD);
}

char s[MAX];
int z[MAX];
int pref[MAX];
int poz[MAX];
int len;

void CalculateZ()
{
  len = strlen(s);

  z[0] = len;
  int l = 0, r = 0;

  for (int i=1; i<len; i++) {
    if (r >= i && z[i - l] < r - l + 1)
      z[i] = z[i - l];
    else {
      if (r < i) {
        l = r = i;
      }
      for (; r < len && s[r] == s[z[i]]; r++, z[i]++);
    }
  }
}

int main()
{
  int n, m;
  int rje = 1;

  scanf("%d%d%s", &n, &m, s);
  CalculateZ();

  for (int i=0; i<m; i++) {
    scanf("%d", &poz[i]); poz[i]--;
    pref[poz[i]]++;
    pref[poz[i]+len]--;

    if (i && poz[i-1] + len > poz[i] && z[poz[i] - poz[i-1]] < len - (poz[i] - poz[i-1]))
      rje = 0;
  }

  for (int i=0; i<n; i++) {
    if (i)
      pref[i] += pref[i-1];

    if (!pref[i])
      rje = Mul(rje, 26);
  }

  printf("%d\n", rje);
  
  return 0;
}