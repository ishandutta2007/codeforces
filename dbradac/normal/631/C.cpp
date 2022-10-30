#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 200100;

struct event {
  int t, vel, st;
} ev[MAX];

bool operator < (const event &a, const event &b)
{
  return -a.vel != -b.vel ? -a.vel < -b.vel :
         a.t != b.t ? a.t < b.t :
         a.st < b.st;
}

multiset <int> S;
int p[MAX], rje[MAX];

int main()
{
  int n, q;

  scanf("%d%d", &n, &q);
  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  for (int i=0; i<q; i++) {
    scanf("%d%d", &ev[i].st, &ev[i].vel);
    ev[i].t = i;
  }

  ev[q++] = event { -1, 0, 1 };
  sort(ev, ev + q);

  int tst = ev[0].st, zad = ev[0].t;

  for (int i=ev[0].vel; i<n; i++)
    rje[i] = p[i];

  for (int i=0; i<ev[0].vel; i++)
    S.insert(p[i]);

  for (int i=1; i<q; i++) {
    for (; (int) S.size() > ev[i].vel; ) {
      if (tst == 1) {
        rje[S.size()-1] = *(--S.end());
        S.erase(--S.end());
      }
      else {
        rje[S.size()-1] = *S.begin();
        S.erase(S.begin());
      }
    }

    if (ev[i].t > zad) {
     tst = ev[i].st;
     zad = ev[i].t;
    }
  }

  for (int i=0; i<n; i++)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}