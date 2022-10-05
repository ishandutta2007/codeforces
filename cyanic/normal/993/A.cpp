#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

struct point {
	int x, y;
} a[4], b[4], p;
int A, B;

int cross(point p, point a, point b) {
	return (a.x-p.x)*(b.y-p.y) - (a.y-p.y)*(b.x-p.x);
}

bool check(int x, int y) {
	p.x = x; p.y = y;
	int AA = 0, BB = 0;
	rep (i, 0, 3) {
		AA += abs(cross(p, a[i], a[(i+1)%4]));
		BB += abs(cross(p, b[i], b[(i+1)%4]));
	}
	return abs(AA) == A && abs(BB) == B;
}

int main() {
	rep (i, 0, 3) scanf("%d%d", &a[i].x, &a[i].y);
	rep (i, 0, 3) scanf("%d%d", &b[i].x, &b[i].y);
	A = abs(cross(a[0], a[1], a[2]) + cross(a[0], a[2], a[3]));
	B = abs(cross(b[0], b[1], b[2]) + cross(b[0], b[2], b[3]));
	rep (x, -100, 100) rep (y, -100, 100)
		if (check(x, y)) 
			return puts("Yes"), 0;
	puts("No");
	
	return 0;
}