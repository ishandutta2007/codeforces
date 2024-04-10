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

char temp[300];
int freesurnames[300], freenames[300];
multiset<string> names[300], surnames[300];

string spacja (string a, string b) {
   return a + " " + b;
}

int main () {
   wez(n)
   FOR(i,n) {
      scanf("%s",temp);
      names[temp[0]].insert(temp);
   }
   FOR(i,n) {
      scanf("%s",temp);
      surnames[temp[0]].insert(temp);
   }
   
   REP(c,'A','Z') {
      int minn = min(SZ(names[c]), SZ(surnames[c]));
      freesurnames[c] = SZ(surnames[c]) - minn;
      freenames[c] = SZ(names[c]) - minn;
   }
   
   vector<string> res;
   REP(c,'A','Z') {
      REP(c2,'A','Z') {
         if (c != c2) {
            while (freenames[c] > 0 && freesurnames[c2] > 0) {
               --freesurnames[c2];
               --freenames[c];
               res.pb(spacja(*names[c].begin(), *surnames[c2].begin()));
               names[c].erase(names[c].begin());
               surnames[c2].erase(surnames[c2].begin());
            }
         } else {
            while (!names[c].empty() && !surnames[c].empty()) {
               res.pb(spacja(*names[c].begin(), *surnames[c].begin()));
               names[c].erase(names[c].begin());
               surnames[c].erase(surnames[c].begin());
            }
         }
      }
   }
      
   FOR(i,SZ(res)) {
      printf("%s",res[i].c_str());
      if (i != SZ(res)-1) printf(", ");
   }
}