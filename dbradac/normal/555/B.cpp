#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long ll;
typedef pair<ll, ll> pii;

const int MAX = 200100;

struct str {
  int ind;
  ll l, r;
  str (int _ind, ll _l, ll _r) : ind(_ind), l(_l), r(_r) {}
  str () {}
};

bool operator < (str a, str b)
{
  if (a.r != b.r)
    return a.r < b.r;
  if (a.l != b.l)
    return a.l < b.l;
  return a.ind < b.ind;
}

struct event {
  int st, ind; //0 dolazi int, 2 odlazi int, 1 dolazi covo
  ll t;
  event (int _st, int _ind, ll _t) : st(_st), ind(_ind), t(_t) {}
  event () {} 
};

bool operator < (event a, event b)
{
  if (a.t != b.t)
    return a.t < b.t;
  return a.st < b.st;
}

set <str> S;
int rje[MAX];
vector <event> E;
ll li[MAX], ri[MAX];

int main()
{
  int n, m, rez = 1;

  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++) {
    scanf("%I64d%I64d", &li[i], &ri[i]);
    if (i) {
      E.push_back(event(0, i, li[i] - ri[i-1]));
      E.push_back(event(2, i, ri[i] - li[i-1]));
    }
  }
  
  for (int i=0; i<m; i++) {
    ll tmp;
    scanf("%I64d", &tmp);
    E.push_back(event(1, i, tmp));
  } 

  sort(E.begin(), E.end());

  for (int i=0; i<(int) E.size(); i++) {
    event ev = E[i];
    if (!ev.st)
      S.insert(str(ev.ind, li[ev.ind] - ri[ev.ind-1], ri[ev.ind] - li[ev.ind-1]));
    else if (ev.st == 2) {
      if (S.find(str(ev.ind, li[ev.ind] - ri[ev.ind-1], ri[ev.ind] - li[ev.ind-1])) != S.end()) {
        rez = 0;
        break;
      } 
    }
    else {
      if (!S.empty()) {
        set<str> :: iterator it = S.begin();
        rje[it->ind] = ev.ind;
        S.erase(it);
      }
    }
  } 
  
  if (!rez)
    printf("No\n");
  else {
    printf("Yes\n");
    for (int i=1; i<n; i++)
      printf("%d ", rje[i] + 1);
    printf("\n");
  }

  return 0;
}