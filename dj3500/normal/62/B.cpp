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
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(t)while(t--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
template<typename T,typename TT> inline ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> inline ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.sz)s<<t[i]<<" ";return s; }
inline void pisz(int n) { printf("%d\n",n); }

set<int> st[300];
set<int,greater<int> > st2[300];

int main () {
   ios_base::sync_with_stdio(0);
   int n,k;
   string s;
   cin >> n >> k >> s;
   FOR(i,s.length()) {
      st[s[i]].insert(i);
      st2[s[i]].insert(i);
   }
   FOR(testno,n) {
      string c;
      cin >> c;
      int len = c.length();
      ll w = 0;
      FOR(i,len) {
         char ch = c[i];
         set<int>::iterator it = st[ch].lower_bound(i);
         set<int,greater<int> >::iterator it2 = st2[ch].lower_bound(i);
         int worst = INF;
         if (it != st[ch].end()) {
            int wyn = abs(i-*it);
            if (wyn < worst) worst = wyn;
         }
         if (it2 != st2[ch].end()) {
            int wyn = abs(i-*it2);
            if (wyn < worst) worst = wyn;
         }
         if (worst == INF) {
            w += len;
         } else {
            w += worst;
         }
      }
      cout << w << endl;
   }
}