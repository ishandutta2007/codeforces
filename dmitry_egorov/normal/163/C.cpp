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

vector <pair <long double, int> > Ev;
long double Res[110000];

int main()
{
  int n, x, i;
  long double l, v1, v2, nl, lx;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>n>>l>>v1>>v2, nl=l*v2/(v1+v2);
  Ev.pb(mp(0,0)), Ev.pb(mp(2.0*l,0));
  for (i=0; i<n; i++)
  {
    scanf("%d", &x), lx=x; 
    Ev.pb(mp(lx,-1));
    if (lx>=nl)
      Ev.pb(mp(lx-nl,1));
    else
      Ev.pb(mp(0,1)), Ev.pb(mp(2.0*l+lx-nl,1));
  }
  sort(Ev.begin(),Ev.end());
  //for (i=0; i<=(int)Ev.size(); i++)
  //  cerr<<Ev[i].first<<" "<<Ev[i].second<<endl; 
  int id=0, cnt=0;
  while (id+1<(int)Ev.size())
    cnt+=Ev[id].second, Res[cnt]+=Ev[id+1].first-Ev[id].first, id++;
  for (i=0; i<=n; i++)
    printf("%.12lf\n", (double)( ((long double)Res[i])/  ((long double)(2.0*l)) )  );
  return 0;
}