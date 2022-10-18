#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

struct panel 
{
  int l, r, h, id;
  panel ()
  {
    l=0, r=0, h=0, id=0;
  }
  panel (int _l ,int _r, int _h, int _id)
  {
    l=_l, r=_r, h=_h, id=_id;
  }
};

set <int> S[210000];
set <pair <int, int> > SS;
panel A[210000];
int e;
pair <int, pair <int, int> > E[210000];
int D[210000];
int Id[210000];

void add (int id)
{
  E[e++]=mp(A[id].r,mp(-1,id)), E[e++]=mp(A[id].l,mp(1,id));
}

bool operator < (panel a, panel b)
{
  if (a.h!=b.h)
    return a.h>b.h;
  if (a.l!=b.l)
    return a.l<b.l;
  return a.r<b.r;
}

int main()
{
  int i, n, t, next, prev, v, tp;
  set <int> :: iterator it;
  set <pair <int, int> > :: iterator it2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &t);
  for (i=1; i<=n; i++)
    scanf("%d%d%d", &A[i].h, &A[i].l, &A[i].r), A[i].id=i, add(i);
  A[0]=panel(-inf,inf,t,0), A[n+1]=panel(-inf,inf,0,n+1), add(0), add(n+1);
  sort(E,E+e);
  for (i=0; i<e; i++)
  {
    tp=E[i].second.first, v=E[i].second.second;
    //cerr<<"!!!   "<<SS.size()<<"      "<<tp<<" "<<v<<endl;
    if (tp==-1)
    {
      SS.erase(mp(A[v].h,v));
      continue;
    }
    SS.insert(mp(A[v].h,v)), it2=SS.find(mp(A[v].h,v));
    next=-1, prev=-1;

    it2++;
    if (it2!=SS.end())
      next=it2->second;
    it2--;

    if (it2!=SS.begin())
      it2--, prev=it2->second;

    if (next!=-1 && prev!=-1)
      S[next].erase(prev);//, S[next].insert(v), S[v].insert(prev);
    if (next!=-1)
      S[next].insert(v);
    if (prev!=-1)
      S[v].insert(prev);
  }
  sort(A,A+n+2);
  for (i=0; i<n+2; i++)
    Id[A[i].id]=i;
  for (D[0]=2*inf, i=0; i<=n; i++)
    for (v=A[i].id, it=S[v].begin(); it!=S[v].end(); it++) 
/*      cerr<<v<<" "<<(*it)<<" D=  "<<D[v]<<" "<<D[*it]<<endl,*/ D[*it]=max(D[*it],min(D[v],min(A[Id[v]].r,A[Id[*it]].r)-max(A[Id[v]].l,A[Id[*it]].l)));
  cout<<D[n+1]<<endl;
  return 0;
}