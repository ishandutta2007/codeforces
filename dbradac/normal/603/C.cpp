#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<20;

int p[MAX];
int sg[MAX];
int k;

int Sprague(int x)
{
  if (x < MAX)
    return sg[x];

  if (!(k % 2))
    return 1 ^ (x % 2);

  if (x & 1)
    return 0;

  vector <int> V;
  V.push_back(Sprague(x-1));
  V.push_back(Sprague(x / 2));

  for (int i=0;; i++) {
    int da=1;
    for (int j=0; j<(int) V.size(); j++)
      if (V[j] == i)
        da = 0;

    if (da)
      return i;
  }
}

int main()
{
  int rje=0;

  int n;
  scanf("%d%d", &n, &k);

  sg[0] = 0;
  for (int i=0; i<MAX; i++) {
    vector <int> V;
    if (i) {
      V.push_back(sg[i-1]);
      if (!(i % 2)) {
        if (k % 2)
          V.push_back(sg[i/2]);
        else
          V.push_back(0);
      }
    }

    for (int j=0; ; j++) {
      int da=1;
      for (int ii=0; ii<(int) V.size(); ii++)
        if (V[ii] == j)
          da = 0;

      if (da) {
        sg[i] = j;
        break;
      }
    }
  }

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    rje ^= Sprague(tmp);
  }

  printf("%s\n", rje ? "Kevin" : "Nicky");

  return 0;
}