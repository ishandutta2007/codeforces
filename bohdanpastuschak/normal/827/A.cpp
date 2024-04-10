#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define ll long long
#define mod 1000000007
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<ld,ld>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>
#define vld vector<ld>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 100001
clock_t startTime;

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int n; cin >> n;
	
	vector<string> t(n);
	vi k(n);
	vector<vi> x(n);
	int length = 0;
	FOR(i, 0, n)
	{
		cin >> t[i];
		cin >> k[i];
		x[i].assign(k[i], 0);
		FOR(j, 0, k[i])
			cin >> x[i][j], x[i][j]--;
		length = max(length, (int)(t[i].size() + x[i][k[i] - 1] - 1));
	}

	vpii all_x;
	FOR(i, 0, n)
		for (auto xx : x[i])
			all_x.push_back(MP(xx, i));

	sort(ALL(all_x));
	string ans;
	
	FOR(i, 0, all_x.size())
	{
		while (ans.size() < all_x[i].X)
			ans += 'a';
		if (ans.size() == all_x[i].X)
			ans += t[all_x[i].Y];
		else
		{
			int ind = ans.size() - all_x[i].X;
			if (ind < t[all_x[i].Y].size())
			{
				FOR(j, ind, t[all_x[i].Y].size())
					ans += t[all_x[i].Y][j];
			}
		}
	}

	cout << ans;
	//cin >> n;
	return 0;
}
//don't forget about MAXN, mod and infinity