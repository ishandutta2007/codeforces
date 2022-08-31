/*
Hanit Banga
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 5;

char s[N];

int main()
{
	cin >> s;

	int n = strlen(s);
	int dot = 0;
	while (dot < n and s[dot] != '.')
		++dot;

	if (dot == n)
		s[n++] = '.';
	
	int i = 0, j = n-1;
	while (s[i] == '0')
		++i;
	while (s[j] == '0')
		--j;

	int p = 0;
	if (i == dot)
	{
		while (dot < j)
		{
			swap(s[dot], s[dot+1]);
			++dot;
			--p;
			if (s[i] == '0')
				++i;
			else
				break;
		}
	}
	else
	{
		while (i < dot-1)
		{
			swap(s[dot], s[dot-1]);
			++p;
			--dot;
		}
	}

	while (s[j] == '.' or s[j] == '0')
		--j;

	if (i > j)
		cout << '0';

	while (i <= j)
		cout << s[i++];

	if (p)
		cout << 'E' << p;
}