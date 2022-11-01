#pragma comment(linker, "/STACK:16000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i,n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define REPD(i,n) for (int i = (n)-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = (a); _##i = (b); i <= _##i; ++i)
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define pb push_back
#define MP make_pair
const double pi = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef long long LL;

LL gcd(LL a, LL b) {
	if (a<0) a=-a;
	if (b<0) b=-b;
	if (a<b) swap(a,b);
	while (b) {
		LL t = b;
		b = a%b;
		a = t;
	}
	return a;
}

template <typename T>
struct Point {
	T x,y;
	Point(T xx = 0, T yy = 0) : x(xx), y(yy) {}
};

template <typename T> Point<T> operator+(const Point<T>& a, const Point<T>& b) { return Point<T>(a.X+b.X,a.Y+b.Y); }
template <typename T> Point<T> operator-(const Point<T>& a, const Point<T>& b) { return Point<T>(a.X-b.X,a.Y-b.Y); }

#define MOD 1000000007

int main()
{
	//freopen(".in","r",stdin);

	LL a[3];
	REP(i,3) cin >> a[i];
	sort(a,a+3);
	LL res = a[0]+a[1]+a[2]-1;
	do {
		if ((a[0]+a[1]) % 2 == 0) {
			res = min(res,max(a[0],a[1]));
		}
	} while (next_permutation(a,a+3));
	cout << res << endl;
	return 0;
}