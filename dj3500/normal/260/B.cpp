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

char s[100007];
int cnt[5][14][35];
int day[256][256], month[256][256], yr[256];

int main () {
   int k = 0;
   REP(c,'0','2') REP(d,'0','9') day[c][d] = k++;
   day['3']['0'] = 30;
   day['3']['1'] = 31;
   k = 0;
   REP(d,'0','9') month['0'][d] = k++;
   month['1']['0'] = 10;
   month['1']['1'] = 11;
   month['1']['2'] = 12;
   yr['3'] = 2013;
   yr['4'] = 2014;
   yr['5'] = 2015;
   scanf("%s", s);
   int n = strlen(s);
   for (int i = 0; i + 10 <= n; ++i) {
      if (s[i+6] == '2' && s[i+7] == '0' && s[i+8] == '1' && s[i+5] == '-' && s[i+2] == '-') {
         int y = yr[s[i+9]];
         int m = month[s[i+3]][s[i+4]];
         int d = day[s[i]][s[i+1]];
         if (y == 0 || m == 0 || d == 0) continue;
         if (m == 2 && d > 28) continue;
         if (m == 4 && d > 30) continue;
         if (m == 6 && d > 30) continue;
         if (m == 9 && d > 30) continue;
         if (m == 11 && d > 30) continue;
         cnt[y - 2013][m][d] ++;
      }
   }
   
   int ma = 0, y1, m1, d1;
   REP(d,1,31) REP(m,1,12) REP(y,0,2) {
      if (ma < cnt[y][m][d]) {
         ma = cnt[y][m][d];
         y1 = y;
         m1 = m;
         d1 = d;
      }
   }
   printf("%02d-%02d-%d\n", d1, m1, y1+2013);
}