#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<20;

int nap[MAX], iza[MAX]; //ako je nap ko je iza, ako je iza ko je nap
int daliz[MAX], dalnap[MAX];
int rje[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    dalnap[a] = 1;
    daliz[b] = 1;
    nap[a] = b;
    iza[b] = a;
  }

  rje[0] = rje[n+1] = 0;
  
  for (int i=1; i<MAX; i++)
    if (!daliz[i] && dalnap[i])
      rje[1] = i;
  
  
  printf("%d ", rje[1]);

  for (int i=1; i<n; i++) {
    rje[i+1] = nap[rje[i-1]];
    printf("%d ", rje[i+1]);
  }
  printf("\n");

  return 0;
}