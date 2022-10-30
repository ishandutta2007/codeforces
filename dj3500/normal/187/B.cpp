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

int timee[64][64][64], dp[64][64][64];

int main () {
	wez3(n,m,r)
	FOR(i,m) {
		FOR(j,n) FOR(k,n) scanf("%d", &timee[i][j][k]);
		// FW
		FOR(u,n) FOR(j,n) FOR(k,n) REMIN(timee[i][j][k], timee[i][j][u] + timee[i][u][k]);
	}
	
	FOR(from,n) FOR(to,n) {
		dp[0][from][to] = INF;
		FOR(i,m) REMIN(dp[0][from][to], timee[i][from][to]);
	}
	
	FORI(ch,60) FOR(from,n) FOR(to,n) {
		dp[ch][from][to] = dp[ch-1][from][to];
		FOR(thru,n) REMIN(dp[ch][from][to], dp[0][from][thru] + dp[ch-1][thru][to]);
	}
	
	while (r--) {
		wez3(starting,ending,changes)
		--starting; -- ending;
		if (changes > 60) changes = 60;
		pisz(dp[changes][starting][ending]);
	}
}