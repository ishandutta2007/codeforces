#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

const int MAX_INT = (1 << 31)-1;
const ll MAX_LL = (1LL << 63)-1;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date
{
	int y, m, d;
	date():
		y(1900), m(1), d(1)
		{
		}
};

istream& operator>>(istream& in, date& d)
{
	in >> d.y;
	in.ignore();
	in >> d.m;
	in.ignore();
	in >> d.d;
	return in;
}

ostream& operator<<(ostream& out, const date& d)
{
	out << d.y << ":" << d.m << ":" << d.d;
	return out;
}

bool operator>(const date& d1, const date& d2)
{
	return (d1.y > d2.y || d1.y == d2.y && d1.m > d2.m ||
		d1.y == d2.y && d1.m == d2.m && d1.d > d2.d);
}

bool vis(int year)
{
	return (year%4==0 && year%100!=0 || year%400==0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	date d1, d2;
	cin >> d1 >> d2;
	if (d1 > d2)
		swap(d1, d2);
	//cout << d1 << " " << d2 << endl;
	int ans = 0;
	if (d1.y != d2.y)
	{
		for (int i = d1.y+1; i < d2.y; ++i)
		{
			ans += 365;
			if (vis(i))
				++ans;
		}
		if (vis(d1.y)) ++month[2];
		for (int i = d1.m+1; i < 13; ++i)
			ans += month[i];	
		ans += month[d1.m]-d1.d;
		if (vis(d1.y)) --month[2];
		if (vis(d2.y)) ++month[2];
		for (int i = 1; i < d2.m; ++i)
			ans += month[i];
		ans += d2.d;
		if (vis(d2.y)) --month[2];
	}else
	{
		if (vis(d1.y)) ++month[2];
		if (d1.m == d2.m)
			ans = d2.d-d1.d;
		else
		{
			for (int i = d1.m+1; i < d2.m; ++i)
				ans += month[i];
			ans += month[d1.m]-d1.d;
			ans += d2.d;
		}
		if (vis(d1.y)) --month[2];
	}
	cout << ans << endl;
	return 0;
}