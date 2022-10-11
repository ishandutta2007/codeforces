#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define ld long double
#define SIZE 100228
#define eps 1e-6

int n;
ld mn[SIZE], mx[SIZE], a[SIZE], b[SIZE];

ld solve(ld a, ld b, ld c)
{
	ld d = b * b - 4 * a * c;
	if (d < 0)
	{
		if (d < -eps)
			return 0;
		else
			d = 0;
	}
	return (-b + sqrt(d)) / (2 * a);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mx[i];
	for (int i = 0; i < n; i++)
		cin >> mn[i];
	ld s = mx[0] + mn[0];
	b[0] = solve(-1, s, -mx[0]);
	a[0] = s - b[0];
	ld sa = a[0], sb = b[0];
	for (int i = 1; i < n; i++)
	{
		ld s = mx[i] + mn[i];
		b[i] = solve(-1, sa - sb + s, sb * s - mx[i]);
		a[i] = s - b[i];
		sa += a[i];
		sb += b[i];
	}
	for (int i = 0; i < n; i++)
		cout << a[i]<< ' ';
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
	cout << endl;
	return 0;
}