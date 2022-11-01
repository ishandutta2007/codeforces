#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string a, b;

int get_num(string s) {
	if (s == "monday") return 0;
	if (s == "tuesday") return 1;
	if (s == "wednesday") return 2;
	if (s == "thursday") return 3;
	if (s == "friday") return 4;
	if (s == "saturday") return 5;
	if (s == "sunday") return 6;
	return -1;
}

int aa, bb;

bool test(int n) {
	if (n % 7 == (bb - aa + 7) % 7) {
		return true;
	} else {
		return false;
	}
}

int main() {
	cin >> a >> b;
	aa = get_num(a);
	bb = get_num(b);
	if (test(28) || test(30) || test(31)) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}