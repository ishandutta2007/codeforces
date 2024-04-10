#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

int rje = 0;
int n, k;

int main()
{
  scanf("%d%d", &n, &k);
  int komp=0;

  for (int i=0; i<k; i++) {
    int sz;
    scanf("%d", &sz);
    vector <int> V;
    for (int j=0; j<sz; j++) {
      int tmp;
      scanf("%d", &tmp); tmp--;
      V.push_back(tmp);
    }

    int j=0;
    for (; j<(int) V.size(); j++)
      if (j && V[j-1] + 1 < V[j])
        break;

    if (V[0] > 0)
      j = 1;

    rje += (int) V.size() - j;
    komp += (int) V.size() - j + 1;
  }
  
  printf("%d\n", rje + komp - 1);

  return 0;
}