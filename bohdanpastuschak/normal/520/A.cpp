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
	int n; cin >> n;
	string s;
	cin >> s;

	set<char> u;
	FOR(i, 0, s.size())
	{
		if (s[i] < 97)
			u.insert(s[i]);
		else
			u.insert(s[i] - 32);
	}

	if (u.size() != 26)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}