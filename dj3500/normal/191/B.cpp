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

int n,k;
ll b;
ll a[100007];

int main () {
   IOS
   cin >> n >> k >> b;
   FORI(i,n) cin >> a[i];
   
   if (k == n-1) {
      ll sum = 0;
      FORI(i,n-1) sum += a[i];
      if (sum > b) {
         pisz(1);
      } else {
         pisz(n);
      }
      
      return 0;
   }
   
   vector<ll> v;
   FORI(i,n-1) v.pb(a[i]);
   sort(ALL(v));
   reverse(ALL(v));
   int kth = v[k-1];
   ll sumofk = 0;
   FOR(i,k) sumofk += v[i];
   //DBG(sumofk)
   //DBG(kth)
   
   FORI(i,n-1) {
      ll sum = sumofk;
      //DBG(i)
      //DBG(a[i])
      if (a[i] < kth) {
         sum += a[i];
         sum -= kth;
      }
      //DBG(sum)
      if (sum > b) {
         pisz(i);
         return 0;
      }
   }
   pisz(n);
}