#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	long double px, py;
};

long double a, b, c; Point G[2];

long double dist(Point a1, Point a2) {
	return sqrtl((a1.px - a2.px) * (a1.px - a2.px) + (a1.py - a2.py) * (a1.py - a2.py));
}

int main() {
	cin >> a >> b >> c >> G[0].px >> G[0].py >> G[1].px >> G[1].py;
	
	long double E1 = abs(G[0].px - G[1].px) + abs(G[0].py - G[1].py);
	
	Point V1 = { G[0].px, -(c + a * G[0].px) / b };
	Point W1 = { G[1].px, -(c + a * G[1].px) / b };
	Point V2 = { -(c + b * G[0].py) / a, G[0].py };
	Point W2 = { -(c + b * G[1].py) / a, G[1].py };

	long double E2 = dist(G[0], V1) + dist(V1, W1) + dist(W1, G[1]);
	long double E3 = dist(G[0], V1) + dist(V1, W2) + dist(W2, G[1]);
	long double E4 = dist(G[0], V2) + dist(V2, W1) + dist(W1, G[1]);
	long double E5 = dist(G[0], V2) + dist(V2, W2) + dist(W2, G[1]);

	printf("%.12Lf\n", min({ E1, E2, E3, E4, E5 }));
	return 0;
}