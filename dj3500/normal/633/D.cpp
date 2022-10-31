// tested by Hightail: https://github.com/dj3500/hightail
#include <bits/stdc++.h>
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
#define DBG(vari) cout<<"["<<__LINE__<<"] "<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int main () {
   wez(n)
   set<int> distinct;
   unordered_map<int,int> m;
   FOR(i,n) {
      wez(x)
      m[x]++;
      distinct.insert(x);
   }
   int ma = 2;
   for (int a0 : distinct) for (int b0 : distinct) {
      if (a0 == b0 && m[a0] < 2) continue;
      int len = 2;
      int a = a0, b = b0;
      --m[a];
      --m[b];
      while(1) {
         int c = a+b;
         unordered_map<int,int>::iterator it = m.find(c);
         if (it == m.end() || it->se < 1) break;
         --it->se;
         ++len;
         a = b;
         b = c;
      }
      
      REMAX(ma, len);
      
      a = a0; b = b0;
      ++m[a];
      ++m[b];
      REP(k,3,len) {
         int c = a+b;
         m[c]++;
         a = b;
         b = c;
      }
   }
   pisz(ma);
}