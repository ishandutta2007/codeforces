#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> mas(n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		if (mas[i] % 2 == 0)
		{
			cout << mas[i] / 2 << "\n";
		}
		else
		{
			int x = mas[i] / 2;
			if (2 * x > mas[i])
				x--;
			if (cnt)
				x++;
			cout << x << "\n";
			cnt ^= 1;
		}		
	}
	return 0;
}