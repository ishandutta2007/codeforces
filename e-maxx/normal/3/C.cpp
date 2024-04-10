#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


string a[3];

bool win (char c) {
	for (int i=0; i<3; ++i) {
		if (a[i][0] == c && a[i][1] == c && a[i][2] == c)
			return true;
		if (a[0][i] == c && a[1][i] == c && a[2][i] == c)
			return true;
	}
	if (a[0][0] == c && a[1][1] == c && a[2][2] == c)
		return true;
	if (a[0][2] == c && a[1][1] == c && a[2][0] == c)
		return true;
	return false;
}

void no() {
	puts ("illegal");
	exit(0);
}

int main() {

	for (int i=0; i<3; ++i)
		cin >> a[i];

	int c1 = 0,  c2 = 0;
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			if (a[i][j] == 'X')
				++c1;
			else if (a[i][j] == '0')
				++c2;
	if (! (c1 == c2 || c1 == c2 + 1))
		no();

	if (win ('X') && c1 == c2)
		no();
	if (win ('0') && c1 > c2)
		no();
	if (win ('X') && win ('0'))
		no();

	if (win ('X'))
		puts ("the first player won");
	else if (win ('0'))
		puts ("the second player won");
	else if (c1 + c2 == 9)
		puts ("draw");
	else if (c1 == c2)
		puts ("first");
	else
		puts ("second");

}