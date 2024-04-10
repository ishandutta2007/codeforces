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
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)

bool poss[10000];

vi przel (int n) {
   vi v(4);
   v[0] = n/1000;
   n%=1000;
   v[1] = n/100;
   n%=100;
   v[2] = n/10;
   v[3] = n%10;
   return v;
}

int main () {
   wez(n)
   FOR(i,10000) poss[i] = 1;
   while (n--) {
      string s;
      int rowno,prawie;
      cin >> s >> rowno >> prawie;
      FOR(j,4) s[j]-='0';
      FOR(i,10000) {
         vi v = przel(i);
         int r=0,p=0;
         FOR(j,4) {
            if (v[j]==s[j]) ++r;
            FOR(k,4)if(j!=k)if(v[j]==s[k]) ++p;
         }
         if(!(r==rowno && p==prawie)) poss[i]=0;
      }
   }
   int possi=0;
   vi any;
   FOR(i,10000) {
      vi v = przel(i);
      int ile[10];
      FOR(k,10)ile[k]=0;
      FOR(j,4) ile[v[j]]++;
      bool zle=0;
      FOR(k,10)if(ile[k]>1)zle=1;
      if (!zle && poss[i]) {
         ++possi;
         any=v;
      }
   }
   if (possi == 0) {
      cout << "Incorrect data";
   } else if (possi > 1) {
      cout << "Need more data";
   } else {
      FOR(j,4)cout << any[j];
   }
}