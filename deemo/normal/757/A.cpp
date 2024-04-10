#include<bits/stdc++.h>

using namespace std;

int cnt[500], c2[500];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	for (char c:s)
		cnt[c]++;
	
	int ans = 1e9;
	string t = "Bulbasaur";
	for (char c:t)
		c2[c]++;
	for (int i = 0; i < 500; i++)
		if (c2[i])
			ans = min(ans, cnt[i]/ c2[i]);

	cout << ans << "\n";
	return 0;
}