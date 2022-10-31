#define SYF freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
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
#define IOS ios_base::sync_with_stdio(0);

#define N 128
int a[N][3],b[N][3],c[N],d[N][N];
char word[N][N];
vector<string> res[N];

int main () {
   SYF
   wez2(n,t)
   FORI(i,n) scanf("%d %d %d %d",&a[i][1], &b[i][1], &a[i][2], &b[i][2]);
   wez(m)
   FORI(k,m) scanf("%s %d",word[k],c+k);
   FORI(i,n) FORI(k,m) d[i][k] = 0;

   deque<int> deck;
   FORI(k,m) deck.pb(k);
   int i = 1, time = t, j = 1;

   while (!deck.empty()) {
      int k = deck.front();
      deck.pop_front();

      int timeneeded = max(1, c[k] - (a[i][j] + b[i][3-j]) - d[i][k]);
      if (timeneeded < time) {
         // zgadli
         res[i].pb(word[k]);
         time -= timeneeded;
      } else if (timeneeded == time) {
         res[i].pb(word[k]);
         time = t;
         i++;
         if (i == n+1) {
            i = 1;
            j = 3-j;
         }
      } else {
         deck.pb(k);
         d[i][k] += time;
         time = t;
         i++;
         if (i == n+1) {
            i = 1;
            j = 3-j;
         }
      }
   }

   FORI(i,n) {
      printf("%d ",SZ(res[i]));
      FOR(j,SZ(res[i])) printf("%s ",res[i][j].c_str());
      printf("\n");
   }
}