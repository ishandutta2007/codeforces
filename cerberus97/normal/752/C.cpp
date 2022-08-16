/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)
#define x first
#define y second

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int dist (pii a, pii b);

int main()
{
	int n;
	string s;
	cin >> n >> s;

	int points = 1;
	pii p = {0, 0}, cur = {0, 0};

	for (auto i : s)
	{
		pii temp = cur;

		if (i == 'R')
			++temp.x;

		else if (i == 'L')
			--temp.x;

		else if (i == 'U')
			++temp.y;

		else
			--temp.y;

		if (dist(p, temp) < dist(p, cur))
		{
			++points;
			p = cur;
		}

		cur = temp;
	}

	cout << points;
}

int dist (pii a, pii b)
{
	return abs(a.x-b.x) + abs(a.y-b.y);
}