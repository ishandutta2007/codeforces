#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	int ans = n/2;
	int a = n/2, b = 0;
	if (n&1)
		a--, b++;
	cout << ans << "\n";
	while (a--)
		cout << "2 ";
	while (b--)
		cout << "3 ";
	cout << "\n";
	return 0;
}