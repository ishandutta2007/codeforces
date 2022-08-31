/*
Hanit Banga
Problem: 
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

set <pii> points;

int main()
{
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	points.insert({x1+x2-x3, y1+y2-y3});
	points.insert({x2+x3-x1, y2+y3-y1});
	points.insert({x3+x1-x2, y3+y1-y2});

	cout << points.size() << endl;

	for (auto i : points)
		cout << i.first << ' ' << i.second << endl;

}