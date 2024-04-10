#include <iostream>

using namespace std;

#define loop(i, start, stop) for (i = start; i < stop; ++i)

int main (void) {
	ios_base::sync_with_stdio(0);

	int i, k, m;
	int n;

	cin >> n >> ws;

	int totalPart = 0;
	int lastChar = '2';
	int longestPart = 0;
	int currentPart = 0;
	int numberOfGreaterThan1Parts = 0;

	char ch;
	loop(i, 0, n) {
		cin >> ch;

		if (ch != lastChar) {
			if (currentPart > longestPart) longestPart = currentPart;
			if (currentPart >= 2) ++numberOfGreaterThan1Parts;
			++totalPart;
			lastChar = ch;
			currentPart = 1;
		} else {
			++currentPart;
		}
	}

	if (currentPart > longestPart) longestPart = currentPart;
	if (currentPart >= 2) ++ numberOfGreaterThan1Parts;

	int result = totalPart;

	if (longestPart >= 3) result += 2;
	else if (longestPart == 2 && numberOfGreaterThan1Parts >= 2) result += 2;
	else if (longestPart == 2) ++result;


	cout << result;

	return 0;
}