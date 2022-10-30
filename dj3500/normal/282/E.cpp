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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

struct Node {
   Node* lnk[2];
   Node () { lnk[0] = lnk[1] = 0; }
   void insert (char *s) {
      if (*s == 0) return;
      bool b = (*s) - '0';
      if (0 == lnk[b]) lnk[b] = new Node;
      lnk[b]->insert(s+1);
   }
};

#define N 100007
ll prefxor[N], sufxor[N], a[N];

int main () {
   IOS
   int n;
   cin >> n;
   FORI(i,n) cin >> a[i];
   prefxor[0] = sufxor[n+1] = 0;
   FORI(i,n) prefxor[i] = prefxor[i-1] ^ a[i];
   REPD(i,n,1) sufxor[i] = sufxor[i+1] ^ a[i];
   
   Node eps;
   char s[45];
   REPD(b,40,0) s[40-b] = '0';
   s[41] = 0;
   eps.insert(s);
   
   ll best = 0;
   REPD(i,n,0) {
      Node* nd = &eps;
      ll cur = 0;
      REPD(b,40,0) {
         bool bit = !((1LL << b) & prefxor[i]);
         // chcemy bit
         if (0 == nd->lnk[bit]) {
            //if (0 == nd->lnk[!bit]) { DBG(b) return 1; }
            nd = nd->lnk[!bit];
         } else {
            nd = nd->lnk[bit];
            cur ^= 1LL << b;
         }
      }
      REMAX(best,cur);
      
      REPD(b,40,0) s[40-b] = '0' + bool((1LL << b) & sufxor[i]);
      //s[41] = 0;
      eps.insert(s);
   }
   cout << best;
}