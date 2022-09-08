#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long max1, kol, n, t, i, j, m[111111], m1[111111];
long bin(long l, long r)
{
  long x, y;
  x = m1[i] - m1[r + 1];
  y = m1[i] - m1[r + 2];
  if ((x <= t) && (y > t) || (x <= t) && (r == n)) kol = r - i + 1;
  //printf("%d %d %d %d %d \n", x, y, l, r, kol);
  //getch();
  if ((kol == 0) && (x > t)) bin(l, (l + r) / 2);
  if ((kol == 0) && (x < t)) bin (r, r + (l + r) / 2);
}
int main()
{
  scanf("%d%d", &n, &t);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);
  m1[n] = m[n];
  m1[n + 1] = 0;
  m1[n + 2] = 0;
  for (i = n - 1; i >= 1; i--)
    m1[i] = m1[i + 1] + m[i];
  max1 = -1;
  for (i = 1; i <= n; i++)
  {
    kol = 0;
    if (m[i] == t) kol = 1;
    if (m[i] < t) bin(i, n);
    //printf("%d\n", kol);
    if (kol > max1) max1 = kol;
    if (max1 >= n - i) break;
  }
  printf("%d", max1);
  return 0;
}