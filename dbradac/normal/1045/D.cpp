#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<17, KOR = 300;

double p[MAX];
double nodes, edges;
int n;
vector <int> V[MAX], Vel[MAX];
double sum_sus[MAX];

void upd(int node, int st) {
  nodes += (1-p[node]) * st;
  for (auto it : Vel[node])
    sum_sus[it] += (1-p[node]) * st;

  double moj_sum=0;
  if ((int) V[node].size() > KOR)
    moj_sum = sum_sus[node];
  else {
    for (auto it : V[node])
      moj_sum += 1-p[it];
  }

  edges += moj_sum * (1-p[node]) * st;
}

int main()
{
  scanf("%d", &n);
  REP(i, n) scanf("%lf", &p[i]);

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].push_back(b);
    V[b].push_back(a);
  }

  REP(i, n)
    for (auto it : V[i])
      if ((int) V[it].size() > KOR)
        Vel[i].push_back(it);

  REP(i, n)
    for (auto it : V[i])
      sum_sus[i] += p[it];

  REP(i, n) {
    nodes += 1-p[i];
    for (auto it : V[i]) {
      edges += (1-p[i]) * (1-p[it]);
    }
  }
  edges /= 2;

  int q;
  scanf("%d", &q);
  for (; q--; ) {
    int node;
    scanf("%d", &node);
    upd(node, -1);
    scanf("%lf", &p[node]);
    upd(node, 1);

    printf("%lf\n", nodes - edges);
  }

  return 0;
}