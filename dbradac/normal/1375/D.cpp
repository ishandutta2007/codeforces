#include <cstdio>
#include <cassert>
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

const int MAX = 1005;

int n;
int p[MAX];
int op;

int mex() {
  int has[n+2] = {0};
  REP(i, n) has[p[i]] = 1;
  REP(i, n+2) if (!has[i]) return i;

  assert(false);
}

vector <int> R;
void change(int ind) {
  R.push_back(ind);
  p[ind] = mex();
  op++;
}

void gen() {
  n = rand() % 5 + 1; 
  REP(i, n) p[i] = rand() % (n+1);

//  REP(i, n) TRACE(i _ p[i]);
}

void load() {
  scanf("%d",&n);
  REP(i, n) scanf("%d", &p[i]);
}

bool sorted() {
  REP(i, n-1) if (p[i] > p[i+1]) return false;
  return true;
}

int main()
{
  int t;
  scanf("%d", &t);

  while(t--) {
    load();
    //gen();
    op = 0;
    R = {};

    bool touched_last = false;
    while(!sorted()) {
      int val = mex();
      int ind = min(n-1, val);

      if (ind == n-1) {
        if (touched_last) {
          int best = -1;
          REP(j, n) {
            if (p[j] != j && (best == -1 || p[j] < p[best])) best = j;
          }

          change(best);
        }
        else {
          change(ind);
          touched_last = true;
        }
      }
      else
        change(ind);
    }

    //TRACE(n _ op);
    assert(op <= 2*n);

    printf("%d\n", op);
    REP(i, op) printf("%d ", R[i]+1);
    printf("\n");
  }

  return 0;
}