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
	string a, b, c; cin >> a >> b >> c;

	if (a.size() + b.size() != c.size())
	{
		cout << "NO";
		return 0;
	}

	map<char, int> m;
	FOR(i, 0, a.size())
		m[a[i]]++;
	FOR(i, 0, b.size())
		m[b[i]]++;

	map<char, int> r;
	FOR(i, 0, c.size())
		r[c[i]]++;

	for (auto v : m)
	{
		if (r[v.first] != v.second)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";	
	return 0;
}