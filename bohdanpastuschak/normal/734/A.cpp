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
	int n; cin >> n;
	string s;
	cin >> s;

	int A = 0, D = 0;
	FOR(i, 0, s.size())
		if (s[i] == 'A')A++;
		else
			D++;

	if (A == D)
		cout << "Friendship";
	else
		if (A > D)
			cout << "Anton";
		else
			cout << "Danik";

	

	return 0;
}