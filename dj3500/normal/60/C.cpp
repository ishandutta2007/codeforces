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
#define SZ(t) (int(t.size()))
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

vi adj[102];
int num[102];
bool vis[102];
int gcd[102][102], lcm[102][102];

int gcdf (int a, int b) {
	if (b == 0) return a;
	return gcdf(b,a%b);
}
int lcmf (int a, int b) {
	return a / gcdf(a,b) * b;
}

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

bool propagate (int v) {
	if (vis[v]) return true;
	vis[v] = 1;
	FOR(j,SZ(adj[v])) {
		int w = adj[v][j];
		if (((ll)lcm[v][w]*gcd[v][w]) % num[v]) return false;
		int powinnobyc = (ll)lcm[v][w]*gcd[v][w] / num[v];
		if (lcmf(num[v],powinnobyc) != lcm[v][w] || gcdf(num[v],powinnobyc) != gcd[v][w]) return false;
		if (num[w] == -1)
			num[w] = powinnobyc;
		else if (num[w] != powinnobyc)
			return false;
		if (!propagate(w)) return false;
	}
	return true;
}

int main () {
	wez2(n,m);
	while(m--) {
		wez2(a,b);
		wez2(g,l);
		adj[a].pb(b);
		adj[b].pb(a);
		gcd[a][b]=gcd[b][a]=g;
		lcm[a][b]=lcm[b][a]=l;
		if (l % g) {
			printf("NO\n");
			return 0;
		}
	}

	vector<vi> skladowe = podziel_na_skladowe(n,adj);
	FOR(k,SZ(skladowe)) {
		vi skladowa = skladowe[k];
		//DBG(skladowa);
		int poczw = skladowa[0];
		if (SZ(skladowa) == 1) {
			num[poczw] = 1;
			continue;
		}

		bool udalosie = 0;
		int poczg = gcd[poczw][adj[poczw][0]], poczl = lcm[poczw][adj[poczw][0]];
		//DBG(poczg)DBG(poczw)
		for (int mnoznik = 1; mnoznik * poczg <= poczl; ++mnoznik) {
			if (poczl % (mnoznik*poczg)) continue;
			FOR(l,SZ(skladowa)) {
				vis[skladowa[l]] = 0;
				num[skladowa[l]] = -1;
			}
			num[poczw] = mnoznik * poczg;
			//DBG(num[poczw])
			if (propagate(poczw)) {
				udalosie = 1;
				break;
			}
		}
		if (!udalosie) {
			printf("NO\n");
			return 0;
		}
	}

	// wszystko ustalone
	printf("YES\n");
	FORI(i,n) printf("%d ",num[i]);
}