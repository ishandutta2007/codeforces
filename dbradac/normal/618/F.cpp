#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<21;

struct str {
  int val, ind;
} p[MAX];

int root[MAX], urank[MAX];

bool operator < (const str &a, const str &b)
{
  return a.val < b.val;
}

int Find(int x)
{
  if (root[x] == -1)
    return x;
  return root[x] = Find(root[x]);
}

void Union(int a, int b)
{
  a = Find(a);
  b = Find(b);

  if (a != b) {
    if (urank[a] > urank[b])
      root[b] = a;
    else if (urank[b] > urank[a])
      root[a] = b;
    else {
      root[b] = a;
      urank[a]++;
    }
  }
}

priority_queue <str> Q[2];
int n;

void Ispis(int x)
{
  int rr = Find(x);
  vector <int> V[2];

  for (int i=0; i<2*n; i++)
    if (Find(i) == rr)
      V[i / n].push_back(i % n + 1);

  for (int i=0; i<2; i++) {
    printf("%d\n", (int) V[i].size());
    for (int j=0; j<(int) V[i].size(); j++)
      printf("%d ", V[i][j]);
    printf("\n");
  }
}


int main()
{
  scanf("%d", &n);

  memset(root, -1, sizeof root);

  for (int i=0; i<2; i++)
    for (int j=0; j<n; j++) {
      int ind = i * n + j;
      scanf("%d", &p[ind].val);
      p[ind].ind = ind;
      Q[i].push(p[ind]);
    }

  for (;;) {
    assert(Q[0].size());
    assert(Q[1].size());

    str t0, t1;
    for (int da=1; da; ) {
      da = 0;
      for (t1 = Q[1].top(); (int) Q[0].size() > t1.val; Q[0].pop(), da=1);
      for (t0 = Q[0].top(); (int) Q[1].size() > t0.val; Q[1].pop(), da=1);
    }

    Union(t0.ind, t1.ind);
    Q[0].pop();
    Q[1].pop();

    if (t0.val == t1.val) {
      Ispis(t0.ind);
      break;
    }
    
    str nov = str { abs(t0.val - t1.val), t0.ind };

    if (t0.val > t1.val)
      Q[0].push(nov);
    else
      Q[1].push(nov);
  }

  return 0;
}