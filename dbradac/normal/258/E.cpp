#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

const int MAX = 100010, TOUR = 1<<17;

struct tour {
  int val, broj, prop;
  tour (int val, int broj, int prop) : val(val), broj(broj), prop(prop) {}
  tour () {}
} t[2*TOUR];

struct event {
  int t, l, r, val;
  event (int t, int l, int r, int val) : t(t), l(l), r(r), val(val) {}
  event () {}
};

bool operator < (const event &a, const event &b)
{
  return a.t < b.t;
}

vector <int> V[MAX];
vector <event> E;
int disc[MAX], fin[MAX];
int rje[MAX];
int vr=0;

void Propagiraj(int x)
{
  for (int i=2*x; i<=2*x+1; i++) {
    t[i].prop += t[x].prop;
    t[i].val += t[x].prop;
  }

  t[x].prop = 0;
}

tour Merge(tour l, tour r)
{
  if (l.val < r.val)
    return tour(l.val, l.broj, 0);
  if (r.val < l.val)
    return tour(r.val, r.broj, 0);
  return tour(l.val, l.broj + r.broj, 0);
}

void Stavi(int pos, int lo, int hi, int begin, int end, int val)
{
  if (lo >= end || hi <= begin)
    return;
  if (lo >= begin && hi <= end) {
    t[pos].val += val;
    t[pos].prop += val;
    return;
  }

  Propagiraj(pos);
  Stavi(2*pos+0, lo, (lo+hi)/2, begin, end, val);
  Stavi(2*pos+1, (lo+hi)/2, hi, begin, end, val);

  t[pos] = Merge(t[2*pos], t[2*pos+1]);
}

void Dfs(int node, int prosli)
{
  disc[node] = vr++;

  for (int i=0; i<(int) V[node].size(); i++) {
    int nn = V[node][i];
    if (nn != prosli)
      Dfs(nn, node);
  }

  fin[node] = vr;
}

void Init(int n)
{
  for (int i=0; i<n; i++)
    t[i+TOUR] = tour(0, 1, 0);

  for (int i=n; i<TOUR; i++)
    t[i+TOUR] = tour(1e9, 0, 0);

  for (int i=TOUR-1; i; i--)
    t[i] = Merge(t[2*i], t[2*i+1]);
}

int main()
{
  int n, brq;

  scanf("%d%d", &n, &brq);

  Init(n);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  Dfs(0, -1);

  for (int i=0; i<brq; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    E.push_back(event(disc[a], disc[a], fin[a], 1));
    E.push_back(event(fin[a], disc[a], fin[a], -1));
    E.push_back(event(disc[b], disc[a], fin[a],  1));
    E.push_back(event(fin[b], disc[a], fin[a], -1));

    E.push_back(event(disc[a], disc[b], fin[b], 1));
    E.push_back(event(fin[a], disc[b], fin[b], -1));
    E.push_back(event(disc[b], disc[b], fin[b],  1));
    E.push_back(event(fin[b], disc[b], fin[b], -1));
  }

  sort(E.begin(), E.end());

  for (int i=0, ind=0; i<n; i++) {
    for (; ind < (int) E.size() && E[ind].t == i; ind++) {
      event ev = E[ind];
      Stavi(1, 0, TOUR, ev.l, ev.r, ev.val);
    }

    if (t[1].val)
      rje[i] = n - 1;
    else
      rje[i] = max(0, n - t[1].broj - 1);
  }

  for (int i=0; i<n; i++)
    printf("%d ", rje[disc[i]]);
  printf("\n");

  return 0;
}