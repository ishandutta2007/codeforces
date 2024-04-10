#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, m;

	cin >> n;

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		int s = 0;
		int x;
		for (int j = 0; j < 3; ++j) cin >> x, s += x;
		if (s >= 2) ++answer;

		//cout << s << endl;
	}

	cout << answer;

    return 0;
}