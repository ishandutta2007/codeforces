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

	bool is[] = { 0,0,0,0,0 };
	FOR(i, 0, s.size())
	{
		if (s[i] == 'h')is[0] = 1;
		if (s[i] == 'e' && is[0] == 1) is[1] = 1;
		if (s[i] == 'l' && is[2] == 1) is[3] = 1;
		if (s[i] == 'l' && is[1] == 1) is[2] = 1;		
		if (s[i] == 'o' && is[3] == 1) is[4] = 1;
	}

	if (is[4])
		cout << "YES";
	else
		cout << "NO";


	return 0;
}