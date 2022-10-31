#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define INF (int)2e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define wez(n) int (n); scanf("%d",&(n));
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;

inline void pisz(int n) {
   printf("%d\n",n);
}

vector<int> v[1002];

int main () {
   wez(n);wez(m);wez(k);
   FOR(i,n) {
      wez(a);wez(b);
      v[a].pb(b);
   }
   int w=0;
   FORI(i,m) {
      w += *min_element(v[i].begin(), v[i].end());
   }
   printf("%d\n",min(w,k));
}