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
#define vi vector<ll>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()

int mf(string a, string b)
{
	return a.length() < b.length();
}

int main()
{
	int n, k; cin >> n >> k;
	int ans1 = 0, ans2 = 0;

	vector<string> a(n);
	FOR(i, 0, n)
		cin >> a[i];

	string pass; cin >> pass;
	sort(ALL(a), mf);

	FOR(i, 0, n)
	{
		if (a[i].size() == pass.size() && ans1 == 0)ans1 = i + 1;
		if (a[i].size() == pass.size()) ans2 = i + 1;
	}

	ans1 = ans1 + 5 * ((ans1 - 1) / k);
	ans2 = ans2 + 5 * ((ans2 - 1) / k);
	cout << ans1 << " " << ans2;
	return 0;
}