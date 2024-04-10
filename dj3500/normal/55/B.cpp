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
#define INF (ll)1e15
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

char zn[3];

vector<ll> doit (int x, int y, char op, vector<ll> a) {
   ll wyn;
   if (op == '+') wyn = a[x] + a[y];
   else wyn = a[x]*a[y];
   a.erase(a.begin()+y);
   a.erase(a.begin()+x);
   a.pb(wyn);
   return a;
}

int fi1[] = {0,0,0,1,1,2};
int fi2[] = {1,2,3,2,3,3};
int se1[] = {0,0,1};
int se2[] = {1,2,2};



int main () {
   ll b[4];
   cin >> b[0] >> b[1] >> b[2] >> b[3];
   vector<ll> a;
   FOR(i,4)a.pb(b[i]);
   cin >> zn[0] >> zn[1] >> zn[2];
   //DBG(zn[1])
   //DBG(INF)
   
   ll min = INF;
   FOR(i,6) FOR(j,3) {
      vector<ll> w = doit(0,1,zn[2],doit(se1[j],se2[j],zn[1],doit(fi1[i],fi2[i],zn[0],a)));
      ll wyn = w[0];
      //DBG(wyn)
      if (wyn < min) min = wyn;
   }
   cout << min << endl;
}