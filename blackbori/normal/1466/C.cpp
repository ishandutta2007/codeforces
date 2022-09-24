#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void tc()
{
	string S; int L[33];
	int i, c, n, s;
	cin >> S;

	n = S.size(); s = 0;
	for(i = 0; i < 26; i ++) L[i] = -1e9;
	for(i = 0; i < n; i ++){
		c = S[i] - 'a';
		if(i - L[c] <= 2) s ++;
		else L[c] = i;
	}	
	cout << s << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
//*
	cin >> t;
/*/
	t = 1;
//*/
	for(; t --; ) tc();

	return 0;
}