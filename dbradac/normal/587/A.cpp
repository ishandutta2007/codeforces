#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1000100;

int br[MAX], ima[MAX];
int p[MAX];
int n;

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
      scanf("%d", &p[i]);
      ima[p[i]]++;
  }
  

  int ret=0;
  for (int i=0; i<MAX; i++) {
    int tmp = ima[i] + br[i];
    br[i+1] += tmp / 2;
    ret += tmp % 2;
  }
  
  printf("%d\n", ret);

  return 0;
}