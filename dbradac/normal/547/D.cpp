#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 200005;

vector <P> V[2*MAX];
int rje[6*MAX];

void Euler(int node)
{
  for (; !V[node].empty(); ) {
    P tmp = V[node].back();
    V[node].pop_back();
    if (!rje[tmp.Y]) {
      rje[tmp.Y] = 1 + node / MAX;
      Euler(tmp.X);
    }
  }
}

int main()
{
  int n, ind=0;
  char s[10] = " rb";

  scanf("%d", &n);

  for (int i=0; i<n; i++, ind++) {
    int r, s;
    scanf("%d%d", &r, &s);
    V[r].push_back(P(MAX + s, i));
    V[MAX + s].push_back(P(r, i));
  }

  for (int i=0; i<2*MAX; i++) {
    if (V[i].size() & 1) {
      V[0].push_back(P(i, ind));
      V[i].push_back(P(0, ind++));
    }
  }

  for (int i=0; i<2*MAX; i++)
    if (!V[i].empty())
      Euler(i);

  for (int i=0; i<n; i++)
    printf("%c", s[rje[i]]);
  printf("\n");

  return 0;
}