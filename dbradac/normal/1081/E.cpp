#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 200005;

ll a[MAX];
ll x[MAX];

void nope() {
  printf("No\n");
  exit(0);
}

int main()
{
  //  while(1) {
    int n;
    
    //    memset(a, 0, sizeof a);
    //    memset(x, 0, sizeof x);
    //    n = 2*(rand() % 3 + 1);

    //    ll tmp[n];
    //    REP(i, n) tmp[i] = rand() % 10;
    //    sort(tmp, tmp+n);
    
    //    for (int i=1; i<n; i+=2) x[i] = (tmp[i] - tmp[i-1]) * (tmp[i] + tmp[i-1]);

    scanf("%d", &n);
       
       for (int i=1; i<n; i+=2) scanf("%lld", &x[i]);
       
    ll a1=MAX, a2=MAX;

    for (int j=1; j*j <= x[1]; j++) {
      if (x[1] % j == 0) {
	ll p = j, q = x[1] / j;
	if (q < p) swap(p, q);
	if ((p+q) % 2) continue;
	if (p == q) continue;

	ll t1 = (q-p) / 2, t2 = (p+q) / 2;
	if (max(t1, t2) < max(a1, a2)) {
	  a1 = t1;
	  a2 = t2;
	}
      }
    }

    if (a1 == MAX && a2 == MAX) nope(); 
    a[0] = a1;
    a[1] = a2;

    //    int ne = 0;
    for (int i=3; i<n; i+=2) {
      a1 = MAX, a2 = MAX;
      for (int j=1; j*j <= x[i]; j++) {
	if (x[i] % j) continue;
	ll p = j, q = x[i] / j;
	if (q < p) swap(p, q);
	if ((p+q) % 2) continue;
	if (p == q) continue;

	ll t1 = (q-p) / 2, t2 = (p+q) / 2;
	if (min(t1, t2) <= a[i-2]) continue;
	if (max(t1, t2) < max(a1, a2)) {
	  a1 = t1;
	  a2 = t2;
	}      
      }

      if (a1 == MAX && a2 == MAX) nope();
      a[i-1] = a1;
      a[i] = a2;
    }
    //    if (ne) continue;

    x[0] = (ll) a[0] * a[0];
    FOR(i, 1, n) {
      assert(a[i] > a[i-1]);
      if (i % 2) assert(((ll) a[i] - a[i-1]) * ((ll) a[i] + a[i-1]) == x[i]);
      else x[i] = ((ll) a[i] - a[i-1]) * ((ll) a[i] + a[i-1]);
    }

    printf("Yes\n");
    REP(i, n) printf("%lld ", x[i]);
    printf("\n");

    //  }
  
  return 0;
}