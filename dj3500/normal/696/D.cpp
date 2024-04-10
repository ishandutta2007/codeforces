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

typedef vector<ll> row;   // na longlongach dziala 10 razy wolniej
int R;                // ustawic to przed uzyciem
struct macierz : vector<row> {
   macierz() : vector<row>(R,row(R,0)) {}
};

macierz mult(const macierz &m1, const macierz &m2) {
   macierz w;
   FOR(i,R) FOR(j,R) {
      ll x = -1LL * INF * INF;
      FOR(k,R) REMAX(x, m1[i][k] + m2[k][j]);
      w[i][j] = x;
   }
   return w;
}

macierz potega(const macierz &m, ll k) { // uwaga: czy wczytae k jako longlonga?
   if (k == 1) return m;
   macierz x = potega(m,k/2);
   x = mult(x,x);
   if (k&1) return mult(m,x);
   return x;
}

bool isSuffix (string s, string t) {
  if (s.length() > t.length()) return 0;
  FOR(i,SZ(s)) {
    if (s[i] != t[t.length()-s.length()+i]) return 0;
  }
  return 1;
}

const int N = 2222;
int partscore[N];
string s[N];
ll prize[N];

ll ile[20300][205];
const int TURNS = 3500;
int gdzie[TURNS+3][205];

int main () {
   wez(n);
   ll l;
   cin >> l;
   FORI(i,n) scanf("%d", partscore+i);
   FORI(i,n) cin >> s[i];
   
   vector<string> prefs;
   FORI(i,n) REP(k,0,SZ(s[i])) prefs.pb(s[i].substr(0,k));
   sort(ALL(prefs));
   prefs.erase(unique(ALL(prefs)), prefs.end());
   
   R = SZ(prefs);
   macierz A;
   FOR(i,R) FOR(j,R) A[i][j] = -1LL * INF * INF;
   
   FOR(k,SZ(prefs)) {
      FORI(i,n) if (isSuffix(s[i], prefs[k])) prize[k] += partscore[i];
   }
   
   FOR(k,SZ(prefs)) {
      FOR(j,26) {
         string nu = prefs[k] + char('a' + j);
         REP(st,0,SZ(nu)) {
            string suf = nu.substr(st);
            if (binary_search(ALL(prefs), suf)) {
               int i = lower_bound(ALL(prefs), suf) - prefs.begin();
               A[k][i] = prize[i];
               break;
            }
         }
      }
   }
   
   macierz V; // all zeroes
   macierz res = mult(potega(A, l), V);
   cout << res[0][0];
}