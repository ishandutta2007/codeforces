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

#define N 200006
char s[N], t[N];
int a[N], b[N];

int main () {
	scanf("%s %s", s, t);
	int n = strlen(s), m = strlen(t);
	t[m] = '#';
	s[n] = '$';
	vi occ[300];
	FOR(j,m) occ[t[j]].pb(j);
	
	int cur = 0;
	a[0] = 0;
	if (s[0] == t[0]) { a[0] = 1; cur = 1; }
	REP(i,1,n-1) {
		a[i] = a[i-1];
		if (cur < m && s[i] == t[cur]) {
			a[i]++;
			cur++;
		}
	}
	
	cur = m-1;
	b[n-1] = 0;
	if (s[n-1] == t[m-1]) { b[n-1] = 1; cur--; }
	REPD(i,n-2,0) {
		b[i] = b[i+1];
		if (cur >= 0 && s[i] == t[cur]) {
			b[i]++;
			cur--;
		}
	}
	
	//DBG(vi(a,a+n))
	//DBG(vi(b,b+n))
	
	FOR(i,n) {
		char c = s[i];
		int le, ri;
		if (i == 0) {
			le = 0;
		} else {
			le = a[i-1];
		}
		// 0 <= le <= m
		if (le == m) le = m - 1;
		
		if (i == n-1) {
			ri = m-1;
		} else {
			ri = m-1 - b[i+1];
		}
		// -1 <= ri <= m-1
		if (ri == -1) ri = 0;
		
		//DBG(i)DBG(ri)DBG(le)
		
		// czy t[ri,le] zawiera c?
		vi::iterator it = lower_bound(ALL(occ[c]), ri);
		if (it != occ[c].end() && *it <= le) {
			// ok
		} else {
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");
}