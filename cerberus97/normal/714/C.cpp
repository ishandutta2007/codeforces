#include <iostream>
#include <cstring>

using namespace std;

const int P = (1<<19) + 5;

typedef long long ll;

int pattern[P] = {0};

void addZeroesToLeft(char s[20])
{
	int len = strlen(s);
	char x[20];

	if (len < 19)
	{
		for (int i = 19-len, j = 0; i < 19; ++i, ++j)
			x[i] = s[j];

		for (int i = 0; i < 19-len; ++i)
			x[i] = '0';

		x[19] = 0;
	}

	strcpy(s, x);
}

int PatternToCode(char s[20])
{
	int ans = 0;

	for (int i = 0, j = 1; i < 19; ++i, j *= 2)
	{
		if (s[i] == '1')
			ans += j;
	}

	return ans;
}

int NumToCode(ll x)
{
	int ans = 0, j = 1<<18;

	while (x)
	{
		if (x % 2 == 1)
			ans += j;

		x /= 10;
		j /= 2;
	}

	return ans;
}

int ans(char s[20])
{
	addZeroesToLeft(s);
	return pattern[PatternToCode(s)];
}

void add(ll x)
{
	pattern[NumToCode(x)]++;
}

void rem(ll x)
{
	pattern[NumToCode(x)]--;
}

int main()
{
	int t;
	cin >> t;

	char qt, s[20];
	ll x;

	while (t--)
	{
		cin >> qt;

		if (qt == '+')
		{
			cin >> x;
			add(x);
		}

		else if (qt == '-')
		{
			cin >> x;
			rem(x);
		}

		else
		{
			cin >> s;
			cout << ans(s) << '\n';
		}
	}
}