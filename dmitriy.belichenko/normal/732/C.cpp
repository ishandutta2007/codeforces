#include<iostream>
#include<set>
#include<algorithm>
#include<math.h>
#include<string>
#include<utility>
using namespace std;
int main()
{
	int u, p;
	long long b, d, s;
	cin >> b >> d >> s;
	long long a[3];
	a[0] = b;
	a[1] = d;
	a[2] = s;
	int n = 3;
	sort(a, a + n);
	long long res = 0;
	if (a[1] + 1 < a[2])
	{
		res = res + a[2] - a[1] - 1;
	}
	if (a[0] + 1 < a[2])
	{
		res = res + a[2] - a[0] - 1;
	}
	cout << res;

	return 0;
}