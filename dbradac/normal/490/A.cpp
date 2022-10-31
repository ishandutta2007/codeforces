#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> V[4];

int main()
{
  int n, tmp, r;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &tmp);
    V[tmp].push_back(i+1);
  }
  
  r = min(V[1].size(), min(V[2].size(), V[3].size()));
  printf("%d\n",r);

  for (int i=0; i<r; i++)
    printf("%d %d %d\n", V[1][i], V[2][i], V[3][i]);

  return 0;
}