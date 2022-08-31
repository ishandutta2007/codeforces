#include <iostream>

using namespace std;

char temp[5];

void conv(int num, char *s)
{
	s[1] = num % 10 + '0';
	num /= 10;
	s[0] = num % 10 + '0';
}

int cost(char *c1, char *c2)
{
	int ans = 0;

	if (c1[0] != c2[0])
		++ans;

	if (c1[1] != c2[1])
		++ans;

	return ans;
}

int main()
{
	int type;
	cin >> type;

	char cl[10];
	cin >> cl;

	if (cl[3] > '5')
		cl[3] = '5';

	int st = 0, en = 23;

	if (type == 12)
	{
		st = 1;
		en = 12;
	}

	int ans = 100, mn;

	for (int i = st; i <= en; ++i)
	{
		conv(i, temp);

		if (cost(temp, cl) < ans)
		{
			ans = cost(temp, cl);
			mn = i;
		}
	}

	conv(mn, cl);
	cout << cl;
}