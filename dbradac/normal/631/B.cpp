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

const int MAX = 5005;

P r[MAX], s[MAX];

int main()
{
  int brred, brstup, q;

  scanf("%d%d%d", &brred, &brstup, &q);

  for (int i=0; i<q; i++) {
    int st, ind, val;
    scanf("%d%d%d", &st, &ind, &val);
    if (st == 1)
      r[ind] = P(i+1, val);
    else
      s[ind] = P(i+1, val);
  }

  for (int i=1; i<=brred; i++) {
    for (int j=1; j<=brstup; j++)
      printf("%d ", max(r[i], s[j]).Y);
    printf("\n");
  }

  return 0;
}