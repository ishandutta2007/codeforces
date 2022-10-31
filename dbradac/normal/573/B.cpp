#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int p[MAX], dist[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    dist[i] = MAX;
  }


  int maxx = -1;
  for (int i=0; i<n; i++) {
    maxx = max(maxx, i - p[i]);
    dist[i] = min(dist[i], i - maxx);
  }  

  int rje=0;
  int minn = n;
  for (int i=n-1; i>=0; i--) {
    minn = min(minn, i + p[i]);
    dist[i] = min(dist[i], minn - i);
    rje = max(rje, dist[i]);
  }

  printf("%d\n", rje);

  return 0;
}