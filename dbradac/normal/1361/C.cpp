#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<22;

void no(){cout << "NO\n"; exit(0);}
 
int DUM;
int n;
vector <P> V[MAX];
vector <int> sol;
int done[MAX]; //edges
int p[MAX];

void dfs(int x) {
  while(!V[x].empty()) {
    P tmp = V[x].back();
    V[x].pop_back();
    if (done[tmp.Y]) continue;
    done[tmp.Y] = 1;
    dfs(tmp.X);
    sol.push_back(tmp.X);
  }
}

int ne;
void edge(int a, int b) {
  V[a].push_back(P(b, ne));
  V[b].push_back(P(a, ne++));
}

void gen_graph(int mid) {
  ne = 0;
  REP(i, MAX) V[i].clear();

  int mod = 1<<mid;
  REP(i, 2*n)
    edge(i, DUM + (p[i] % mod));
  REP(i, n)
    edge(2*i, 2*i+1);
}

void get_euler(int mid) {
  gen_graph(mid);
  dfs(0);

  vector <int> T;

  for (auto it : sol)
    if (it < DUM)
      T.push_back(it);

  if (abs(T[0] - T[1]) != 1) {
    T.push_back(T[0]);
    T.erase(T.begin());
  }

  for (auto it : T) printf("%d ", it+1);

  printf("\n");
}

int bio[MAX];
void dfs_con(int x) {
  bio[x] = 1;
  for (auto it : V[x]) {
    if (!bio[it.X]) dfs_con(it.X);
  }
}

int ok(int mid) {
  gen_graph(mid);
  memset(bio, 0, sizeof bio);
  dfs_con(0);

  REP(i, 2*n) if (!bio[i]) return 0;

  int mod = 1<<mid;
  REP(i, 2*n) {
    if (V[i].size() & 1) return 0;
    if (V[DUM + (p[i] % mod)].size() & 1) return 0;
  }


  return 1;
}

int main()
{
  scanf("%d", &n);
  REP(i, 2*n) scanf("%d", &p[i]);
  DUM = 2*n;

  int lo=0, hi=20;
  
  while(lo<hi) {
    int mid = (lo + hi + 1) / 2;
    if (ok(mid)) lo = mid;
    else hi = mid - 1;
  }

  printf("%d\n", lo);
  get_euler(lo);

  return 0;
}