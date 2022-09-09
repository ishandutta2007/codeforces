#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double ta = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	double tb = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (ta < tb) swap(ta, tb);
	printf("%.10lf\n%.10lf\n", ta, tb);
	return 0;
}