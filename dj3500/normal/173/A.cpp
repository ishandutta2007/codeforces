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

char s1[1000007], s2[1000007];

inline int conv (char c) {
   if (c == 'R') return 0;
   if (c == 'S') return 1;
   return 2;
}

int main () {
   wez(n)
   scanf("%s %s", s1, s2);
   int a1 = strlen(s1), a2 = strlen(s2);
   int b1 = 0, b2 = 0;
   FOR(k,a1*a2) {
      char ch1 = s1[k % a1], ch2 = s2[k % a2];
      int choice1 = conv(ch1), choice2 = conv(ch2);
      if (choice1 == choice2) continue;
      else if (choice1 == (choice2+1)%3) b1++;
      else b2++;
   }
   int calosci = n / (a1 * a2);
   int res1 = calosci * b1, res2 = calosci * b2;
   n %= (a1 * a2);
   //DBG(n)
   FOR(k,n) {
      char ch1 = s1[k % a1], ch2 = s2[k % a2];
      //DBG(mp(ch1,ch2))
      int choice1 = conv(ch1), choice2 = conv(ch2);
      if (choice1 == choice2) continue;
      else if (choice1 == (choice2+1)%3) res1++;
      else res2++;
   }
   printf("%d %d",res1,res2);
}