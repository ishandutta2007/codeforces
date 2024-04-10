#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
	int n;
	cin >> n;
	int ans = (n + n + 1) * (n + 1) 
		+ n * (n + 1) / 2 + n * (n - 1) / 2;
	cout << ans << endl;
}