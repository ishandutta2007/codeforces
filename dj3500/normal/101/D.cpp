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
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

vector<pii> adj[100004];
double expe[100004];
ll vert[100004], trav[100004], a[100004];

void dfs(int v, int skad) {
	vert[v] = 1;
	if (v == 1) vert[v] = 0;

	trav[v] = 0;
	expe[v] = 0;

	vector<pair<double,int> > vec;
	for (vector<pii>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
		int w = it->fi, waga = it->se;
		if (w == skad) continue;

		dfs(w,v);
		trav[v] += trav[w] + 2*waga;
		vert[v] += vert[w];

		a[w] = 2*waga + trav[w];

		vec.pb(mp((double)a[w] / vert[w], w));
		
		expe[v] += vert[w] * (waga + expe[w]);
		
	}

	sort(ALL(vec));
	ll sumaczesciowa = 0;
	FORI(i,int(vec.size()) - 1) {
		int ind = vec[i].second, prevind = vec[i-1].second;
		sumaczesciowa += a[prevind];
		expe[v] += vert[ind] * sumaczesciowa;
	}

	expe[v] /= vert[v];
}

int main () {
	wez(n)
	FOR(i,n-1) {
		wez3(ai,bi,ti)
		adj[ai].pb(mp(bi,ti));
		adj[bi].pb(mp(ai,ti));
	}

	dfs(1,-1);

	cout << setprecision(9) << fixed << expe[1] << endl;
}