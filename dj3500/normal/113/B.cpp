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
using namespace std;
#define pb push_back
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
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

vi kmp(string t, string p) { // text, pattern | zwraca 0-based indeksy trafien wzorca
   vi kn(SZ(p)+1,-1); // funkcja prefiksowa Knutha
   FORI(i,SZ(p)) {
      int j = kn[i-1];
      while (j != -1 && p[j] != p[i-1]) j=kn[j];
      kn[i] = j+1;
   }

   vi ans;
   int ppos=0,tpos=0;
   while (tpos<SZ(t)) {
      while (ppos!=-1 && (ppos == SZ(p) || p[ppos]!=t[tpos])) ppos=kn[ppos];
      ppos++;
      tpos++;
      if (ppos==SZ(p)) ans.pb(tpos-SZ(p));
   }
   return ans;
}

struct hasz {
   #define ull unsigned ll
   vector<ull> prpow, h;
   static const unsigned ll pr = 1000000009;

   hasz(string t) : prpow(SZ(t)+1), h(SZ(t)+1) {
      h[0] = 0;
      FORI(i,SZ(t)) h[i] = h[i-1]*pr + t[i-1];
      prpow[0] = 1;
      FORI(i,SZ(t)) prpow[i] = prpow[i-1] * pr;
   }

   ull haszuj (int a, int b) { // hasz podsowa t[a..b] (a,b 0-based)
      return h[b+1] - prpow[b-a+1]*h[a];
   }
};

int main () {
   ios_base::sync_with_stdio(0);
   string t,sb,se;
   cin >> t >> sb >> se;
   vi occb = kmp(t,sb), occe = kmp(t,se);
   vi matche[2005];
   FOR(i,SZ(occb)) {
      int pos = occb[i];
      FOR(j,SZ(occe)) {
         int dl = occe[j] - pos;
         if (dl < 0) continue; // koncowka stoi po poczatku
         if (dl < SZ(sb)-SZ(se)) continue; // koncowka konczy sie przed koncem poczatku
         matche[dl].pb(pos);
      }
   }

   hasz h(t);
   int wyn = 0;
   FOR(dl,2005) {
      set<ull> hasze;
      FOR(i,SZ(matche[dl])) {
         int lewy = matche[dl][i], prawy = lewy + dl + SZ(se) - 1;
         hasze.insert(h.haszuj(lewy,prawy));
      }
      wyn += SZ(hasze);
   }

   cout << wyn << endl;
}