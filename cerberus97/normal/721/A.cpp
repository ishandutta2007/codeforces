#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	char s[105];
	cin >> s;

	s[n] = 'W';

	int ans = 0, curSize = (s[0] == 'B')?1:0;
	vector <int> sizes;

	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == 'W' and s[i-1] == 'B')
		{
			sizes.push_back(curSize);
			curSize = 0;
			++ans;
		}

		else if (s[i] == 'B')
		{
			++curSize;
		}
	}

	cout << ans << '\n';

	for (auto &i : sizes)
		cout << i << ' ';
}