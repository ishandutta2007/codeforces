// tested by Hightail: https://github.com/dj3500/hightail
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
#include <cassert>
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

const int N = 200200;
char s[N];
int segments[N]; // segments[i] = liczba segmentow w s[i..n]
ll special[N];

int main () {
   wez2(n,m);
   scanf("%s", s + 1);
   ll res = 0;

   res += m-1; // i == n

   REPD(i,n,1) segments[i] = segments[i+1] + (s[i] != s[i+1]);


   REPD(i,n-1,1) {
      if (i == n-1) {
         special[n-1] = (s[n-1] == s[n]) ? 1 : 2;
      } else {
         if (s[i] == s[i+1]) {
            if (s[i+1] == s[i+2]) {
               special[i] = special[i+1];
            } else {
               special[i] = 1;
            }
         } else {
            special[i] = 1;
            if (s[i+2] == s[i]) {
               special[i] += special[i+1];
            } else {
               special[i] += 1;
            }
         }
      }

      if (s[i] != s[i+1]) {
         // choose t[i] = s[i+1]
         int k = n-i-1;
         res += (k+1) * m - k;
         res += segments[i];
         res -= special[i];
      }
      // choose t[i] = not s[i] nor s[i+1]
      ll options = (s[i] != s[i+1]) ? m - 2 : m - 1;
      res += options * segments[i];
   }
   cout << res;
}