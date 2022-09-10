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
#define MAXN 4000001
clock_t startTime;

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	
	string s;
	cin >> s;
	int n = s.size();
	FOR(i,0,n)
		if (s[i] == '8' || s[i] == '0')
		{
			cout << "YES" << endl << s[i];
			return 0;
		}

	vi dil;
	FOR(i, 1, 125)
		dil.push_back(8 * i);

	for (auto d : dil)
	{
		if (d == 64)
			cout << "";
		int c1 = d / 100, c2 = (d/10)%10, c3 = d % 10;
		bool m1 = false, m2 = false, m3 = false;
		if (c1 == 0)
		{
			m1 = true;
			if (c2 == 0)
				m2 = true;
		}
		FOR(i, 0, n)
		{
			if ((s[i] - '0' == c1 && !m1))
			{
				m1 = true;
				if (c1 > 0)
					continue;
			}
			
			if ((s[i] - '0' == c2 && m1 && !m2))
			{
				m2 = true;
				if (c1 > 0 || c2 > 0)
					continue;
			}
			
			if (s[i] - '0' == c3 && m2)
				m3 = true;
		}

		if (m3)
		{
			cout << "YES" << endl;
			if (c1 > 0)
				cout << c1 << c2 << c3;
			else
				if (c2 > 0)
					cout << c2 << c3;
				else
					cout << c3;
			return 0;
		}
	}

	cout << "NO";

	return 0;
}
//don't forget about MAXN, mod and infinity