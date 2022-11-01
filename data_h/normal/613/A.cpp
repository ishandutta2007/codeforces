#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Node {
	double x, y;
	Node(double x, double y) : x(x), y(y) {}
	Node() {}
};

double sqr(double x) {
	return x * x;
}

double dot(Node a, Node b, Node c) {
	return (b.x - a.x) * (c.x - a.x) + (c.y - a.y) * (b.y - c.y);
}

double det(Node a, Node b) {
	return fabs(a.x * b.y - b.x * a.y);
}

double dis(Node a, Node b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main() {
	int n;
	scanf("%d", &n);
	double px, py, max_dis = 0, min_dis = 1e100;
	scanf("%lf %lf", &px, &py);
	vector<Node> points;
	for (int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		points.push_back(Node(x - px, y - py));
		max_dis = max(max_dis, (x - px) * (x - px) + (y - py) * (y - py));
		min_dis = min(min_dis, (x - px) * (x - px) + (y - py) * (y - py));
	}
	points.push_back(points[0]);
	for (int i = 0; i < n; i++) {
		if (dot(points[i], points[i + 1], Node(0, 0)) < 0 || dot(points[i + 1], points[i], Node(0, 0)) < 0) {
			continue;
		}
		min_dis = min(min_dis, sqr(det(points[i], points[i + 1]) / dis(points[i], points[i + 1])));
	}
	printf("%.20f\n", (max_dis - min_dis) * acos(-1.0));
	return 0;
}