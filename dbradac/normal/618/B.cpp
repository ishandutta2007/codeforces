#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 55;

int p[MAX][MAX];
int rje[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    scanf("%d", &p[i][j]);

  for (int i=1; i<=n; i++) {
    for (int j=0; j<n; j++) {
      int da = 1;
      if (rje[j])
        continue;
      for (int k=0; k<n; k++)
        if (p[j][k] > i)
          da = 0;

      if (da) {
        rje[j] = i;
        break;
      }
    }
  }

  for (int i=0; i<n; i++)
    printf("%d ", rje[i]);

  return 0;
}