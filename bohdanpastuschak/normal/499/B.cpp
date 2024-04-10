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
	int n, m; cin >> n >> m;

	string a, b;
	map<string, string> mapa;
	REPEAT(m)
	{
		cin >> a >> b;
		mapa[a] = b;
	}

	vector<string> s;
	REPEAT(n)
	{
		cin >> a;
		s.push_back(a);
	}

	FOR(i, 0, n)
	{
		if (mapa[s[i]].length() < s[i].length())
			cout << mapa[s[i]] << " ";
		else
			cout << s[i] << " ";
	}


	return 0;
}