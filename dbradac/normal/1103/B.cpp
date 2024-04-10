#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1000*1000*1000;

int ask(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  char ss[5];
  scanf(" %s", ss);
  return ss[0] == 'x';
}

void ans(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}

void rek(int lo, int hi) {
  if (lo == hi) {
    ans(lo);
    return;
  }
  
  if (lo + 1 == hi) {
    if (lo == 1) {
      if (ask(2, 1))
	ans(1);
      else
	ans(2);       
    }
    else {
      if (ask(lo-1, lo))
	ans(lo);
      else
	ans(lo+1);
    }

    return;
  }

  if (lo * 2 == hi) {
    if (ask(lo-1, lo)) {
      ans(lo);
      return;
    }

    rek(lo+1, hi);
    return;
  }

  assert(lo*2 - 2 >= hi);
  int mid = (lo + hi) / 2;
  if (ask(lo-1, mid))
    rek(lo, mid);
  else
    rek(mid+1, hi);
}

void go() {
  for (int i=1; 2*i <= MAX; i*=2) {
    if (ask(i, 2*i)) {
      rek(i, 2*i);
      return;
    }
  }

  rek(1<<29, MAX);
}

int main()
{
  while(1) {
    char t[20];
    scanf(" %s", t);
    if (t[0] == 's') go();
    else if (t[0] == 'm') assert(0);
    else break;    
  }

  return 0;
}