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
	vector<int> arr(n);
	vector<int> where(n);
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
		mas[i]--;
		where[mas[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[i]--;
		arr[i] = where[arr[i]];
	}
	int ans = 0, mn = n;
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > mn)
			ans++;
		mn = min(mn, arr[i]);
	}
	cout << ans << endl;
	return 0;
}