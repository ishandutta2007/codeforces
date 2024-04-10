#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

const int MAX = 30005;

vector <int> V[MAX];
int p[MAX];
int minn[MAX], maxx[MAX];

int Rek(int poz, int l)
{
  int ind = l - minn[poz];

  if (V[poz][ind] != -1)
    return V[poz][ind];

  int r=0;
  for (int k=l-1; k<=l+1; k++)
    if (poz + k < MAX && k)
      r = max(r, p[poz+k] + Rek(poz+k, k));
  
  return V[poz][ind] = r;
}

int main()
{
  int n, l;

  scanf("%d%d", &n, &l);

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    p[tmp]++;
  }
  
  for (int i=l, poz=l; i && poz < MAX; i--, poz+=i) {
    for (int j=poz; j<MAX && j<=poz+i-2; j++)
      minn[j] = i;
    if (i == 1)
      for (int j=poz; j<MAX; j++)
        minn[j] = 1;
  }

  for (int i=l, poz=l; poz < MAX; i++, poz += i)
    for (int j=poz; j<MAX && j<=poz+i; j++)
      maxx[j] = i;

  for (int i=l; i<MAX; i++)
    for (int j=0; j<=maxx[i] - minn[i]; j++)
      V[i].push_back(-1);

  int sum=0;
  for (int i=l; i<MAX; i++)
    sum += maxx[i] - minn[i] + 1;

  printf("%d\n", p[l] + Rek(l, l));

  return 0;
}