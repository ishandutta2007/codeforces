#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef pair <int, int> P;

const int MAX = 1<<17;

int usebe[MAX];
int bio[MAX];
int used[500100];
vector <P> V[MAX];
vector <int> T;
vector <int> R;

void Euler(int node)
{
  for (; V[node].size(); ) {
    P nn = V[node].back();
    V[node].pop_back();
    if (!used[nn.Y]) {
      used[nn.Y] = 1;
      Euler(nn.X);
      R.push_back(node);
    }
  }
}

int main()
{
  int n, e, uke=0, us=0;

  scanf("%d%d", &n, &e);

  for (int i=0; i<e; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b) {
      usebe[a]++;
      us++;
    }
    else {
      V[a].push_back(P(b, uke));
      V[b].push_back(P(a, uke));
      uke++;
    }
  }
  
  for (int i=1; i<=n; i++)
    if (V[i].size() & 1)
      T.push_back(i);
  
  for (int i=0; i<(int) T.size(); i+=2) {
    int a = T[i], b = T[i+1];
    V[a].push_back(P(b, uke));
    V[b].push_back(P(a, uke));
    uke++;
  }

  if ((uke + us) & 1) {
    usebe[1]++;
    us++;
  }
  
  printf("%d\n", us + uke);

  for (int i=1; i<=n; i++)
    for (int j=0; j<usebe[i]; j++)
      printf("%d %d\n", i, i);

  Euler(1);

  for (int i=0, st=0; i<(int) R.size(); i++, st^=1) {
    int a=R[i], b=R[(i+1) % R.size()];

    if (usebe[a] & 1) {
      usebe[a] = 0;
      st ^= 1;
    }
    
    if (st)
      swap(a, b);
    printf("%d %d\n", a, b);
  }

  return 0;
}