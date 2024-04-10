#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int mod = 1000000007;

/*void go (int pref, int stars) {
   if (pref > 0) printf("%d", pref);
   while(stars--) printf("*");
   printf("\n");
}*/

string toString (ll num, int b) {
   string w;
   if (num==0) w = "0";
   while (num != 0) {
      int r = num%b;
      num /= b;
      if (r < 10) w += r+'0';
      else w += r+'A'-10;
   }
   reverse(ALL(w));
   return w;
}

// maksimum co zmiesci sie w long longu to (66 po 33)
#define NEED 66
ll nt[NEED+1][NEED+1];

void initnewton () {
	FOR(n,NEED+1) nt[n][0] = 1;
	FORI(k,NEED) nt[0][k] = 0;
	FORI(n,NEED) FORI(k,NEED) nt[n][k] = nt[n-1][k-1] + nt[n-1][k];
}

int nwld[10];
int maxstars = 0;
void go (int pref, int stars) {
   //DBG(mp(pref,stars))
   if (pref == 0) {
      REMAX(maxstars,stars);
      return;
   }
   string s = toString(pref,10);
   int luck = 0;
   FOREACH(x,s) if (*x == '4' || *x == '7') ++luck;
   REP(lucky,0,stars) {
      nwld[luck + lucky] += (1 << lucky) * (1 << (3 * (stars-lucky))) * nt[stars][lucky];
   }
}

int main () {
   wez(m)
   initnewton();
   
   REP(d,0,9) nwld[d] = 0;
   
   ll p = 10, k = 1;
   while (p <= m+1) {
      go(0,k);
      p *= 10;
      k++;
   }
   p /= 10; k--;
   ll d = 1;
   while(p) {
      if ((d+1) * p <= m+1) {
         go(d, k);
         d++;
      } else {
         p /= 10; k--;
         d *= 10;
      }
   }
   
   if (maxstars > 0) {
      go(1 /*anything unlucky*/, maxstars);
      nwld[0]--; // za zero
   }
   
   //DBG(vi(nwld,nwld+10))
   
   ll res = 0;
   REP(eleph,1,9) {
      REP(p1,0,8) REP(p2,0,8) REP(p3,0,8) REP(p4,0,8) REP(p5,0,8) REP(p6,0,8) {
         if (p1 + p2 + p3 + p4 + p5 + p6 >= eleph) continue;
         ll options = nwld[eleph];
         nwld[eleph]--;
         options *= nwld[p1];
         options %= mod;
         nwld[p1]--;
         options *= nwld[p2];
         options %= mod;
         nwld[p2]--;
         options *= nwld[p3];
         options %= mod;
         nwld[p3]--;
         options *= nwld[p4];
         options %= mod;
         nwld[p4]--;
         options *= nwld[p5];
         options %= mod;
         nwld[p5]--;
         options *= nwld[p6];
         options %= mod;
         nwld[eleph]++;
         nwld[p1]++;
         nwld[p2]++;
         nwld[p3]++;
         nwld[p4]++;
         nwld[p5]++;
         res += options;
      }
   }
   res %= mod;
   if (res < 0) res += mod;
   pisz(res);
}