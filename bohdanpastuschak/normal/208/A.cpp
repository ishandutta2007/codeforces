#include <iostream>
#include <vector>
#include <string>
#include <set>
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

	string r;
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
		{
			r += ' ';
			i += 3;
		}
		else
		{
			r += s[i];
			i++;
		}
	}
	

	cout << r;
	return 0;
}