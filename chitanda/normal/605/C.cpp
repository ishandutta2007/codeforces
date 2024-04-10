#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define eps (1e-8)

const int maxn = 100100;
int n, P, Q, x0, y0, top;
struct node{
	int a, b;
	bool operator < (const node &q)const{
		return a < q.a || (a == q.a && b > q.b);
	}
}p[maxn], q[maxn], pq;
node operator - (const node a, const node b){
	pq.a = a.a - b.a, pq.b = a.b - b.b;
	return pq;
}

ll Cross(node x, node y){
	return (ll)x.a * y.b - (ll)x.b * y.a;
}

ll cross(node x, node y, node z){
	node xx = y - x, yy = z - x;
	return Cross(xx, yy);
}

int main(){
	scanf("%d%d%d", &n, &P, &Q);
	int x0 = 0, y0 = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &p[i].a, &p[i].b);
		x0 = max(x0, p[i].a);
		y0 = max(y0, p[i].b);
	}

	sort(p + 1, p + n + 1);
	q[top = 1].a = 0, q[1].b = y0;
	p[++n].a = x0, p[n].b = 0;
	for(int i = 1; i <= n; i++){
		while(top > 1 && cross(q[top], q[top - 1], p[i]) <= 0) top--;
		q[++top] = p[i];
	}

	double ans = 0;
	node x; x.a = P, x.b = Q;
	for(int i = 1; i < top; i++){
		if (Cross(q[i], x) <= 0 && Cross(q[i + 1], x) >= 0){
			double l = 0, r = 1000000, x1, x2, y1, y2;
			while(r - l > eps){
				double mid = (l + r) / 2;
				x1 = P - q[i].a * mid, y1 = Q - q[i].b * mid;
				x2 = q[i + 1].a - q[i].a, y2 = q[i + 1].b - q[i].b;
				if (x1 * y2 - x2 * y1 <= 0) l = mid;
				else r = mid;
			}
			ans = l;
		}
	}
	printf("%.8lf\n", ans);
  return 0;
}