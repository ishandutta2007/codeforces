#include <cstdio>
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1<<18;

vector <int> V[MAX];
int n;
int bio[MAX];

int dijam(int x, int pr, int kraj, vector <int> &T) 
{
  T.push_back(x);
  if (x == kraj) return 1;

  for (auto it : V[x]) {
    if (it != pr) {
      if (dijam(it, x, kraj, T))
	return 1;
    }
  }

  T.pop_back();
  return 0;
}

void dfs(int x, int dd)
{
  if (bio[x] != -1) return;
  bio[x] = dd;

  for (auto it : V[x])
    dfs(it, dd+1);
}

int najdalji(int x)
{
  memset(bio, -1, sizeof bio);
  dfs(x, 0);

  P ret = P(0, x);
  REP(i, n)
    ret = max(ret, P(bio[i], i));

  return ret.Y;
}

void nope()
{
  printf("-1\n");
  exit(0);
}

int go(int x, int pr)
{
  int ds = -1;
  vector <int> Ds;
  
  for (auto it : V[x]) {
    if (it != pr) {
      int tmp = go(it, x);
      if (ds == -1) {
	ds = tmp;
	if (pr == -1)
	  Ds.push_back(tmp);
      }
      else if (tmp != ds) {
	if (pr != -1) nope();
	//	TRACE(it+1 _ tmp);
	int da = 0;
	for (auto it : Ds) if (it == tmp) da = 1;
	if (!da) Ds.push_back(tmp);
      }
    }
  }

  if (pr == -1) {
    if ((int) Ds.size() > 2) nope();
    int sum = 0;
    for (auto it : Ds) { sum += it+1; }
    for (; !(sum % 2); sum /= 2);
    return sum;
  }

  //  TRACE(x+1 _ 1+ds);
  //  if (ds == -1) return 1;
  return 1 + ds;
}

int main()
{
  scanf("%d", &n);
  srand(time(0) * getpid());
  //  n = rand()% 7 + 1;
  //  debug("%d\n", n);
  REP(i, n-1) {
    int a, b;
    //  a = rand() % (i+1);
    //    b = i+1;
    scanf("%d%d", &a, &b); a--; b--;
    //    debug("%d %d\n", a+1, b+1);
    V[a].push_back(b);
    V[b].push_back(a);
  }

  int prvi = najdalji(0);
  int drugi = najdalji(prvi);
  vector <int> Dij;
  dijam(prvi, -1, drugi, Dij);

  assert((int) Dij.size() == bio[drugi] + 1);
  int root = Dij[Dij.size()/2];

  printf("%d\n", go(root, -1));

  return 0;
}