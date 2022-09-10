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

	int m = 0, M = 0;
	FOR(i, 0, s.size())
		if (s[i] < 97) M++;
		else
			m++;

	if (M > m)
	{
		FOR(i, 0, s.size())
			if (s[i] >= 97) s[i] -= 32;
	}
	else
	{
		FOR(i, 0, s.size())
			if (s[i] < 97) s[i] += 32;
	}

	cout << s;

	return 0;
}