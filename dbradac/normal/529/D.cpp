#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int fen[MAX];
int rje[MAX];
int p[MAX];

void Stavi(int pos, int val)
{
  for (pos++; pos < MAX; pos += pos & -pos)
    fen[pos] += val;
}

int Vrati(int pos)
{
  int ret=0;

  if (pos < 0)
    return 0;
  for (pos++; pos; pos -= pos & -pos)
    ret += fen[pos];

  return ret;
}

int main()
{
  int n, m, vr, uspio=0, ind=1;

  scanf("%d%d%d", &n, &m, &vr);

  for (int i=0; i<n; i++) {
    int h, min, sec;
    scanf("%d:%d:%d", &h, &min, &sec);
    int t = 3600 * h + 60 * min + sec;
    p[i] = t;
  }

  sort(p, p+n);
  
  for (int i=0; i<n; i++) {
    int tmp = Vrati(p[i]) - Vrati(p[i] - vr);
    if (tmp < m) {
      rje[i] = ind++;
      if (tmp == m - 1)
        uspio = 1;
      Stavi(p[i], 1);
    }
    else {
      rje[i] = rje[i-1];
      Stavi(p[i-1], -1);
      Stavi(p[i], 1);
    }
  }
  
  if (!uspio)
    printf("No solution\n");
  else {
    printf("%d\n", ind-1);
    for (int i=0; i<n; i++)
      printf("%d\n", rje[i]);
  }

  return 0;
}