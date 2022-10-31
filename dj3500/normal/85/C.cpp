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
#define INF 2147483647
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

const int N = 100005;
int najw[N],najmn[N], key[N];
vector<int> syny[N];
vector<pair<int,double> > vec;

void dfs (int v) {
   if (syny[v].empty()) {
      najw[v]=najmn[v]=key[v];
   } else {
      if (key[syny[v][0]] > key[syny[v][1]]) reverse(ALL(syny[v]));
      dfs(syny[v][0]);
      dfs(syny[v][1]);
      najw[v]=najw[syny[v][1]];
      najmn[v]=najmn[syny[v][0]];
   }
}


void dfs2(int v, ll suma, int ile, int maxi) {
   if (syny[v].empty()) {
      vec.pb(mp(maxi,(double)suma/ile));
   } else {
      dfs2(syny[v][0], suma+najmn[syny[v][1]], ile+1, key[v]);
      dfs2(syny[v][1], suma+najw[syny[v][0]], ile+1, maxi);
   }
}

int root;

int main () {
   wez(n)
   FORI(i,n) {
      wez2(parent,k)
      key[i]=k;
      if(parent!=-1) syny[parent].pb(i);
      else root = i;
   }
   
   dfs(root);
   dfs2(root,0,0,INF);
   
  // DBG(vec)
   
//   DBG(vi(najw+1,najw+n+1))
//   DBG(vi(najmn+1,najmn+n+1))

   set<pair<int,double> > wtf(ALL(vec));
   
   TESTS {
      wez(klucz)
      set<pair<int,double> >::iterator it = wtf.lower_bound(mp(klucz,0));
      printf("%.10lf\n",it->se);
   }
}