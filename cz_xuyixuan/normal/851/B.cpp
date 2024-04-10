#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define EPS	1e-6
struct point {long long x, y; };
long long operator * (point a, point b) {return a.x * b.y - a.y * b.x; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
long long dist(point a, point b) {
	point c = a - b;
	return c.x * c.x + c.y * c.y;
}
bool equal(long long x, long long y) {
	return x == y;
}
int main() {
	ios::sync_with_stdio(false);
	point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	if (!equal((long long)0, (b - a) * (c - a)) && equal(dist(a, b), dist(b, c))) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}