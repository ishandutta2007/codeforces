#include <iostream>
#include <cstring>

using namespace std;

char s[(int)1e5 + 5];

int main()
{
	int len;
	
	cin >> s;
	len = strlen(s);

	int l = 0, r;

	while (l < len and s[l] == 'a')
		++l;

	if (l == len)
	{
		s[len-1] = 'z';
		cout << s;
		return 0;
	}

	for (r = l; r < len; ++r)
	{
		if (s[r] == 'a')
		{
			--r;
			break;
		}
	}

	if (r == len)
		--r;

	for (int i = l; i <= r; ++i)
	{
		if (s[i] == 'a')
			s[i] = 'z';

		else
			--s[i];
	}

	cout << s;
}