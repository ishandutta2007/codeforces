#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 305;

int n, t;
int p[MAX];
int rje[MAX], pred[MAX], kraj[MAX];
int kol[MAX];

void Prednji()
{
  for (int i=0; i<n*n; i++) {
    int tmp = p[i % n];
    int maxx = 0;
    for (int j=0; j<=tmp; j++)
      maxx = max(maxx, pred[j]);

    pred[tmp] = maxx + 1;
  }

  for (int i=1; i<MAX-2; i++)
    pred[i] = max(pred[i-1], pred[i]);

  for (int i=0; i<MAX; i++)
    pred[i] += (t - 2 * n) * kol[i];
}

void Kraj()
{
  for (int i=n*n-1; i>=0; i--) {
    int tmp = p[i % n];
    int maxx = 0;
    for (int j=tmp; j<MAX; j++)
      maxx = max(maxx, kraj[j]);

    kraj[tmp] = maxx + 1;
  }

  for (int i=MAX-2; i>=0; i--)
    kraj[i] = max(kraj[i], kraj[i+1]);
}

void Rijesi()
{
  for (int i=0; i<n*t; i++) {
    int tmp = p[i % n];
    int maxx=0;
    for (int j=0; j<=tmp; j++)
      maxx = max(maxx, rje[j]);

    rje[tmp] = maxx + 1;
  }

  for (int i=1; i<MAX-2; i++)
    rje[i] = max(rje[i-1], rje[i]);
}

int main()
{
  scanf("%d%d", &n, &t);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    kol[p[i]]++;
  }

  if (t <= 2 * n) {
    Rijesi();
    printf("%d\n", rje[300]);
    return 0;
  }

  Prednji();
  Kraj();

  int ret=0;
  for (int i=0; i<MAX; i++)
    ret = max(ret, pred[i] + kraj[i]);
  
  printf("%d\n", ret);

  return 0;
}