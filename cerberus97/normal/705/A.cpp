#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string hateGen = "I hate that ", hateEnd = "I hate it", loveGen = "I love that ", loveEnd = "I love it";

	for (int i = 1; i <= n; ++i)
	{
		if (i == n)
		{
			if (i % 2)
				cout << hateEnd;

			else
				cout << loveEnd;
		}

		else
		{
			if (i % 2)
				cout << hateGen;

			else
				cout << loveGen;
		}
	}
}