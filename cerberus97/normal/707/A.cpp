#include <iostream>

using namespace std;

int main()
{
	int n, m;
	char c;
	bool f = true;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> c;

			if (c != 'B' and c != 'W' and c != 'G')
				f = false;
		}
	}

	if (f)
		cout << "#Black&White";

	else
		cout << "#Color";
}