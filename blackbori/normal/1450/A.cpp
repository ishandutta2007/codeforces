#include <bits/stdc++.h>

using namespace std;

void tc()
{
	string S; int n;
	cin >> n >> S;
	sort(S.begin(), S.end());
	cout << S << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	for(; t --; ){
		tc();
	}
}