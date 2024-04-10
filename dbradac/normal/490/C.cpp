#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<20;

char s[MAX];
ll pota[MAX], potb[MAX];
int n;

int Ispis(int poz)
{  
  if (s[poz] == '0')
    return 0;

  printf("YES\n");

  for (int i=0; i<poz; i++)
    printf("%c", s[i]);
  printf("\n");

  for (int i=poz, da=0; i<n; i++) {
    if (s[i] != '0')
      da = 1;
    if (da)
      printf("%c", s[i]);
  }
  printf("\n");

  return 1;
}

int main()
{
  int a, b;
  ll osta=0, ostb=0;

  scanf("%s%d%d",s, &a, &b);
  n = (int) strlen(s);
  
  pota[0] = potb[0] = 1;
  for (int i=1; i<MAX; i++) {
    pota[i] = (pota[i-1] * 10) % a;
    potb[i] = (potb[i-1] * 10) % b;
  }

  osta = (s[0] - '0') % a;
  
  for (int i=n-1; i; i--)
    ostb = (ostb + (s[i] - '0') * potb[n-i-1]) % b;

  int da=0;
  for (int i=1; i<n; i++) {
    if (!osta && !ostb) {
      da = Ispis(i);
      if (da)
        break;
    }
    osta = (10 * osta + s[i] - '0') % a;
    ostb = ((ostb - potb[n-i-1] * (s[i] - '0')) % b + b) % b;
  }

  if (!da)
    printf("NO\n");

  return 0;
}