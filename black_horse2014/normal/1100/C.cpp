#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; double r; cin >> n >> r;
	printf("%.10lf\n", r / (1 / sin(acos(-1) / n) - 1));
}