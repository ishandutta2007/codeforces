#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	cin >> n;

	string st;


	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> st;
		if (st == "++X" || st == "X++") ++ answer;
		else --answer;
	}

	cout << answer;

    return 0;
}