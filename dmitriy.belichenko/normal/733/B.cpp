#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	long long l[100005];
	long long r[100005];
	int ans = -1;
	long long suml = 0, sumr = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i] ;
		suml += l[i];
		cin >> r[i];
		sumr += r[i];
	}
	long long res = abs(suml - sumr);
	for (int i = 0; i < n; i++)
	{
		if (abs(suml - sumr - l[i] + r[i] - l[i] + r[i]) > res)
		{
			ans = i;
			res = abs(suml - sumr - l[i] + r[i] - l[i] + r[i]);
		}

	}
	cout << ans + 1;
	return 0;
}