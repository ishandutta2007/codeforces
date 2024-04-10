#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<12;

int rje=0;
int val[MAX];
int p[MAX];
int n;


void Rek(int ind)
{
  if (ind >= (1<<n))
    return;
  
  Rek(2*ind+0);
  Rek(2*ind+1);

  int a = val[2*ind+0] + p[2*ind+0];
  int b = val[2*ind+1] + p[2*ind+1];

  if (a > b)
    swap(a, b);

  rje += b - a;
  val[ind] = b;
}

int main()
{
  scanf("%d", &n);

  for (int i=2; i<(1<<(n+1)); i++)
    scanf("%d", &p[i]);
  
  Rek(1);

  printf("%d\n", rje);

  return 0;
}