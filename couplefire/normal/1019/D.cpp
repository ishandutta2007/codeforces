#include <bits/stdc++.h>
 
#define For(i, j, k) for (int i = j; i <= k; i++)
 
using namespace std;
 
typedef long long LL;
 
const int N = 2010;
 
struct Point {
	int x, y;
 
	bool operator < (const Point& B) const {
		return y ^ B.y ? y > B.y : x > B.x;
	}
}P[N];
 
typedef Point Vector;
 
Vector operator - (Vector u, Vector v) { return (Vector){u.x - v.x, u.y - v.y}; }
Vector operator + (Vector u, Vector v) { return (Vector){u.x + v.x, u.y + v.y}; }
LL Cross(Vector u, Vector v) { return 1ll * u.x * v.y - 1ll * u.y * v.x; } 
 
struct Segment {
	int u, v;
	Vector p;
 
	bool operator < (const Segment& B) const {
		return Cross(p, B.p) > 0;
	}
}A[N * N];
 
int n, m;
int pos[N];
LL S;
 
int main() {
 
	cin >> n >> S;
	S <<= 1;
	For(i, 1, n) cin >> P[i].x >> P[i].y;
	sort(P + 1, P + n + 1);
 
	For(i, 1, n) pos[i] = i;
	For(i, 1, n) For(j, i + 1, n) A[++m] = (Segment){i, j, P[i] - P[j]};
	sort(A + 1, A + m + 1);
 
	For(i, 1, m) {
		int &a = pos[A[i].u], &b = pos[A[i].v];
		
		Vector p = P[b] - P[a];
		int l = 1, r = a - 1;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (abs(Cross(p, P[mid] - P[a])) >= S) l = mid;
			else r = mid - 1;
		}
		if (abs(Cross(p, P[l] - P[a])) == S) {
			printf("Yes\n%d %d\n%d %d\n%d %d\n", P[a].x, P[a].y, P[b].x, P[b].y, P[l].x, P[l].y);
			return 0;
		}
 
		swap(a, b);
		swap(P[a], P[b]);
	}
	puts("No");
 
	return 0;
}