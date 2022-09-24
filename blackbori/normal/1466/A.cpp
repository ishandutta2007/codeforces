#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int A[1010];

void tc()
{
	vector <int> V;
	int n, i, j;

	cin >> n;

	for(i = 0; i < n; i ++){
		cin >> A[i];
		for(j = 0; j < i; j ++){
			V.push_back(abs(A[i] - A[j]));
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	cout << V.size() << "\n";
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