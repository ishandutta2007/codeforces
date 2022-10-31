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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

#define N 500500

map<string,int> mapa;
int last = 0;
pii score[N];
int id (string s) {
   FOR(i,SZ(s)) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
   if (mapa.count(s)) return mapa[s];
   // nowe slowo
   int R = 0;
   FOR(i,SZ(s)) if (s[i] == 'r') ++R;
   ++last;
   score[last] = mp(R, SZ(s));
   return mapa[s] = last;
}
vi adj[N];
bool seen[N];
pii operator + (const pii &a, const pii &b) { return mp(a.fi + b.fi, a.se + b.se); }

void dfs (int v, pii sc) {
   if (seen[v]++) return;
   score[v] = sc;
   FOREACH(x,adj[v]) dfs(*x, sc);
}

int main () {
   IOS
   int n, m;
   cin >> n;
   vi essay;
   string temp, temp2;
   FOR(i,n) {
      cin >> temp;
      essay.pb(id(temp));
   }
   cin >> m;
   FOR(i,m) {
      cin >> temp >> temp2;
      int a = id(temp), b = id(temp2);
      adj[b].pb(a);
   }
   
   vector<pair<pii,int> > sorter;
   FORI(i,last) sorter.pb(mp(score[i], i));
   sort(ALL(sorter));
   
   FOREACH(it,sorter) {
      dfs(it->se, it->fi);
   }
   
   ll r1 = 0, r2 = 0;
   FOREACH(it,essay) {
      r1 += score[*it].fi;
      r2 += score[*it].se;
   }
   cout << r1 << " " << r2;
}