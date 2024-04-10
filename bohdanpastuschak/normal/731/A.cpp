#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
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

	int ans = 0;
	char b = 'a';
	FOR(i, 0, s.size())
	{
		ans += min(min(abs(b - s[i]), abs(s[i] + 26 - b)), abs(b + 26 - s[i]));
		b = s[i];
	}

	cout << ans;
	return 0;
}