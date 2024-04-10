#include <cstdio>
#include <algorithm>

using namespace std;

int kolko[4];
int prost[4] = {2, 3, 5, 7};
char s[40];

void Rastav(int k)
{
  for (int i=0; i<4; i++) {
    for (; !(k % prost[i]); kolko[i]++, k /= prost[i]);
  }
}

void Stavi(int k)
{
  printf("%d", k);
  for (int i=2; i<=k; i++) {
    int tmp = i;
    for (int j=0; j<4; j++) {
      for (; !(tmp % prost[j]); kolko[j]--, tmp /= prost[j]);
    }
  }
}

int main()
{
  int n;

  scanf("%d%s", &n, s);

  for (int i=0; i<n; i++)
    for (int j=2; j<=s[i]-'0'; j++)
      Rastav(j);

  for (int i=3; i>=0; i--)
    for (; kolko[i];)
      Stavi(prost[i]);

  printf("\n");

  return 0;
}