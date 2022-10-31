#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1005;

struct str {
  int ind;
  P val;
};

bool operator < (str a, str b)
{
  return a.val < b.val;
}

vector <str> V[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    V[y/1000].push_back(str {i + 1, P(x, y) });
  }

  for (int i=0; i<MAX; i++) {
    sort(V[i].begin(), V[i].end());
    if (i & 1)
      for (int j=0; j<(int) V[i].size(); j++)
        printf("%d ", V[i][j].ind);
    else
      for (int j=(int) V[i].size()-1; j>=0; j--)
        printf("%d ", V[i][j].ind);
  }

  return 0;
}