#include <iostream>

using namespace std;

string get1(int n) {
	if (n == 0)
		return "zero";
	if (n == 1)
		return "one";
	if (n == 2)
		return "two";
	if (n == 3)
		return "three";
	if (n == 4)
		return "four";
	if (n == 5)
		return "five";
	if (n == 6)
		return "six";
	if (n == 7)
		return "seven";
	if (n == 8)
		return "eight";
	if (n == 9)
		return "nine";
}

string get3(int n) {
	if (n == 2)
		return "twenty";
	if (n == 3)
		return "thirty";
	if (n == 4)
		return "forty";
	if (n == 5)
		return "fifty";
	if (n == 6)
		return "sixty";
	if (n == 7)
		return "seventy";
	if (n == 8)
		return "eighty";
	if (n == 9)
		return "ninety";
}

string get2(int n) {
	if (n < 10)
		return get1(n);
	if (n < 20) {
		if (n == 10)
			return "ten";
		if (n == 11)
			return "eleven";
		if (n == 12)
			return "twelve";
		if (n == 13)
			return "thirteen";
		if (n == 14)
			return "fourteen";
		if (n == 15)
			return "fifteen";
		if (n == 16)
			return "sixteen";
		if (n == 17)
			return "seventeen";
		if (n == 18)
			return "eighteen";
		if (n == 19)
			return "nineteen";
	}
	if (n % 10 == 0)
		return get3(n / 10);
	return get3(n / 10) + "-" + get1(n % 10);

}

int main() {
	ios::sync_with_stdio(0);

	int s;
	cin >> s;

	cout << get2(s) << "\n";

	return 0;
}