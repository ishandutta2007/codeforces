#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

#define ll long long
#define mod 1000000007
#define infinity (ll)1e18+1
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define MP make_pair

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)

int main()
{
	string s;
	cin >> s;

	int num1 = 0, num2 = 0;

	FOR(i, 0, s.size() - 1)
	{
		if (s[i] == 'A' && s[i + 1] == 'B') num1++;
		if (s[i] == 'B' && s[i + 1] == 'A') num2++;
	}

	if (num1 > 1 && num2 > 1)
	{
		cout << "YES";
		return 0;
	}
	if (num1 < 1 || num2 < 1)
	{
		cout << "NO";
		return 0;
	}
	if (num1 > 2 || num2 > 2)
	{
		cout << "YES";
		return 0;
	}

	if (num1 * num2 == 2)
	{
		FOR(i, 0, s.size() - 3)
		{
			if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A' && s[i+3] == 'B')
			{
				cout << "NO";
				return 0;
			}
			if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B' && s[i+3] == 'A')
			{
				cout << "NO";
				return 0;
			}
		}
		cout << "YES"; return 0;
	}

	FOR(i, 0, s.size() - 2)
	{
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A')
		{
			cout << "NO";
			return 0;
		}
		if (s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B')
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}