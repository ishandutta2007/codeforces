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

struct wyn { bool umie0:1, umie1:1, dobry:1; };
ostream& operator << (ostream& str, const wyn &w) {
	return str << "[" << w.umie0 << w.umie1 << w.dobry << "]";
}

int pos = 0;
char s[1000007];

wyn go() {
	if (s[pos] == '(') {
		pos++;
		wyn lewy = go();
		char oper = s[pos];
		pos++;
		wyn prawy = go();
		pos++; // )
		
		if (oper == '&') {
			return (wyn){
				lewy.umie0 || prawy.umie0 || (lewy.dobry && prawy.dobry),
				lewy.umie1 && prawy.umie1,
				(lewy.umie1 && prawy.dobry) || (lewy.dobry && prawy.umie1) || (lewy.dobry && prawy.dobry)
			};
		} else if (oper == '|') {
			return (wyn){
				lewy.umie0 && prawy.umie0,
				lewy.umie1 || prawy.umie1 || (lewy.dobry && prawy.dobry),
				(lewy.umie0 && prawy.dobry) || (lewy.dobry && prawy.umie0) || (lewy.dobry && prawy.dobry)
			};
		} else if (oper == '^') {
			return (wyn){
				(lewy.umie0 && prawy.umie0) || (lewy.umie1 && prawy.umie1) || (lewy.dobry && prawy.dobry),
				(lewy.umie0 && prawy.umie1) || (lewy.umie1 && prawy.umie0) || (lewy.dobry && prawy.dobry),
				(lewy.dobry && (prawy.umie0 || prawy.umie1)) || (prawy.dobry && (lewy.umie0 || lewy.umie1))
			};
		} else printf("WTF2%c", oper);
	} else {
		if (s[pos] == '0') {
			pos++;
			return (wyn){1,0,0};
		} else if (s[pos] == '1') {
			pos++;
			return (wyn){0,1,0};
		} else if (s[pos] == '?') {
			pos++;
			return (wyn){0,0,1};
		} else printf("WTF%c", s[pos]);
	}
}

int main () {
	wez(n)
	scanf("%s", s);
	wyn res = go();
	DBG(res)
	printf(res.dobry ? "YES\n" : "NO\n");
}