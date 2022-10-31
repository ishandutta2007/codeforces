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

vector<vi> podziel_na_skladowe (int n, vi *adj) {
	vector<bool> vis(n+1,0);
	vector<vi> wyn;
	FORI(i,n) {
		if (vis[i]) continue;
		vi skladowa;
		deque<int> q;
		q.pb(i);
		while (!q.empty()) {
			int v = q.front();
			q.pop_front();
			if (vis[v]) continue;
			vis[v]=1;
			skladowa.pb(v);
			FOR(j,SZ(adj[v])) q.pb(adj[v][j]);
		}
		wyn.pb(skladowa);
	}
	return wyn;
}

bool lucky (int x) {
   while (x) {
      if (x%10 != 4 && x%10 != 7) return false;
      x /= 10;
   }
   return true;
}

vi adj[100006];

int main () {
   wez(n)
   FOR(u,n-1) {
      wez3(a,b,w)
      if (!lucky(w)) {
         adj[a].pb(b);
         adj[b].pb(a);
      }
   }
   vector<vi> v = podziel_na_skladowe(n,adj);
   ll sumawsz = 0, suma = 0;
   FOR(i,SZ(v)) {
      ll k = SZ(v[i]);
      sumawsz += k;
   }
   FOR(i,SZ(v)) {
      ll k = SZ(v[i]), reszta = sumawsz - k;
      suma += k * reszta * (reszta - 1);
   }
   cout << suma << endl;
}