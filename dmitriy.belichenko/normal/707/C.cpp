#include <bits/stdc++.h>

using namespace std;

pair <long long, long long> ans(long long x)
{
  if (x % 2 == 1)
     return {(x * x) /  2 + 1, (x * x) / 2};
  pair <long long, long long> temp = ans(x / 2);
  return {temp.first * 2, temp.second * 2};
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long x;
	cin >> x;
	if (x < 3)
	{
		cout << -1 << endl;
		return 0;
	}
	bool hm = true;
	long long tmp = x;
	while (tmp % 2 == 0)
		tmp /= 2;
	hm = (tmp == 1);
	if (hm)
	{
		cout << x / 4 * 3 << " " << x / 4 * 5 << endl;
		return 0;
	}
  auto temp = ans(x);

		cout << temp.first << " " << temp.second << endl;

	return 0;
}