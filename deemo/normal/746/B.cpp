#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;	cin >> n;
	string s;	cin >> s;
	string ans;
	int cur = 0;
	if (n&1)	cur++;
	for (int i = cur; i < n; i += 2)
		ans += s[i];
	reverse(ans.begin(), ans.end());
	if (n&1)	ans += s[0];
	cur = 1;
	if (n&1)	cur++;
	for (int i = cur; i < n; i += 2)
		ans += s[i];
	cout << ans << "\n";
	return 0;
}