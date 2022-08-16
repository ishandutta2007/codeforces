#include <iostream>

using namespace std;

int main()
{
	char x;
	int i, j;

	cin >> x >> i;
	j = (x - 'a') + 1;

	int ans = -1;

	for (int x = i-1; x <=i+1; ++x)
		for (int y = j-1; y <= j+1; ++y)
			if (x > 0 and x < 9 and y > 0 and y < 9)
				++ans;

	cout << ans;
}