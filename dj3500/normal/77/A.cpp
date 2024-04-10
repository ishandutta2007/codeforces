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
#define INF 2000000008
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

bool likes[10][10];
int expe[4];

int main () {
   map<string,int> tr;
   int temp = 0;
   tr["Anka"] = temp; temp++;
   tr["Chapay"] = temp; temp++;
   tr["Cleo"] = temp; temp++;
   tr["Troll"] = temp; temp++;
   tr["Dracul"] = temp; temp++;
   tr["Snowy"] = temp; temp++;
   tr["Hexadecimal"] = temp; temp++;
   TESTS {
      string p,syf,q;
      cin >> p >> syf >> q;
      likes[tr[p]][tr[q]] = 1;
   }
   cin >> expe[0] >> expe[1] >> expe[2];
   
   pii best = mp(INF,0);
   
   int cnt[8];
   for (cnt[0] = 0; cnt[0] <= 2; cnt[0]++)
   for (cnt[1] = 0; cnt[1] <= 2; cnt[1]++)
   for (cnt[2] = 0; cnt[2] <= 2; cnt[2]++)
   for (cnt[3] = 0; cnt[3] <= 2; cnt[3]++)
   for (cnt[4] = 0; cnt[4] <= 2; cnt[4]++)
   for (cnt[5] = 0; cnt[5] <= 2; cnt[5]++)
   for (cnt[6] = 0; cnt[6] <= 2; cnt[6]++) {
      //DBG(vi(cnt,cnt+7))
      int ile[3];
      FOR(i,3) ile[i]=0;
      FOR(i,7) ile[cnt[i]]++;
      bool ok = 1;
      FOR(i,3) if (ile[i] == 0) ok = 0;
      if (!ok) continue;
      
      int liking = 0;
      FOR(i,7) FOR(j,7) if(likes[i][j] && cnt[i] == cnt[j]) ++liking;
      
      int minexp = INF;
      int maxexp = -INF;
      FOR(i,7) {
         int score = expe[cnt[i]] / ile[cnt[i]];
         REMIN(minexp, score)
         REMAX(maxexp, score)
      }
      pii wyn = mp(maxexp-minexp, -liking);
      if (wyn < best) best = wyn;
   }
   printf("%d %d\n",best.fi,-best.se);
}