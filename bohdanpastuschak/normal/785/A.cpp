#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <iomanip>
#include <functional>
#include <list>
#include <cmath>
#include <fstream>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mod 1000000007
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i>= (a); --i)

#define vec(a) vector<ll> a
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-6


int main()
{
	int n;
	cin >> n;

	string s;
	int ans = 0;
	FOR(i, 0, n)
	{
		cin >> s;
		switch (s[0])
		{
		case 'T': ans += 4; break;
		case 'C': ans += 6; break;
		case 'O': ans += 8; break;
		case 'D': ans += 12; break;
		case 'I': ans += 20; break;
		}
	}


	cout << ans;
	





	return 0;
}