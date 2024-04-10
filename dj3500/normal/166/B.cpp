#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
struct POINT {
    int x,y;
    POINT(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator ==(POINT& a) {return a.x==x && a.y==y;}
};
#define Det(a,b,c) (LL(b.x-a.x)*LL(c.y-a.y)-LL(b.y-a.y)*(c.x-a.x))
bool PointInsideConvexPol(vector<POINT>& l, POINT p){
	int a = 1, b = SIZE(l)-1, c;
	if (Det(l[0], l[a], l[b]) > 0) swap(a,b);
	if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) return false;
	while(abs(a-b) > 1) {
		c = (a+b)/2;
		if (Det(l[0], l[c], p) > 0) b = c; else a = c;
	}
	return Det(l[a], l[b], p) < 0;
}
int main() { 
   ios_base::sync_with_stdio(0);
	vector<POINT> pol;
	POINT p;
	int n;
	cin >> n;
	REP(x, n) {
		cin >> p.x >> p.y;
		pol.PB(p);
	}
	int m;
	cin >> m;
	bool ok = 1;
	REP(x, m) {
	   cin >> p.x >> p.y;
	   if (!PointInsideConvexPol(pol, p)) ok = 0;
	}
	cout << (ok ? "YES" : "NO");
	return 0;
}