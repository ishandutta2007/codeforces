#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> below20 {
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine",
		"ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};
	vector<string> above20 {
		"", "", "twenty", "thirty", "forty",
		"fifty", "sixty", "seventy", "eighty", "ninety"
	};
	
	int n; cin >> n;
	if (n < 20) return cout << below20[n], 0;
	cout << above20[n / 10];
	if (n % 10 > 0) cout << '-' << below20[n % 10];
	return 0;
}