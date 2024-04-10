#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#include <memory.h>
#include <map>
#include <cmath>

using namespace std;

bool solve() {
	long long a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if (a * c * e * b * d * f > 0 && a * c * e < b * d * f) return true;
	if (c == 0 && d > 0) return true;
	if (a == 0 && b > 0 && c > 0 && d > 0) return true;
	if (e == 0 && f > 0 && a * b * c * d > 0) return true;
		
	return false;
}

int main() {

	puts(solve() ? "Ron" : "Hermione");
	
	return 0;
}