#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1005;

int sito[MAX];
vector <int> V;

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=2; i<=n; i++) {
    if (!sito[i]) {
      for (int j=2*i; j<=n; j+=i)
        sito[j] = 1;
            
      for (int tmp=i; tmp<=n; tmp*=i)
        V.push_back(tmp);
    }
  }

  printf("%d\n", (int) V.size());
  for (int i=0; i<(int) V.size(); i++)
    printf("%d ", V[i]);
  printf("\n");

  return 0;
}