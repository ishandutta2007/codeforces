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




#define ll int
// weak tests, lol



// RMQ na przedziale od 0 do n-1
// przed uzyciem ustawic MAXX, n i odpalic init
// zwieksz zwieksza wartosci z przedzialu [aw,bw] o ile
// getmin zwraca minimum z przedzialu [aw,bw]
// MAXX - 2 * (najmniejsza potega dwojki wieksza od n) + 10

#define MAXX 524298
ll incr[MAXX], minn[MAXX];
int n;

void init () {
   FOR(i,MAXX) incr[i] = minn[i] = 0;
}

int aw,bw,x; // temp

void zwieksz2 (int v, int a, int b) {
   if (aw > b || bw < a) return;
   if (a >= aw && b <= bw) {
      incr[v] += x;
      minn[v] += x;
   } else {
      int mid = (a+b)/2;
      zwieksz2(2*v, a, mid);
      zwieksz2(2*v+1, mid+1, b);
      minn[v] = incr[v] + min(minn[2*v], minn[2*v + 1]);
   }
}

void zwieksz (int _aw, int _bw, int _x) {
   aw = _aw; bw = _bw; x = _x;
   zwieksz2(1,0,n-1);
}

ll getmin (int v, int a, int b) {
   if (aw > b || bw < a) return INF;
   if (a >= aw && b <= bw) {
      return minn[v];
   } else {
      int mid = (a+b)/2;
      return incr[v] + min(getmin(2*v, a, mid), getmin(2*v+1, mid+1, b));
   }
}

ll getmin (int _aw, int _bw) {
   aw = _aw; bw = _bw;
   return getmin(1,0,n-1);
}

int main () {
   ios_base::sync_with_stdio(0);
   cin >> n;
   init();


   FOR(i,n) {
      int y;
      cin >> y;
      zwieksz(i,i,y);
      //DBG(vector<ll>(incr+1,incr+8))
      //DBG(vector<ll>(minn+1,minn+8))
   }

   int m;
   cin >> m;
   char s[200];
   cin.getline(s,200); // \n
   while (m--) {
      cin.getline(s,200);
      vi nums;
      stringstream ss(s);
      int in;
      while (ss >> in) nums.pb(in);

      //DBG(nums)

      if (SZ(nums) == 2) {
         int lf = nums[0], rg = nums[1];
         //DBG(mp(lf,rg))
         ll wyn;
         if (lf <= rg) {
            wyn = getmin(lf,rg);
         } else {
            wyn = min(getmin(lf,n-1), getmin(0,rg));
         }
         cout << wyn << "\n";
      } else if (SZ(nums) == 3) {
         int lf = nums[0], rg = nums[1], v = nums[2];
         if (lf <= rg) {
            zwieksz(lf,rg,v);
         } else {
            zwieksz(lf,n-1,v);
            zwieksz(0,rg,v);
         }
      } else {
         printf("error!");
         return 1;
      }
   }
}