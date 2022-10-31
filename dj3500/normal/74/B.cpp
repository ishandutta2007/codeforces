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
using namespace std;
#define pb push_back
#define INF (int)1e9
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

bool tohead;

int pozco (int pozprzed, int n) {
   if (tohead) {
      if (pozprzed==1) {
         tohead = 0;
         return 2;
      } else return pozprzed-1;
   } else {
      if (pozprzed == n) {
         tohead = 1;
         return n-1;
      } else return pozprzed+1;
   }
}

int main () {
   wez3(n,st,co)
   string syf,s;
   cin >> syf >> s;
   tohead = (s=="head");
   cin >> s;
   
   int pos = 0, len = s.length();
   while (s[pos] == '0' && pos < len) ++pos;
   
   // poczatek
   int ilewytrzyma;
   if (tohead) {
      if (st < co) {
         ilewytrzyma = co-2;
      } else {
         ilewytrzyma = co-2 + n-1;
      }
   } else {
      if (st > co) {
         ilewytrzyma = n-co-1;
      } else {
         ilewytrzyma = n-co-1 + n-1;
      }
   }
   if (ilewytrzyma < pos) {cout << "Controller " << ilewytrzyma+1 << endl; return 0;}
   
   FOR(i,pos) co=pozco(co,n);
   
   while(1) {
      if (pos == len) {cout << "Stowaway" << endl; return 0; }
      
      if (s[pos] == '1') {
         co = pozco(co,n);
         if (tohead) st = n;
         else st = 1;
      } else {
         co=pozco(co,n);
         if (st==co) {cout << "Controller " << pos+1 << endl; return 0;}
      }
      
      ++pos;
   }
}