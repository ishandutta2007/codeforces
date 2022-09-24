#include<iostream>
#include<set>
#include<algorithm>
#include<math.h>
#include<string>
#include<utility>
using namespace std;
int main()
{
	int n;
	int k;
	int a[500];
	cin >> n >> k;
	int res = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] + a[i] < k)
			{
				res+= k - a[i] - a[i - 1];
				a[i] = k - a[i - 1];
			}
		}
	cout << res << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}