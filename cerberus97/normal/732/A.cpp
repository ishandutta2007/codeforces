#include <iostream>

using namespace std;

int main()
{
	int k, r;
	cin >> k >> r;

	int st = k % 10, cur = st;

	for (int ans = 1; ans < 10; ++ans)
	{
		cur = (st * ans) % 10;
		
		if (cur == r or cur == 0)
		{
			cout << ans;
			break;
		}
	}
}