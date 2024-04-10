#include <bits/stdc++.h>

using namespace std;


int main()
{
	string st;

	cin >> st;

	vector<int> dp(st.size());

	dp[0] = 1;

	for (int i = 1; i < st.size(); ++i)
	{
		if (st[i] == st[i - 1]) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
	}

	if (*max_element(dp.begin(), dp.end()) >= 7)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

    return 0;
}