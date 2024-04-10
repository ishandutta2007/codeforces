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

char s[100007];
int prefsum[100007], endsat[100007];

int main () {
	/*REP(sfsdfs,0,1000) {
	int n = 7;
	const char *u = "()[]";
	FOR(k,n) s[k] = u[rand() % 4];
	s[n] = 0;
	
	int bes = 0;
	REP(a,0,n-1) REP(b,a,n-1) {
		int open = 0;
		REP(c,a,b) open += s[c] == '[';
		vi stack;
		bool fail = 0;
		REP(i,a,b) {
			if (s[i] == '(') stack.pb(0);
			else if (s[i] == '[') stack.pb(1);
			else if (s[i] == ')') {
				if (!stack.empty() && stack.back() == 0) stack.pop_back();
				else fail = 1;
			} else if (s[i] == ']') {
				if (!stack.empty() && stack.back() == 1) stack.pop_back();
				else fail = 1;
			}
		}
		if (!fail && stack.empty()) REMAX(bes, open);
	}*/


	scanf("%s", s);
	vector<pii> stack;
	int n = strlen(s);

	FOR(i,n) endsat[i] = -1;

	FOR(i,n) {
		if (s[i] == '(') {
			stack.pb(mp(0,i));
		} else if (s[i] == '[') {
			stack.pb(mp(1,i));
		} else if (s[i] == ')') {
			if (!stack.empty() && stack.back().fi == 0) {
				endsat[stack.back().se] = i;
				stack.pop_back();
			} else {
				stack.clear();
			}
		} else if (s[i] == ']') {
			if (!stack.empty() && stack.back().fi == 1) {
				endsat[stack.back().se] = i;
				stack.pop_back();
			} else {
				stack.clear();
			}
		}	
	}
	
	REPD(i,n-1,0) if (endsat[i] != -1) {
		int k = endsat[i];
		k++;
		if (k < n) if (endsat[k] != -1) endsat[i] = endsat[k];
	}
	
	prefsum[0] = s[0] == '[';
	REP(i,1,n-1) prefsum[i] = prefsum[i-1] + (s[i] == '[');
	prefsum[n] = 0;
	int best = -1, bestl, bestr;
	FOR(i,n) if (endsat[i] != -1) {
		int a = i - 1;
		if (a == -1) a = n;
		int score = prefsum[endsat[i]] - prefsum[a];
		if (score > best) {
			best = score;
			bestl = i;
			bestr = endsat[i];
		}
	}
	if (best == -1) {
		best = 0;
		pisz(0);
	} else {
		pisz(best);
		REP(i,bestl,bestr) printf("%c", s[i]);
	}
	
	/*if (bes != best) {
		DBG("FUCK");
		DBG(bes)DBG(best)
		DBG(s)
		return 1;
	}*/
}