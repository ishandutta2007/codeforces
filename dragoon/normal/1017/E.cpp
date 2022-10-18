#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

LL INF = 1000000009;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

struct Point {
	LL x, y;

	Point(LL a, LL b) { x = a; y = b; }
	Point() {}

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
LL cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (LL)(B.y - O.y) - (A.y - O.y) * (LL)(B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0, i, t;
	vector<Point> H(2 * n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (i = 0; i < n; i++) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
			k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
			k--;
		H[k++] = P[i];
	}

	H.resize(k);
	H.pop_back();
	return H;
}

vector<vector<LL>> GetPoly(int n) {
	vector<Point> V;
	for (int i = 0; i < n; i++) {
		LL xx, yy;
		scanf("%lld %lld", &xx, &yy);
		V.push_back({ xx, yy });
	}
	V = convex_hull(V);

	vector<vector<LL>> Z;
	for (int i = 0; i < SZ(V); i++) {
		int j = (i + 1) % SZ(V);
		LL dist1 = S(V[i].x - V[j].x) + S(V[i].y - V[j].y);
		Z.push_back({ dist1 });
		int k = (j + 1) % SZ(V);
		LL dist2 = S(V[k].x - V[j].x) + S(V[k].y - V[j].y);
		LL dist3 = S(V[i].x - V[k].x) + S(V[i].y - V[k].y);
		LL lob = dist1 + dist2 - dist3;
		Z.push_back({ lob, lob, dist1, dist2 });
	}
	return Z;
}

LL gcd(LL a, LL b) {
	if (!a) return b;
	if (!b) return a;
	return gcd(b, a % b);
}

int EQ(vector<LL>& A, vector<LL>& B) {
	if (SZ(A) != SZ(B)) return 0;
	if (SZ(A) == 1) {
		return A[0] == B[0];
	}
	vector<LL> lhs, rhs;
	lhs.push_back(A[0]);
	lhs.push_back(A[1]);
	rhs.push_back(B[0]);
	rhs.push_back(B[1]);
	rhs.push_back(A[2]);
	rhs.push_back(A[3]);
	lhs.push_back(B[2]);
	lhs.push_back(B[3]);

	LL lsign = 1, rsign = 1;
	for (int i = 0; i < 4; i++) {
		if (lhs[i] < 0) {
			lsign *= -1;
			lhs[i] *= -1;
		}
		else if (lhs[i] == 0) lsign = 0;

		if (rhs[i] < 0) {
			rsign *= -1;
			rhs[i] *= -1;
		}
		else if (rhs[i] == 0) rsign = 0;
	}
	if (!lsign || !rsign) {
		return lsign == rsign;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			LL g = gcd(lhs[i], rhs[j]);
			lhs[i] /= g;
			rhs[i] /= g;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (lhs[i] > 1 || rhs[i] > 1) return 0;
	}
	return 1;
}
int f[200005];
void failure(vector<vector<LL>>& S)
{
	int i, now;

	now = f[0] = -1;
	for (int i = 1; i < S.size(); i++) {
		while (now != -1 && !EQ(S[now + 1], S[i])) {
			now = f[now];
		}
		if (EQ(S[now + 1], S[i])) {
			now = f[i] = now + 1;
		}
		else {
			now = f[i] = -1;
		}
	}
}

int wordCount(vector<vector<LL>>& P, vector<vector<LL>>& T)
{
	int now = -1;
	for (int i = 0; i < SZ(T); i++) {
		while (now != -1 && !EQ(P[now + 1], T[i]))
			now = f[now];

		if (EQ(P[now + 1], T[i]))
		{
			now = now + 1;
			if (now + 1 == SZ(P))
				return 1;
		}
		else
			now = -1;
	}
	return 0;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		vector<vector<LL>> V1 = GetPoly(n);
		vector<vector<LL>> V2 = GetPoly(m);

		int sz = V1.size();
		for (int i = 0; i < sz; i++) V1.push_back(V1[i]);

		failure(V2);
		int ret = wordCount(V2, V1);
		printf("%s\n", ret ? "YES" : "NO");



	}
	return 0;
}