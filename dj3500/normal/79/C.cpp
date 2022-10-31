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

int maxendpoint[100006];

int main () {
   ios_base::sync_with_stdio(0);
   string s;
   cin >> s;
   int n = SZ(s);
   int k;
   cin >> k;

   FOR(i,n) maxendpoint[i] = n-1;

   FOR(i,k) {
      string b;
      cin >> b;
      vi matches = kmp(s,b);
      FOR(j,SZ(matches)) {
         REMIN(maxendpoint[matches[j]], matches[j] + SZ(b) - 2);
      }
   }

   REPD(i,n-2,0) REMIN(maxendpoint[i], maxendpoint[i+1])

   int maxdl = -1, pocz;
   FOR(i,n) {
      int dl = maxendpoint[i] - i + 1;
      if (dl > maxdl) {
         maxdl = dl;
         pocz = i;
      }
   }

   printf("%d %d\n",maxdl,pocz);
}