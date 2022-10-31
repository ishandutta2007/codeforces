#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19;
const int POC = 5e8;

vector <int> V[MAX];
int n, m;
int rje[MAX];
int ima[MAX];
map <int, int> M[MAX];

void nope() {
  printf("NO\n");
  exit(0);
}

void check() {
  map <int, int> Cnt;  
  
  REP(i, n) Cnt[rje[i]]++;

  REP(i, n) {
    for (auto it : V[i])
      if (abs(rje[it] - rje[i]) > 1) nope();

    int tmp = (Cnt[rje[i]] + Cnt[rje[i]-1] + Cnt[rje[i]+1]);
    if (tmp != (int) V[i].size() + 1) nope();
  }
}

void solve(int node, int a, int b) {
  rje[node] = POC;
  rje[a] = POC - 1;
  rje[b] = POC + 1;

  for (auto it : V[node]) {
    if (it == a || it == b) continue;

    int ima_a = M[it][a], ima_b = M[it][b];
    if (ima_a && ima_b) rje[it] = POC;
    if (ima_a && !ima_b) rje[it] = rje[a];
    if (!ima_a && ima_b) rje[it] = rje[b];
    if (!ima_a && !ima_b) nope();
  }

  queue <int> Q;

  for (auto it : V[node])
    Q.push(it);

  for (; !Q.empty(); ) {
    int tmp = Q.front(); Q.pop();
    for (auto it : V[tmp]) {
      if (!rje[it]) {
	rje[it] = rje[tmp];
	if (rje[it] < POC) rje[it]--;
	else rje[it]++;

	Q.push(it);
      }
    }
  }

  check();

  printf("YES\n");
  REP(i, n) printf("%d ", rje[i]);
  printf("\n");

  exit(0);
}

int main()
{
  scanf("%d%d", &n, &m);

  if (m == (ll) n * (n - 1) / 2) {
    printf("YES\n");
    REP(i, n) printf("1 ");
    printf("\n");
    return 0;
  }

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
    M[a][b] = M[b][a] = 1;
  }

  REP(i, n) {
    if ((int) V[i].size() < n-1) {
      for (auto it : V[i])
	ima[it] = 1;

      for (auto it : V[i])
	for (auto e : V[it])
	  if (e != i && !ima[e]) solve(it, i, e);
    }
  }

  assert(0);

  return 0;
}