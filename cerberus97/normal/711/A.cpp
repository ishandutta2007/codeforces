#include <iostream>

using namespace std;

char s[1005][10];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> s[i];

	bool ans = false;

	for (int i = 0; i < n; ++i)
	{
		if (s[i][0] == s[i][1] and s[i][0] == 'O')
		{
			s[i][0] = s[i][1] = '+';
			ans = true;
			break;
		}

		if (s[i][3] == s[i][4] and s[i][3] == 'O')
		{
			s[i][3] = s[i][4] = '+';
			ans = true;
			break;
		}
	}

	if (ans)
	{
		cout << "YES\n";

		for (int i = 0; i < n; ++i)
			cout << s[i] << '\n';
	}

	else
		cout << "NO";
}