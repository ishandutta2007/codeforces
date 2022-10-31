#include <cstdio>
#include <queue>
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

const int MAX = 1<<20;

int n;

int kvadrant(P t) { //not (0, 0)
  if (t.X > 0 && t.Y >= 0) return 1;
  if (t.X <= 0 && t.Y > 0) return 2;
  if (t.X < 0 && t.Y <= 0) return 3;
  return 4;
  //if (t.X >= 0 && t.Y < 0) return 4;
}

bool cmp(P a, P b) {
  if (kvadrant(a) != kvadrant(b)) return kvadrant(a) < kvadrant(b);
  return abs((ll) a.X * b.Y) < abs((ll) a.Y * b.X);
}

double norm(P t) {
  return sqrt((ll) t.X * t.X + (ll) t.Y * t.Y);
}

P p[MAX];
vector <vector <double> > Lines;
int nlines;

void get_lines() {
  REP(i, n) {
    if (p[i] == P(0, 0)) {
      swap(p[i], p[n-1]);
      break;
    }
  }

  sort(p, p+n-1, cmp);

  for (int i=0; i<n-1; ) {
    int j=i;
    vector <double> T;
    for (; j<n-1 && !cmp(p[i], p[j]) && !cmp(p[j], p[i]); j++) {
      T.push_back(norm(p[j]));
      //printf("%d %d    ", p[j].X, p[j].Y);
    }
    //printf("\n");
    i=j;
    sort(T.begin(), T.end());
    Lines.push_back(T);
  }

  Lines[0].insert(Lines[0].begin(), 0.0); //origin
}

int k;
int lit[MAX], rit[MAX];
double sum_norm_left[MAX], sum_norm_right[MAX];

double get_gain(int ind, int j) {
  int to_the_right = (int) Lines[ind].size() - rit[ind] - 1;
  int to_the_left = lit[ind];
  
  double me = Lines[ind][j];
  double ret = sum_norm_right[ind] - to_the_right * me;
  ret += to_the_left * me - sum_norm_left[ind];
  ret -= sum_norm_left[ind] + sum_norm_right[ind];
  ret += me * (k - to_the_left - to_the_right - 1);

  return ret;
}

pair <double, P> get_gain(int ind) { //index
  if (lit[ind] > rit[ind]) return make_pair(-1e18, P(ind, 0));
  double a = get_gain(ind, lit[ind]), b = get_gain(ind, rit[ind]);
  if (a > b) return make_pair(a, P(ind, lit[ind]));
  else return make_pair(b, P(ind, rit[ind]));
}

double solve() {
  nlines = (int) Lines.size();

  priority_queue<pair<double, P> > Q;

  REP(i, nlines) {
    lit[i] = 0;
    rit[i] = (int) Lines[i].size() - 1;
    sum_norm_left[i] = sum_norm_right[i] = 0;
    Q.push(get_gain(i));
  }

  double ret = 0;
  REP(iter, k) {
    auto best = Q.top();
    Q.pop();
    ret += best.X;
    int ind = best.Y.X;

    //TRACE(best.X _ best.Y.X _ best.Y.Y);

    if (best.Y.Y == lit[ind]) {
      sum_norm_left[ind] += Lines[ind][lit[ind]];
      lit[ind]++;
    }
    else {
      sum_norm_right[ind] += Lines[ind][rit[ind]];
      rit[ind]--;
    }

    Q.push(get_gain(ind));
  }

  return ret;
}

int main()
{
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d%d", &p[i].X, &p[i].Y);
  get_lines();

  printf("%.10lf\n", solve());

  return 0;
}